/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file PolyCoast.h
    \brief Definition of the Template class CoastPlotting.

    Magics Team - ECMWF 2004

    Started: Mon 2-Feb-2004

    Changes:

*/
#ifndef PolyCoast_H
#define PolyCoast_H

#include "magics.h"

#include "Polyline.h"

namespace magics {


class PolyCoast : public Polyline {
public:
    PolyCoast();
    ~PolyCoast();

    virtual PolyCoast* clone() const;

    virtual Polyline* getNew() const;

    virtual Polyline* getShade() const;
    virtual Polyline* getContour() const;

    int level() const { return level_; }
    void level(int level) { level_ = level; }
    int greenwich() const { return greenwich_; }
    void greenwich(int greenwich) { greenwich_ = greenwich; }

    vector<UserPoint>& coastlines() { return coastlines_; }

protected:
    int level_;
    int greenwich_;
    double area_;
    vector<UserPoint> coastlines_;
};
}  // namespace magics
#endif
