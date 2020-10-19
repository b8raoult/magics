/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file PaperPoint.cc
    \brief

    Changes:

*/

#include "PaperPoint.h"

using namespace magics;

PaperPoint::PaperPoint(double x, double y, double value, bool missing, bool border, int range,
                               const string& name) :
    x_(x),
    y_(y),
    value_(value),
    range_(range),
    name_(name),
    high_(false),
    low_(false),
    missing_(missing),
    border_(border) {}

magics::PaperPoint::PaperPoint() :
    x_(0), y_(0), value_(0), name_(""), high_(false), low_(false), missing_(false), border_(false) {}
