/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file IsoHighlight.cc
    \brief

    Changes:

*/

#include "IsoHighlight.h"

NoIsoHighlight* IsoHighlight::clone() const {
    IsoHighlight* plot = new IsoHighlight();
    plot->copy(*this);
    return plot;
}

void magics::IsoHighlight::visit(magics::Polyline*& line) {
    line = new Polyline();
    line->setColour(*this->colour_);
    line->setLineStyle(style_);
    line->setThickness(this->thickness_);
}

void IsoHighlight::prepare(LevelSelection& levels) {
    vector<double> todo;
    clear();
    levels.thinLevels(frequency_, todo);
    for (LevelSelection::const_iterator level = todo.begin(); level != todo.end(); ++level) {
        (*this)[*level] = *level;
    }
}

void IsoHighlight::operator()(Polyline& poly) {
    if (poly.empty())
        return;

    // MagLog::dev() << "HIGHTLIGHT?--->" << point << "=" << point.value() << "\n";
    const_iterator high = find(poly.back().value());
    if (high == end())
        return;
    poly.setColour(*colour_);
    poly.setLineStyle(style_);
    // MagLog::dev() << "set--->" << thickness_ << "\n";
    poly.setThickness(thickness_);
}

NoIsoHighlight* NoIsoHighlight::clone() const {
    NoIsoHighlight* plot = new NoIsoHighlight();
    return plot;
}
