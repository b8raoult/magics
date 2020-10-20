/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor
 * does it submit to any jurisdiction.
 */

/*! \file NetcdfDecoder.h
    \brief Definition of the Template class NetcdfDecoder.

    Magics Team - ECMWF 2004

    Started: Tue 17-Feb-2004

    Changes:

*/

#ifndef NetcdfDecoder_H
#define NetcdfDecoder_H

#include "AnimationRules.h"
#include "magics.h"

#include "Data.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsDecoder.h"
#include "NetcdfDecoderAttributes.h"
#include "PointsHandler.h"
#include "UserPoint.h"

namespace magics {

class Transformation;

class NetcdfDecoder : public Decoder, public Data, public NetcdfDecoderAttributes {
public:
    NetcdfDecoder();
    virtual ~NetcdfDecoder();

    void decode() override {}
    // implements BaseSceneObject interface
    virtual void set(const map<string, string>& params) override { NetcdfDecoderAttributes::set(params); }
    virtual void set(const XmlNode& node) override { NetcdfDecoderAttributes::set(node); }
    virtual void visit(MagnifierVisitor&);

    virtual PointsHandler& points(const Transformation&, bool) override;

    void customisedPoints(const Transformation& t, const std::set<string>& n, CustomisedPointsList& out,
                          bool all) override {
        customisedPoints(t, n, out);
    }

    void getReady(const Transformation& transformation) override { (*interpretor_).getReady(transformation); }

    void visit(Transformation& transformation) override { (*interpretor_).visit(transformation); }

    void getInfo(map<string, string>&) override;

    void applyScaling(double scaling, double offset) override;

    MatrixHandler& matrix() override;

    void customisedPoints(const std::set<string>& request, CustomisedPointsList& out) {
        (*interpretor_).customisedPoints(request, out);
    }
    void customisedPoints(const Transformation& transformation, const std::set<string>& request,
                          CustomisedPointsList& out) {
        (*interpretor_).customisedPoints(transformation, request, out, thinningFactor_);
    }

    void visit(AnimationStep& step) override;
    void visit(MetaDataCollector&) override;
    void visit(ValuesCollector&) override;
    void visit(TextVisitor&) override;

    virtual std::string getUnits() const override;

protected:
    //! Method to print string about this class on to a stream of type ostream
    //! (virtual).
    virtual void print(ostream&) const override;

    PointsList points_;
    Matrix* data_;

private:
    //! Copy constructor - No copy allowed
    NetcdfDecoder(const NetcdfDecoder&);
    //! Overloaded << operator to copy - No copy allowed
    NetcdfDecoder& operator=(const NetcdfDecoder&);
};

class NetcdfLoop : public DataLoop {
public:
    NetcdfLoop(NetcdfDecoder* netcdf) : netcdf_(netcdf) {}
    virtual ~NetcdfLoop() {}
    void set(const map<string, string>& map) override {}  // NetcdfLoopAttributes::set(map); }
    void set(const XmlNode& node) override {}             // NetcdfLoopAttributes::set(node); }

    void set(NetcdfDecoder* netcdf) { netcdf_ = netcdf; }

    Data* current() override {
        NetcdfDecoder* current = netcdf_;
        netcdf_                = 0;
        return current;
    }
    bool hasMore() override { return (netcdf_ != 0); }
    void next() override { netcdf_ = 0; }

    void visit(Transformation& transformation) override {
        if (netcdf_)
            netcdf_->visit(transformation);
    }

protected:
    virtual void print(ostream& s) const override { s << "NetcdfDecoder[]"; }
    NetcdfDecoder* netcdf_;

private:
    //! Copy constructor - No copy allowed
    NetcdfLoop(const NetcdfLoop&);
    //! Overloaded << operator to copy - No copy allowed
    NetcdfLoop& operator=(const NetcdfLoop&);

    // -- Friends
    //! Overloaded << operator to call print().
    friend ostream& operator<<(ostream& s, const NetcdfLoop& p) {
        p.print(s);
        return s;
    }
};

}  // namespace magics
#endif
