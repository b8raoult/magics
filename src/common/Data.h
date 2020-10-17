/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file Data.h
    \brief Definition of the Abstract template class Data.

    Magics Team - ECMWF 2004

    Started: Fri 16-Jan-2004

    Changes:

*/

#ifndef Data_H
#define Data_H

#include "MagException.h"
#include "magics.h"

#include "BinningObject.h"
#include "CustomisedPoint.h"
#include "DataStats.h"
#include "Layer.h"
#include "MagDateTime.h"
#include "MagicsEvent.h"
#include "MatrixHandler.h"
#include "PointsHandler.h"
#include "RasterData.h"
#include "ThinningMethod.h"
#include "Transformation.h"

namespace magics {

class LegendVisitor;
class TextVisitor;
class MetaDataVisitor;
class MagnifierVisitor;
class LayerNode;
class AnimationRules;
class AnimationStep;


class DataInMemory : public MagicsException {
public:
    DataInMemory();
};


class Data : public MetviewIcon {
public:
    Data();
    virtual ~Data();
    //! Method to access the data as a matrix Used by pcont action routine
    virtual MatrixHandler& matrix();
    virtual MatrixHandler& matrix(const Transformation&);
    virtual MatrixHandler& norm();
    virtual MatrixHandler& direction();
    void binning(BinningObject* binning);

    virtual Data* current();
    virtual Data* next();


    virtual void release();

    virtual void getReady(const Transformation&);
    virtual void visit(Transformation&);

    // Method to access some metada from the data
    // This can be used to define some style Like in advanced curve setting!
    virtual void getInfo(map<string, string>&);

    //! Methods to access the data as a file used by pplot action routine
    virtual string path();

    //! Methods to access the data as a RasterData used by pimage action routine.
    // virtual RasterData& raster(const Transformation&) { throw MethodNotYetImplemented("Data<P>::raster"); }

    virtual void getInfo(const std::set<string>&, multimap<string, string>&);

    virtual bool check(const Transformation& transformation, UserPoint& point);

    //! Method to access the data as a list of points
    // needMissing : if true the list will contain all the points ( If they are outside the area: They will be flagged
    // missing)
    virtual void customisedPoints(const Transformation&, const std::set<string>&, CustomisedPointsList&, bool) = 0;

    //! Method to access the data as a list of points
    // needMissing : if true the list will contain all the points (If they are outside the area: They will be flagged
    // missing)
    virtual PointsHandler& points(const Transformation&, bool) = 0;

    virtual void customisedPoints(const AutomaticThinningMethod&, const Transformation& transformation,
                                  const std::set<string>& need, CustomisedPointsList& out);
    virtual void customisedPoints(const BasicThinningMethod& thinning, const Transformation& transformation,
                                  const std::set<string>& need, CustomisedPointsList& out);
    virtual void visit(TextVisitor&);
    virtual void visit(LegendVisitor&);
    virtual void visit(AnimationRules&);
    virtual void visit(AnimationStep&);
    virtual void visit(MetaDataVisitor&);
    virtual void visit(Layer& layer);
    bool valid();
    virtual void visit(MetaDataCollector& collector);
    virtual void visit(ValuesCollector&) {}
    virtual void visit(DataIndexCollector& dc);
    virtual void visit(MagnifierCollector& magnifier);
    virtual void initInfo();
    string legend();

    // Information needed fron layer management!
    virtual string layerId();
    virtual string name();
    virtual const DateTime& from();
    virtual const DateTime& to();
    virtual const DateDescription& timeStamp();
    virtual const LevelDescription& level();
    virtual string legendText(double, double);
    int dimension() const;
    void dimension(int dim);
    void index(int i);
    static int getUniqueOwnerId();

    virtual std::string getUnits() const;

    virtual void applyScaling(const std::string& target_units);
    virtual void defaultScaling(double&, double&);
    virtual void applyScaling(double, double);

protected:
    int dimension_;
    int index_;
    bool valid_;
    bool scaled_;
    int thinningFactor_;
    static int uniqueOwnerId_;  // Metview usage for overlay control

    DateDescription timeStamp_;
    LevelDescription dataLevel_;

    //! Method to print string about this class on to a stream of type ostream (virtual).
    virtual void print(ostream& out) const ;
    virtual void computeStats();

    AutoVector<PointsHandler> pointsHandlers_;
    // The objects are put in a list, they will be automatically destroyed
    AutoVector<MatrixHandler> matrixHandlers_;

    string legend_;

    string name_;
    string layerId_;
    DateTime from_;
    DateTime to_;
    map<string, vector<double> > stats_;
    vector<int> dataIndex_;


    BinningObject* binning_;

private:
    //! Copy constructor - No copy allowed
    Data(const Data&);
    //! Overloaded << operator to copy - No copy allowed
    Data& operator=(const Data&);

    // -- Friends
    //! Overloaded << operator to call print().
    friend ostream& operator<<(ostream& s, const Data& p) {
        p.print(s);
        return s;
    }
};


class DataLoop : public MetviewIcon {
public:
    DataLoop();
    virtual ~DataLoop();
    virtual void set(const map<string, string>&);
    virtual void set(const XmlNode&);
    virtual void set(LayerNode&);

    virtual void setToFirst();
    virtual Data* current() = 0;
    virtual bool hasMore()  = 0;
    virtual void next()     = 0;
    virtual void add(Data*);
    virtual string layerId();
    virtual string name();
    virtual void visit(Transformation&);
    void visit(Layer& layer);
};

class DataList : public DataLoop {
public:
    DataList();
    ~DataList();
    void setToFirst();
    Data* current();
    bool hasMore();
    void next();
    void add(Data*);

protected:
    vector<Data*>::iterator current_;
    vector<Data*> data_;
};
}  // namespace magics


#endif
