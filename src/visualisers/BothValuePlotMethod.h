/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file BothValuePlotMethod.h
    \brief Definition of the Template class BothValuePlotMethod.

    Magics Team - ECMWF 2004

    Started: Thu 26-Aug-2004

    Changes:

*/

#ifndef BothValuePlotMethod_H
#define BothValuePlotMethod_H

#include "magics.h"

#include "BothValuePlotMethodAttributes.h"
#include "Symbol.h"
#include "ValuePlotMethod.h"
#include "ValuePlotMethodAttributes.h"

namespace magics {

class Transformation;


class BothValuePlotMethod : public ValuePlotMethod, public BothValuePlotMethodAttributes {
public:
    BothValuePlotMethod();
    virtual ~BothValuePlotMethod() override;
    virtual void set(const map<string, string>& map) override;
    virtual void set(const XmlNode& node) override;
    virtual ValuePlotMethod* clone() const override;

    virtual void clone(const BothValuePlotMethod& from);


protected:
    //! Method to print string about this class on to a stream of type ostream (virtual).
    virtual void print(ostream& out) const override;
    void reset() override;

    virtual void add(const PaperPoint& xy) override;

    TextSymbol* marker_;


private:
    //! Copy constructor - No copy allowed
    BothValuePlotMethod(const BothValuePlotMethod&);
    //! Overloaded << operator to copy - No copy allowed
    BothValuePlotMethod& operator=(const BothValuePlotMethod&);

    // -- Friends
    //! Overloaded << operator to call print().
    friend ostream& operator<<(ostream& s, const BothValuePlotMethod& p) {
        p.print(s);
        return s;
    }
};

}  // namespace magics


#endif
