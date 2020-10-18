/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file IsoHighlight.h
    \brief Definition of the Template class IsoHighlight.

    Magics Team - ECMWF 2004

    Started: Wed 25-Aug-2004

    Changes:

*/

#ifndef IsoHighlight_H
#define IsoHighlight_H

#include "magics.h"

#include "Factory.h"
#include "IsoHighlightAttributes.h"
#include "LevelSelection.h"
#include "MagTranslator.h"
#include "Polyline.h"

namespace magics {

class NoIsoHighlight {
public:
    NoIsoHighlight() {}
    virtual ~NoIsoHighlight() {}
    virtual NoIsoHighlight* clone() const;
    virtual void set(const map<string, string>&) {}
    virtual void set(const XmlNode&) {}
    virtual void toxml(ostream&, int = 0) const {}
    virtual bool accept(const string&) { return true; }

    virtual void prepare(LevelSelection&) {}
    virtual void visit(Polyline*&) {}


    virtual void operator()(Polyline&) {}

protected:
    //! Method to print string about this class on to a stream of type ostream (virtual).
    virtual void print(ostream& s) const { s << "NoIsoHighlight[]"; }

private:
    //! Copy constructor - No copy allowed
    NoIsoHighlight(const NoIsoHighlight&);
    //! Overloaded << operator to copy - No copy allowed
    NoIsoHighlight& operator=(const NoIsoHighlight&);
    // -- Friends
    //! Overloaded << operator to call print().
    friend ostream& operator<<(ostream& s, const NoIsoHighlight& p) {
        p.print(s);
        return s;
    }
};

class IsoHighlight : public NoIsoHighlight, public map<double, double>, public IsoHighlightAttributes {
public:
    IsoHighlight() {}
    virtual ~IsoHighlight() override {}
    virtual NoIsoHighlight* clone() const override;
    virtual void set(const map<string, string>& map) override { IsoHighlightAttributes::set(map); }
    virtual void set(const XmlNode& node) override { IsoHighlightAttributes::set(node); }

    virtual bool accept(const string& tag) override { return IsoHighlightAttributes::accept(tag); }
    virtual void visit(Polyline*& line) override;
    virtual void prepare(LevelSelection& levels) override;

    virtual void operator()(Polyline& poly) override;

protected:
    //! Method to print string about this class on to a stream of type ostream (virtual).
    virtual void print(ostream& s) const override { s << "IsoHighlight[]"; }

private:
    //! Copy constructor - No copy allowed
    IsoHighlight(const IsoHighlight&);
    //! Overloaded << operator to copy - No copy allowed
    IsoHighlight& operator=(const IsoHighlight&);
};


template <>
class MagTranslator<string, NoIsoHighlight> {
public:
    NoIsoHighlight* operator()(const string& val) { return SimpleObjectMaker<NoIsoHighlight>::create(val); }
    NoIsoHighlight* magics(const string& param) {
        NoIsoHighlight* object = 0;
        ParameterManager::update(param, object);
        return object;
    }
};

}  // namespace magics
#endif
