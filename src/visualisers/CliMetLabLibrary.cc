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


namespace magics {


CliMetLabLibrary::CliMetLabLibrary() {}

CliMetLabLibrary::~CliMetLabLibrary() {}

void CliMetLabLibrary::askId(MetaDataCollector& collector) {
    // NOTIMP;
    std::cout << "XXXXX askId " << std::endl;
}

bool CliMetLabLibrary::checkId(MetaDataCollector& collector1, MetaDataCollector& collector2) {
    // NOTIMP;
    std::cout << "XXXXX checkId" << std::endl;
    return false;
}

void CliMetLabLibrary::setCriteria(MetaDataCollector& collector, const string& criteria) {
    // NOTIMP;
    std::cout << "XXXXX setCriteria" << std::endl;
}

void CliMetLabLibrary::getStyle(MetaDataCollector& collector, MagDef& def, StyleEntry& style) {
    // NOTIMP;
    std::cout << "XXXXX getStyle" << std::endl;
}

void CliMetLabLibrary::getStyle(const string& name, MagDef& def) {
    std::cout << "XXXXX getStyle " << name << std::endl;
    // NOTIMP;
}

void CliMetLabLibrary::getScaling(MetaDataCollector& collector, double& scaling, double& offset) {
    // NOTIMP;
}

void CliMetLabLibrary::print(ostream& out) const {
    out << "CliMetLabLibrary[]";
}


static SimpleObjectMaker<CliMetLabLibrary, ContourLibrary> climetlab("climetlab");


}  // namespace magics
