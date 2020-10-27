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


#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
#include <filesystem>
namespace fs = std::filesystem;
#else
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif


namespace magics {

static std::map<std::string, ValueMap> styles_;
static std::vector<ValueMap> rules_;

static std::string library_path_ = "<none>";

static size_t counter_ = 0;

static void process(const std::string& path, const ValueMap& entry, int n) {
    bool style = (entry.find("magics") != entry.end());
    bool rule  = (entry.find("match") != entry.end());

    if (rule && style) {

        std::ostringstream oss;
        oss << fs::path(path).stem() << "/" << (counter_++) << "/" << n;
        std::string name = oss.str();

        ASSERT(entry.find("styles") == entry.end());
        ValueList styles;
        styles.push_back(name);

        ValueMap e = entry;
        e["styles"] = styles;

        styles_[name]    = e;
        rules_.push_back(e);


        return;
    }

    if (rule) {
        rules_.push_back(entry);
        return;
    }

    if (style) {
        std::string name = fs::path(path).stem();
        styles_[name]    = entry;
        return;
    }
}


struct Entry {
    size_t rank_;
    std::string path_;
    Entry(size_t rank, const std::string& path) : rank_(rank), path_(path) {}
    bool operator<(const Entry& other) const {
        if (rank_ == other.rank_) {
            return path_ < other.path_;
        }
        return rank_ < other.rank_;
    }
};

static void init(const std::string& library_path) {
    if (library_path_ == library_path) {
        return;
    }


    Tokenizer tokenizer(":");
    vector<string> paths;
    tokenizer(library_path, paths);

    if (paths.size() == 0) {
        paths.push_back("default");  // Or
    }

    std::vector<Entry> entries;

    size_t n = 0;
    for (auto path : paths) {
        if (path == "default") {
            path = buildConfigPath("styles", "climetlab");
        }
        std::cout << "SCANNING " << path << std::endl;
        for (auto& p : fs::recursive_directory_iterator(path)) {
            std::string ext  = p.path().extension();
            std::string full = p.path().string();

            if (ext == ".yaml" || ext == ".json") {
                entries.push_back(Entry(n, full));
            }
        }
        std::cout << "DONE " << path << std::endl;
        n++;
    }

    std::sort(entries.begin(), entries.end());

    for (const auto& entry : entries) {
        const std::string& full = entry.path_;
        try {
            Value m = MagParser::decodeFile(full);
            if (m.isList()) {
                ValueList l = m;
                int n = 0;
                for (auto& v : l) {
                    process(full, v, n++);
                }
            }
            else {
                process(full, m, 0);
            }
        }
        catch (std::exception& e) {
            MagLog::error() << "Error processing " << full << ": " << e.what() << ", ignored." << std::endl;
        }
    }

    library_path_ = library_path;
}

CliMetLabLibrary::CliMetLabLibrary() {}

CliMetLabLibrary::~CliMetLabLibrary() {}

StyleEntry* CliMetLabLibrary::getStyle(Data& data, const std::string& library_path, MagDef& visdef) {
    init(library_path);
    std::string path = buildConfigPath("styles", "climetlab") + "/rules";


    MetaDataCollector collect;

    // Collected which values are needed by the rukes
    std::set<std::string> keys;
    for (ValueMap rule : rules_) {
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

    for (ValueMap rule : rules_) {
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

    if (score == -1) {
        // FIXME
        {
            ofstream out("style");
            out << "default" << std::endl;
        }
        return nullptr;
    }

    std::cout << best << std::endl;

    std::string style_name = std::string(best["styles"][0]);
    // FIXME
    {
        ofstream out("style");
        out << style_name << std::endl;
    }

    ValueMap contour = styles_[style_name]["magics"]["mcont"];

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
                    oss << sep << (bool(v) ? "on" : "off");
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

    // If not found, seach by units


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
