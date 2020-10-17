/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file BothValuePlotMethod.cc
    \brief

    Changes:

*/

#include "BothValuePlotMethod.h"

BothValuePlotMethod::BothValuePlotMethod() : marker_(0) {}

BothValuePlotMethod::~BothValuePlotMethod() {}

void BothValuePlotMethod::set(const map<string, string> &map) {
    BothValuePlotMethodAttributes::set(map);
    ValuePlotMethodAttributes::set(map);
}

void BothValuePlotMethod::set(const XmlNode &node) {
    BothValuePlotMethodAttributes::set(node);
    ValuePlotMethodAttributes::set(node);
}

ValuePlotMethod *BothValuePlotMethod::clone() const {
    BothValuePlotMethod* object = new BothValuePlotMethod();
    object->clone(*this);
    return object;
}

void BothValuePlotMethod::clone(const BothValuePlotMethod &from) {
    BothValuePlotMethodAttributes::copy(from);
    ValuePlotMethodAttributes::copy(from);
}

void BothValuePlotMethod::print(ostream &out) const {
    out << "BothValuePlotMethod[";
    BothValuePlotMethodAttributes::print(out);
    ValuePlotMethodAttributes::print(out);
    out << "]";
}

void BothValuePlotMethod::reset() { marker_ = 0; }

void magics::BothValuePlotMethod::add(const magics::PaperPoint &xy) {
    static map<string, TextSymbol::TextPosition> poshandlers;
    if (poshandlers.empty()) {
        poshandlers["none"]   = TextSymbol::M_NONE;
        poshandlers["left"]   = TextSymbol::M_LEFT;
        poshandlers["top"]    = TextSymbol::M_ABOVE;
        poshandlers["bottom"] = TextSymbol::M_BELOW;
        poshandlers["right"]  = TextSymbol::M_RIGHT;
        poshandlers["centre"] = TextSymbol::M_CENTRE;
    }
    if (!marker_) {
        marker_                                             = new TextSymbol();
        map<string, TextSymbol::TextPosition>::iterator pos = poshandlers.find(lowerCase(position_));
        TextSymbol::TextPosition position = (pos != poshandlers.end()) ? pos->second : TextSymbol::M_ABOVE;
        marker_->position(position);
        marker_->setMarker(marker_index_);
        marker_->setColour(*marker_colour_);
        marker_->setHeight(marker_height_);
        marker_->blanking(false);
        MagFont font;
        font.size(this->height_);
        font.colour(*this->colour_);
        marker_->font(font);
        this->push_back(marker_);
    }
    marker_->push_back(xy, this->label(xy.value()));
}
