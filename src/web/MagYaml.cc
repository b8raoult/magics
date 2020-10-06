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
    {"output", nullptr}, {"mmap", nullptr}, {"mcoast", py_coast}, {"mtable", py_table}, {"msymb", py_symb},
};

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
    action_proc proc = (*k).second;


    ValueMap param = p;
    for (auto j = param.begin(); j != param.end(); ++j) {
        std::string name = (*j).first;
        Value value      = (*j).second;

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
