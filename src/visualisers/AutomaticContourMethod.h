/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file AutomaticContourMethod.h
    \brief Definition of the Template class AutomaticContourMethod.

    Magics Team - ECMWF 2004

    Started: Mon 4-Oct-2004

    Changes:

*/

#ifndef AutomaticContourMethod_H
#define AutomaticContourMethod_H

#include "magics.h"

#include "Akima760Method.h"
#include "BasicSceneObject.h"
#include "ContourMethod.h"
#include "MatrixHandler.h"


namespace magics {


class AutomaticContourMethod : public ContourMethod {
public:
    AutomaticContourMethod();
    virtual ~AutomaticContourMethod();
    ContourMethod* clone();
    virtual bool accept(const string& node);

    virtual MatrixHandler* handler(const AbstractMatrix& matrix, const BasicGraphicsObjectContainer& owner);

protected:
    //! Method to print string about this class on to a stream of type ostream (virtual).
    virtual void print(ostream& out) const override;

private:
    //! Copy constructor - No copy allowed
    AutomaticContourMethod(const AutomaticContourMethod&);
    //! Overloaded << operator to copy - No copy allowed
    AutomaticContourMethod& operator=(const AutomaticContourMethod&);

    // -- Friends
    //! Overloaded << operator to call print().
    friend ostream& operator<<(ostream& s, const AutomaticContourMethod& p) {
        p.print(s);
        return s;
    }
};


}  // namespace magics

#endif
