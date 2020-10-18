/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file Coordinate.cc
    \brief Implementation of the Template class Coordinate.

    Magics Team - ECMWF 2006

    Started: Thu 10-Aug-2006

    Changes:

*/

#include "Coordinate.h"

using namespace magics;

Coordinate::Coordinate() {
    if (automatic() != AxisAutomaticSetting::OFF) {
        minmax(std::numeric_limits<double>::max(), -std::numeric_limits<double>::max());
    }
}


Coordinate::~Coordinate() {}


/*!
 Class information are given to the output-stream.
*/
void Coordinate::print(ostream& out) const {
    out << "Coordinate[";
    out << "]";
}

void YCoordinate::getNewDefinition(const UserPoint& ll, const UserPoint& ur, map<string, string>& def) const {
    def["y_axis_type"] = type();
    def["y_min"]       = tostring(ll.y_);
    def["y_max"]       = tostring(ur.y_);
    def["y_automatic"] = "off";
}

void XRegularCoordinate::set() {
    switch (automatic_) {
        case AxisAutomaticSetting::BOTH:
            if (reverse_) {
                max_ = std::numeric_limits<double>::max();
                min_ = -max_;
            }
            else {
                min_ = std::numeric_limits<double>::max();
                max_ = -min_;
            }
            break;

        case AxisAutomaticSetting::MIN_ONLY:
            min_ = std::numeric_limits<double>::max();
            break;

        case AxisAutomaticSetting::MAX_ONLY:
            max_ = -std::numeric_limits<double>::max();
            break;

        default:
            NOTIMP;
            break;
    }
}

void XRegularCoordinate::minmax(double min, double max) {
    switch (automatic_) {
        case AxisAutomaticSetting::BOTH:
            // set the
            if (reverse_) {
                max_ = std::min(min, max_);
                min_ = std::max(max, min_);
            }
            else {
                min_ = std::min(min, min_);
                max_ = std::max(max, max_);
            }
            break;
        case AxisAutomaticSetting::MIN_ONLY:
            if (reverse_)
                max_ = std::min(min, max_);
            else
                min_ = std::min(min, min_);
            break;

        case AxisAutomaticSetting::MAX_ONLY:
            if (reverse_)
                min_ = std::max(max, min_);
            else
                max_ = std::max(max, max_);
            break;

        default:
            NOTIMP;
            break;
    }
}

void YRegularCoordinate::set() {
    switch (automatic_) {
        case AxisAutomaticSetting::BOTH:
            if (reverse_) {
                max_ = std::numeric_limits<double>::max();
                min_ = -max_;
            }
            else {
                min_ = std::numeric_limits<double>::max();
                max_ = -min_;
            }
            break;

        case AxisAutomaticSetting::MIN_ONLY:
            min_ = std::numeric_limits<double>::max();
            break;

        case AxisAutomaticSetting::MAX_ONLY:
            max_ = -std::numeric_limits<double>::max();
            break;

        default:
            NOTIMP;
            break;
    }
}

void YRegularCoordinate::minmax(double min, double max) {
    switch (automatic_) {
        case AxisAutomaticSetting::BOTH:
            // set the
            if (reverse_) {
                max_ = std::min(min, max_);
                min_ = std::max(max, min_);
            }
            else {
                min_ = std::min(min, min_);
                max_ = std::max(max, max_);
            }
            break;

        case AxisAutomaticSetting::MIN_ONLY:
            if (reverse_)
                max_ = std::min(min, max_);
            else
                min_ = std::min(min, min_);
            break;

        case AxisAutomaticSetting::MAX_ONLY:
            if (reverse_)
                min_ = std::max(max, min_);
            else
                max_ = std::max(max, max_);
            break;

        default:
            NOTIMP;
            break;
    }
}

void XLogarithmicCoordinate::set() {
    switch (automatic_) {
        case AxisAutomaticSetting::BOTH:
            if (reverse_) {
                max_ = std::numeric_limits<double>::max();
                min_ = -max_;
            }
            else {
                min_ = std::numeric_limits<double>::max();
                max_ = -min_;
            }
            break;

        case AxisAutomaticSetting::MIN_ONLY:
            automatic_ = AxisAutomaticSetting::OFF;
            min_       = std::numeric_limits<double>::max();
            break;

        case AxisAutomaticSetting::MAX_ONLY:
            automatic_ = AxisAutomaticSetting::OFF;
            max_       = -std::numeric_limits<double>::max();
            break;

        default:
            NOTIMP;
            break;
    }
}

void XLogarithmicCoordinate::minmax(double min, double max) {
    switch (automatic_) {
        case AxisAutomaticSetting::BOTH:
            // set the
            if (reverse_) {
                max_ = std::min(min, max_);
                min_ = std::max(max, min_);
            }
            else {
                min_ = std::min(min, min_);
                max_ = std::max(max, max_);
            }
            break;

        case AxisAutomaticSetting::MIN_ONLY:
            if (reverse_)
                max_ = std::min(min, max_);
            else
                min_ = std::min(min, min_);
            break;

        case AxisAutomaticSetting::MAX_ONLY:
            if (reverse_)
                min_ = std::max(max, min_);
            else
                max_ = std::max(max, max_);
            break;

        default:
            NOTIMP;
            break;
    }
}

void XLogarithmicCoordinate::getNewDefinition(const UserPoint& ll, const UserPoint& ur,
                                              map<string, string>& def) const {
    def["x_axis_type"] = "logarithmic";
    def["x_min"]       = tostring(ll.x_);
    def["x_max"]       = tostring(ur.x_);
    def["x_automatic"] = "off";
}

void YLogarithmicCoordinate::set() {
    switch (automatic_) {
        case AxisAutomaticSetting::BOTH:
            if (reverse_) {
                max_ = std::numeric_limits<double>::max();
                min_ = -max_;
            }
            else {
                min_ = std::numeric_limits<double>::max();
                max_ = -min_;
            }
            break;

        case AxisAutomaticSetting::MIN_ONLY:
            min_ = std::numeric_limits<double>::max();
            break;

        case AxisAutomaticSetting::MAX_ONLY:
            max_ = -std::numeric_limits<double>::max();
            break;

        default:
            NOTIMP;
            break;
    }
}

void YLogarithmicCoordinate::minmax(double min, double max) {
    switch (automatic_) {
        case AxisAutomaticSetting::BOTH:
            // set the
            if (reverse_) {
                max_ = std::min(min, max_);
                min_ = std::max(max, min_);
            }
            else {
                min_ = std::min(min, min_);
                max_ = std::max(max, max_);
            }
            break;

        case AxisAutomaticSetting::MIN_ONLY:
            if (reverse_)
                max_ = std::min(min, max_);
            else
                min_ = std::min(min, min_);
            break;

        case AxisAutomaticSetting::MAX_ONLY:
            if (reverse_)
                min_ = std::max(max, min_);
            else
                max_ = std::max(max, max_);
            break;

        default:
            NOTIMP;
            break;
    }
}

void YLogarithmicCoordinate::getNewDefinition(const UserPoint& ll, const UserPoint& ur,
                                              map<string, string>& def) const {
    def["y_axis_type"] = "logarithmic";
    def["y_min"]       = tostring(::pow(10., ll.y_));
    def["y_max"]       = tostring(::pow(10., ur.y_));
    def["y_automatic"] = "off";
}

AxisAutomaticSetting XDateCoordinate::automatic() {
    return (automatic_ != AxisAutomaticSetting::OFF) ? AxisAutomaticSetting::BOTH : AxisAutomaticSetting::OFF;
}

void XDateCoordinate::dataMinMax(double min, double max, const string& date) {
    DateTime base(date);
    DateTime mind = base + Second(min);
    DateTime maxd = base + Second(max);
    if (date_min_.empty())
        date_min_ = string(mind);
    if (date_max_.empty())
        date_max_ = string(maxd);
    DateTime mind_(date_min_);
    DateTime maxd_(date_max_);

    switch (automatic_) {
        case AxisAutomaticSetting::BOTH:
            // set the
            if (reverse_) {
                maxd_ = std::min(mind, maxd_);
                mind_ = std::max(maxd, mind_);
            }
            else {
                mind_ = std::min(mind, mind_);
                maxd_ = std::max(maxd, maxd_);
            }
            break;

        case AxisAutomaticSetting::MIN_ONLY:
            if (reverse_)
                maxd_ = std::min(mind, maxd_);
            else
                mind_ = std::min(mind, mind_);
            break;

        case AxisAutomaticSetting::MAX_ONLY:
            if (reverse_)
                mind_ = std::max(maxd, mind_);
            else
                maxd_ = std::max(maxd, maxd_);
            break;

        default:
            NOTIMP;
            break;
    }
    date_max_ = string(maxd_);
    date_min_ = string(mind_);
}

void XDateCoordinate::getNewDefinition(const UserPoint& ll, const UserPoint& ur, map<string, string>& def) const {
    DateTime min       = DateTime(date_min_) + Second(ll.x_);
    DateTime max       = DateTime(date_min_) + Second(ur.x_);
    def["x_axis_type"] = "date";
    def["x_date_min"]  = tostring(min);
    def["x_date_max"]  = tostring(max);
    def["x_automatic"] = "off";
}
