/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file BaseParameter.h
    \brief Definition of Parameter base class.

    Magics Team - ECMWF 2004

    Started: Jan 2004

    Changes:

*/

#ifndef BaseParameter_H
#define BaseParameter_H


#include <PaperPoint.h>
#include "MagException.h"
#include "Matrix.h"
#include "magics.h"

#ifdef LATER
#include <grib_api.h>
typedef grib_handle* GribHandlePtr;
#endif


#include <MagLog.h>


namespace magics {

class MistmatchType : public MagicsException {
public:
    MistmatchType(const string& name, const string& type, const string& wait);
};


class BaseParameter {
public:
    BaseParameter(const string& name);
    virtual ~BaseParameter();
    virtual void reset()           = 0;
    virtual BaseParameter* clone() = 0;
    const string& name() const { return name_; }

    virtual void set(const double&);
    virtual void get(double&) const;

    virtual void set(const bool&);
    virtual void get(bool&) const;

    virtual void set(const magvector<double>&);
    virtual void get(magvector<double>&) const;

    virtual void set(const int&);
    virtual void get(int&) const;

    virtual void set(const magvector<int>&);
    virtual void get(magvector<int>&) const;

    virtual void set(const magvector<long int>&);
    virtual void get(magvector<long int>&) const;

    virtual void set(const string&);
    virtual void get(string&) const;
    virtual void set(const char*);

    virtual void set(const magvector<string>&);
    virtual void get(magvector<string>&) const;

    virtual void set(const LineStyle&);
    virtual void get(LineStyle&) const;

    virtual void set(const DisplayType&);
    virtual void get(DisplayType&) const;

    virtual void set(const Justification&);
    virtual void get(Justification&) const;

    virtual void set(const ListPolicy&);
    virtual void get(ListPolicy&) const;

    virtual void set(const AxisAutomaticSetting&);
    virtual void get(AxisAutomaticSetting&) const;

    virtual void set(const ArrowPosition&);
    virtual void get(ArrowPosition&) const;

    virtual void set(const Matrix&);
    virtual void get(Matrix&) const;

    string getType(const string&) const;
    string getType(const int&) const;
    string getType(const double&) const;
    string getType(const magvector<string>&) const;
    string getType(const magvector<int>&) const;
    string getType(const magvector<long int>&) const;
    string getType(const magvector<double>&) const;

    string getType(const ListPolicy&) const;
    string getType(const LineStyle&) const;
    string getType(const AxisAutomaticSetting&) const;
    string getType(const Justification&) const;
    string getType(const ArrowPosition&) const;
    string getType(const Matrix&) const;
    string getType(const DisplayType&) const;

    virtual string type() const = 0;

protected:
    virtual void print(ostream&) const;
    string name_;

private:
    // No copy allowed
    BaseParameter(const BaseParameter&);
    BaseParameter& operator=(const BaseParameter&);

    // -- Friends
    friend ostream& operator<<(ostream& s, const BaseParameter& p) {
        p.print(s);
        return s;
    }
};

}  // namespace magics
#endif
