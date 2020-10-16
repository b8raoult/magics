/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file ContourLibrary.h
    \brief Definition of the Template class ContourLibrary.

    Magics Team - ECMWF 2010

    Started: Fri 16-Jul-2010

    Changes:

*/


#include "CliMetLabLibrary.h"
#include "Data.h"
#include "MagParser.h"
#include "MetaData.h"

#ifndef MAGICS_ON_WINDOWS
#include <dirent.h>
#else
#include <direct.h>
#include <io.h>
#endif

namespace magics {


CliMetLabLibrary::CliMetLabLibrary() {}

CliMetLabLibrary::~CliMetLabLibrary() {}

StyleEntry* CliMetLabLibrary::getStyle(Data& data, const std::string& library_path, MagDef& visdef) {
    std::string path = buildConfigPath("styles", "climetlab") + "/rules";

    DIR* dir = opendir(path.c_str());
    if (!dir) {
        throw CannotOpenFile(path);
    }

    ValueList rules;

    struct dirent* entry = readdir(dir);
    while (entry) {
        std::string name(entry->d_name);
        std::string ext = name.size() > 6 ? name.substr(name.size() - 5) : std::string();

        if (ext == ".yaml" || ext == ".json") {
            std::string full = path + "/" + name;
            try {
                Value m = MagParser::decodeFile(full);
                if (m.isList()) {
                    ValueList l = m;
                    for (auto& v : l) {
                        v["path"] = full;
                        rules.push_back(v);
                    }
                }
                else {
                    m["path"] = full;
                    rules.push_back(m);
                }
            }
            catch (std::exception& e) {
                MagLog::error() << "Error processing " << full << ": " << e.what() << ", ignored." << std::endl;
            }
        }

        entry = readdir(dir);
    }

    MetaDataCollector collect;

    // Collected which values are needed by the rukes
    std::set<std::string> keys;
    for (const auto& rule : rules) {
        ValueList matches = rule["match"];
        for (ValueMap match : matches) {
            for (auto j = match.begin(); j != match.end(); ++j) {
                keys.insert((*j).first);
            }
        }
    }

    for (auto j = keys.begin(); j != keys.end(); ++j) {
        setCriteria(collect, *j);
    }

    // Get values from the grib or necdf
    data.visit(collect);

    std::cout << "=== DATA" << std::endl;
    for (auto j = collect.begin(); j != collect.end(); ++j) {
        if ((*j).second.size()) {
            std::cout << "--- " << (*j).first << " = " << (*j).second << std::endl;
        }
    }

    int score = -1;
    Value best;

    for (const auto& rule : rules) {
        ValueList matches = rule["match"];
        for (ValueMap match : matches) {
            int same = 0;
            for (auto j = match.begin(); j != match.end(); ++j) {
                std::string key = (*j).first;

                if ((*j).second.isList()) {
                    ValueList vals = (*j).second;
                    for (std::string val : vals) {
                        if (collect[key] == val) {
                            same++;
                            break;
                        }
                    }
                }
                else {
                    std::string val = (*j).second;

                    if (collect[key] == val) {
                        same++;
                    }
                }
            }

            if (same == match.size()) {
                if (same > score) {
                    score = same;
                    best  = rule;
                }
            }
        }
    }

    std::cout << best << std::endl;

    std::string style_name = std::string(best["styles"][0]);
    std::cout << "NAME: " << style_name << std::endl;

    path        = buildConfigPath("styles", "climetlab") + "/styles/" + style_name + ".yaml";
    Value style = MagParser::decodeFile(path);

    ValueMap contour = style["magics"]["mcont"];

    MagDef result;
    for (auto j = contour.begin(); j != contour.end(); ++j) {
        std::string key  = (*j).first;
        const Value& val = (*j).second;
        if (val.isList()) {
            std::ostringstream oss;
            const char* sep  = "";
            ValueList values = val;
            for (auto& v : values) {
                if (val.isBool()) {
                    oss << sep <<( bool(v) ? "on" : "off");
                }
                else {
                    oss << sep << v;
                }
                sep = "/";
            }
            result[(*j).first] = oss.str();
            continue;
        }

        if (val.isBool()) {
            result[(*j).first] = bool(val) ? "on" : "off";
        }
        else {
            result[(*j).first] = std::string(val);
        }
    }

    visdef = result;

    std::cout << "=== VISDEF" << std::endl;
    for (auto j = visdef.begin(); j != visdef.end(); ++j) {
        std::cout << "--- " << (*j).first << " = " << (*j).second << std::endl;
    }

    StyleEntry* s = new StyleEntry();
    vector<string> empty;
    empty.push_back(style_name);
    s->set("default", empty);

    // TODO: fill the entry
    return s;
}  // namespace magics

void CliMetLabLibrary::print(ostream& out) const {
    out << "CliMetLabLibrary[]";
}

static SimpleObjectMaker<CliMetLabLibrary, ContourLibrary> climetlab("climetlab");


}  // namespace magics
