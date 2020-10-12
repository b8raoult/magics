/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include <fstream>
#include "magics.h"

#include "MagYaml.h"

#include "MagException.h"
#include "YAMLParser.h"
#include "py_calls.h"

using namespace magics;

typedef const char* (*action_proc)();

static std::map<std::string, action_proc> actions = {
    {"mboxplot", py_boxplot},
    {"mcoast", py_coast},
    {"mcont", py_cont},
    {"mepsbar", py_epsbar},
    {"mepscloud", py_epscloud},
    {"mepsgraph", py_epsgraph},
    {"mepsinput", py_epsinput},
    {"mepslight", py_epslight},
    {"mepsplumes", py_epsplumes},
    {"mepsshading", py_epsshading},
    {"mepswave", py_epswave},
    {"mepswind", py_epswind},
    {"mgeojson", py_geojson},
    {"mgrib", py_grib},
    {"mimage", py_image},
    {"mimport", py_import},
    {"minput", py_input},
    {"mlegend", py_legend},
    {"mline", py_line},
    {"mmap", nullptr},
    {"mmapgen", py_mapgen},
    {"mmetbufr", py_metbufr},
    {"mmetgraph", py_metgraph},
    {"mnetcdf", py_netcdf},
    {"mobs", py_obs},
    {"modb", py_odb},
    {"moverlay", py_overlay},
    {"mraw", py_raw},
    {"msymb", py_symb},
    {"mtable", py_table},
    {"mtaylor", py_taylor},
    {"mtephi", py_tephi},
    {"mtext", py_text},
    {"mtile", py_tile},
    {"mwind", py_wind},
    {"mwrepjson", py_wrepjson},
    {"output", nullptr},
    // {"page", py_new_page},


};

// TODO: NO globals!!!

static std::map<std::string, std::set<std::string> > reset;

static void check(const string& name, const char* msg) {
    if (msg) {
        std::ostringstream oss;
        oss << "Exception: " << name << ": " << msg;
        throw MagicsException(oss.str());
    }
}

static void execute(const std::string& action, const Value& p) {
    auto k = actions.find(action);
    if (k == actions.end()) {
        throw MagicsException("Unknown action: " + action);
    }

    // Reset previous settings
    for(auto r: reset[action]) {
        py_reset(r.c_str());
    }
    reset[action].clear();

    action_proc proc = (*k).second;


    ValueMap param = p;
    for (auto j = param.begin(); j != param.end(); ++j) {
        std::string name = (*j).first;
        Value value      = (*j).second;

        reset[action].insert(name);

        if (value.isBool()) {
            check(name, py_setc(name.c_str(), bool(value) ? "on" : "off"));
            continue;
        }

        if (value.isString()) {
            std::string s = value;
            check(name, py_setc(name.c_str(), s.c_str()));
            continue;
        }

        if (value.isNumber() || value.isDouble()) {
            double d = value;
            if (long(d) == d) {
                check(name, py_seti(name.c_str(), long(d)));
            }
            else {
                check(name, py_setr(name.c_str(), d));
            }
            continue;
        }

        if (value.isList()) {
            ValueList l = value;
            size_t s    = 0;
            size_t i    = 0;
            size_t d    = 0;
            for (auto e : l) {
                if (e.isString()) {
                    s++;
                    continue;
                }
                if (value.isNumber() || value.isDouble()) {
                    double v = value;
                    if (long(v) == v) {
                        i++;
                    }
                    else {
                        d++;
                    }
                    continue;
                }
                std::ostringstream oss;
                oss << "Value type not supported in list: " << name << " = " << value;
                throw MagicsException(oss.str());
            }
            if (s) {
                std::vector<std::string> tmp;
                std::vector<const char*> v;
                for (auto e : l) {
                    tmp.push_back(e);
                    v.push_back(tmp.back().c_str());
                }
                check(name, py_set1c(name.c_str(), v.data(), v.size()));
            }

            if (d) {
                std::vector<double> v;
                for (auto e : l) {
                    v.push_back(e);
                }
                check(name, py_set1r(name.c_str(), v.data(), v.size()));
            }

            if (i) {
                std::vector<int> v;
                for (auto e : l) {
                    v.push_back(e);
                }
                check(name, py_set1i(name.c_str(), v.data(), v.size()));
            }
            continue;
        }


        std::ostringstream oss;
        oss << "Value type not supported: " << name << " = " << value;
        throw MagicsException(oss.str());
    }

    if (proc) {
        check(action, proc());
    }
}


static void plot(const std::string&, const Value& param) {
    ValueList actions = param;

    check("plot", py_open());

    for (auto j = actions.begin(); j != actions.end(); ++j) {
        ValueMap p = (*j);
        for (auto k = p.begin(); k != p.end(); ++k) {
            execute((*k).first, (*k).second);
        }
    }

    check("plot", py_close());
}

typedef void (*command_proc)(const std::string&, const Value&);


static std::map<std::string, command_proc> commands = {{"plot", plot}};


void MagYaml::processFile(const std::string& path) {
    py_set_python();
    ValueMap p = YAMLParser::decodeFile(path);
    for (auto j = p.begin(); j != p.end(); ++j) {
        std::string command = (*j).first;
        auto k              = commands.find(command);
        if (k == commands.end()) {
            throw MagicsException("Unknown command: " + command);
        }
        (*(*k).second)(command, (*j).second);
    }
}
