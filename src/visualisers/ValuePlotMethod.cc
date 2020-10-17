/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file ValuePlotMethod.cc
    \brief

    Changes:

*/

#include "ValuePlotMethod.h"

ValuePlotMethod* magics::ValuePlotMethod::clone() const {
    ValuePlotMethod* object = new ValuePlotMethod();
    object->copy(*this);
    return object;
}

void ValuePlotMethod::operator()(PointsHandler& data, const Transformation& transformation) {
    reset();
    ThinningPointsHandler thinned(data, lon_frequency_, lat_frequency_);
    thinned.setToFirst();

    while (thinned.more()) {
        UserPoint point = thinned.current();
        double val      = point.value();
        if (min_ <= val && val <= max_) {
            PaperPoint xy = transformation(point);
            if (transformation.in(xy))
                add(xy);
        }
        thinned.advance();
    }
}

void ValuePlotMethod::add(const PaperPoint& xy) {
    static map<string, VerticalAlign> alignhandlers;
    if (alignhandlers.empty()) {
        alignhandlers["normal"] = VerticalAlign::NORMAL;
        alignhandlers["top"]    = VerticalAlign::TOP;
        alignhandlers["cap"]    = VerticalAlign::CAP;
        alignhandlers["half"]   = VerticalAlign::HALF;
        alignhandlers["base"]   = VerticalAlign::BASE;
        alignhandlers["bottom"] = VerticalAlign::BOTTOM;
    }
    ostringstream nice;
    nice << MagicsFormat(format_, xy.value());
    Text* text = new Text();
    text->addText(nice.str(), *colour_, height_);
    text->setJustification(justification_);
    map<string, VerticalAlign>::iterator pos = alignhandlers.find(lowerCase(vertical_align_));
    VerticalAlign align                      = (pos != alignhandlers.end()) ? pos->second : VerticalAlign::BASE;
    text->setVerticalAlign(align);
    text->push_back(xy);
    push_back(text);
}

void ValuePlotMethod::operator()(MatrixHandler& data, const Transformation& transformation) {
    reset();
    int rows    = data.rows();
    int columns = data.columns();
    for (int j = 0; j < rows; j += lat_frequency_) {
        for (int i = 0; i < columns; i += lon_frequency_) {
            double val = data(j, i);
            if (min_ <= val && val <= max_ && val != data.missing()) {
                UserPoint point(data.column(j, i), data.row(j, i), data(j, i));
                PaperPoint xy = transformation(point);
                if (transformation.in(xy))
                    add(xy);
            }
        }
    }
}
