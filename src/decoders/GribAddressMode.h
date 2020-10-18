/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file GribAddressMode.h
    \brief Definition of the Template class GribAddressMode.

    Magics Team - ECMWF 2006

    Started: Mon 13-Feb-2006

    Changes:

*/

#ifndef GribAddressMode_H
#define GribAddressMode_H

#include "Factory.h"
#include "MagTranslator.h"
#include "magics.h"

#include "grib_api.h"


namespace magics {

class XmlNode;

class GribAddressMode {
public:
    GribAddressMode() {}
    virtual ~GribAddressMode() {}

    virtual void set(const XmlNode&) {}
    virtual void set(const map<string, string>&) {}

    virtual bool accept(const string&) { return false; }

    virtual GribAddressMode* clone() const;
    virtual void toxml(ostream&, int = 0) const;
    virtual grib_handle* operator()(grib_context*, FILE*, int) const;
    virtual grib_handle* operator()(grib_context*, FILE*, long int) const;

protected:
    //! Method to print string about this class on to a stream of type ostream (virtual).
    virtual void print(ostream& out) const;

private:
    //! Copy constructor - No copy allowed
    GribAddressMode(const GribAddressMode&);
    //! Overloaded << operator to copy - No copy allowed
    GribAddressMode& operator=(const GribAddressMode&);

    // -- Friends
    //! Overloaded << operator to call print().
    friend ostream& operator<<(ostream& s, const GribAddressMode& p) {
        p.print(s);
        return s;
    }
};

class GribAddressRecordMode : public GribAddressMode {
public:
    GribAddressRecordMode() {}
    ~GribAddressRecordMode() {}

    virtual GribAddressMode* clone() const override;

    virtual grib_handle* operator()(grib_context*, FILE* file, int position) const override;

protected:
    void print(ostream& out) const override;
};

class GribAddressByteMode : public GribAddressMode {
public:
    GribAddressByteMode() {}
    ~GribAddressByteMode() {}
    virtual GribAddressMode* clone() const override;

    virtual grib_handle* operator()(grib_context* context, FILE* file, int position) const override;
    virtual grib_handle* operator()(grib_context* context, FILE* file, long int position) const override;

protected:
    void print(ostream& out) const override;
};


template <>
class MagTranslator<string, GribAddressMode> {
public:
    GribAddressMode* operator()(const string& val) { return SimpleObjectMaker<GribAddressMode>::create(val); }

    GribAddressMode* magics(const string& param) {
        string val;
        ParameterManager::get(param, val);
        return (*this)(val);
    }
};

}  // namespace magics
#endif
