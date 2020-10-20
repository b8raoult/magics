/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file Units.cc
    \brief Implementation of Units class.


    Changes:


*/
#include "Units.h"
#include <map>

#include "MagException.h"
#include "MagLog.h"
#include "MagParser.h"
#include "MagicsSettings.h"

using namespace magics;


struct Scaling {
    double scaling_;
    double offset_;
    Scaling(double scaling = 1, double offset = 0) : scaling_(scaling), offset_(offset) {}
};


static std::map<std::pair<std::string, std::string>, Scaling> conversions;

static void init() {
    if (conversions.empty()) {
        std::set<std::string> seen;

        std::string path = buildConfigPath("units-rules.json");
        ValueMap values  = MagParser::decodeFile(path);
        for (auto j = values.begin(); j != values.end(); ++j) {
            ValueList entries = (*j).second;
            for (auto& e : entries) {
                std::string from = e["from"];
                std::string to   = e["to"];
                double scaling   = e["scaling"];
                double offset    = e["offset"];

                if (seen.find(from) != seen.end()) {
                    MagLog::error() << "Unit [" + from + "] detected more than once" << std::endl;
                    // throw MagicsException("Unit " + from + " already defined");
                }
                seen.insert(from);

                conversions[std::make_pair(from, to)] = Scaling(scaling, offset);
            }
        }
    }
}

bool Units::convert(const std::string& from, const std::string& to, double& scaling, double& offset) {
    scaling = 1;
    offset  = 0;

    init();

    if (to.empty()) {
        return false;
    }

    if(from == "~") {
        // FIXME:
        MagLog::warning() << "Cannot convert data to " << to << ", data units not known" << std::endl;
        return false;
    }

    if (from.empty()) {
        if (MagicsSettings::strict()) {
            throw MagicsException("Cannot convert data to " + to + ", data units not known");
        }
        MagLog::warning() << "Cannot convert data to " << to << ", data units not known" << std::endl;
        return false;
    }

    if (from == to) {
        std::cout << "++++++ Units " << from << " to " << to << " scaling " << scaling << " offset " << offset
                  << std::endl;
        return false;
    }

    auto j = conversions.find(std::make_pair(from, to));
    if (j != conversions.end()) {
        scaling = (*j).second.scaling_;
        offset  = (*j).second.offset_;
        std::cout << "++++++ Units " << from << " to " << to << " scaling " << scaling << " offset " << offset
                  << std::endl;
        return true;
    }

    // y = a * x + b
    // x = (y - b)/a

    j = conversions.find(std::make_pair(to, from));
    if (j != conversions.end()) {
        scaling = 1.0 / (*j).second.scaling_;
        offset  = -(*j).second.offset_ / (*j).second.scaling_;
        std::cout << "++++++ Units (reversed) " << from << " to " << to << " scaling " << scaling << " offset "
                  << offset << std::endl;

        return true;
    }

    if (MagicsSettings::strict()) {
        throw MagicsException("Cannot convert data from [" + from + "] to [" + to + "]");
    }
    MagLog::warning() << "Cannot convert data from [" << from << "] to [" << to << "]" << std::endl;
    return false;
}

void Units::defaultScaling(double& scaling, double& offset, std::string& dataUnits, std::string& plotUnits) {
    init();

    for (auto j = conversions.begin(); j != conversions.end(); ++j) {
        if ((*j).first.first == dataUnits) {
            plotUnits = (*j).first.first;
            scaling   = (*j).second.scaling_;
            offset    = (*j).second.offset_;
        }
    }
}
