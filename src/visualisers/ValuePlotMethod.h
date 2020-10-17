/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file ValuePlotMethod.h
    \brief Definition of the Template class ValuePlotMethod.

    Magics Team - ECMWF 2004

    Started: Thu 26-Aug-2004

    Changes:

*/

#ifndef ValuePlotMethod_H
#define ValuePlotMethod_H

#include "magics.h"

#include "MagicsFormat.h"
#include "MatrixHandler.h"
#include "PointsHandler.h"
#include "Text.h"
#include "Transformation.h"
#include "ValuePlotMethodAttributes.h"

namespace magics {


class ValuePlotMethod : public ValuePlotMethodAttributes, public vector<BasicGraphicsObject*> {
public:
    ValuePlotMethod() {}
    virtual ~ValuePlotMethod() {}
    virtual void set(const map<string, string>& map) { ValuePlotMethodAttributes::set(map); }
    virtual void set(const XmlNode& node) { ValuePlotMethodAttributes::set(node); }

    virtual ValuePlotMethod* clone() const;
    virtual void operator()(MatrixHandler& data, const Transformation& transformation);
    virtual void operator()(PointsHandler& data, const Transformation& transformation);


protected:
    //! Method to print string about this class on to a stream of type ostream (virtual).
    virtual void print(ostream& out) const {
        out << "ValuePlotMethod[";
        ValuePlotMethodAttributes::print(out);
        out << "]";
    }
    virtual void reset() {}  // For Metview, get ready for a second frame.
    virtual void add(const PaperPoint& xy);

    string label(double val) {
        ostringstream nice;
        nice << MagicsFormat(format_, val);
        return nice.str();
    }

private:
    //! Copy constructor - No copy allowed
    ValuePlotMethod(const ValuePlotMethod&);
    //! Overloaded << operator to copy - No copy allowed
    ValuePlotMethod& operator=(const ValuePlotMethod&);

    // -- Friends
    //! Overloaded << operator to call print().
    friend ostream& operator<<(ostream& s, const ValuePlotMethod& p) {
        p.print(s);
        return s;
    }
};

template <>
class MagTranslator<string, ValuePlotMethod> {
public:
    ValuePlotMethod* operator()(const string& val) { return SimpleObjectMaker<ValuePlotMethod>::create(val); }
    ValuePlotMethod* magics(const string& param) {
        ValuePlotMethod* object = 0;
        ParameterManager::update(param, object);
        return object;
    }
};

}  // namespace magics


#endif
