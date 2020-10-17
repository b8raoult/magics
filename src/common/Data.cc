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


#include "Data.h"
#include "Units.h"

int Data::uniqueOwnerId_ = 0;

Data::Data() : dimension_(1), valid_(true), thinningFactor_(1), name_("no_name"), binning_(0), scaled_(false) {}

Data::~Data() {
    delete binning_;
}

MatrixHandler& Data::matrix() {
    throw MethodNotYetImplemented("Data::matrix");
}

MatrixHandler& Data::matrix(const Transformation&) {
    throw MethodNotYetImplemented("Data::matrix");
}

MatrixHandler& Data::norm() {
    throw MethodNotYetImplemented("Data::norm");
}

MatrixHandler& Data::direction() {
    throw MethodNotYetImplemented("Data::norm");
}

void Data::binning(BinningObject* binning) {
    binning_ = binning;
}

Data* Data::current() {
    return this;
}

Data* Data::next() {
    return 0;
}

void Data::release() {}

void Data::getReady(const Transformation&) {}

void Data::visit(Transformation&) {}

void Data::getInfo(map<string, string>&) {}

string Data::path() {
    throw DataInMemory();
}

void Data::getInfo(const std::set<string>&, multimap<string, string>&) {
    throw MethodNotYetImplemented("Data::getInfo");
}

bool Data::check(const Transformation& transformation, UserPoint& point) {
    bool c = transformation.in(point);
    if (!c)
        point.flagMissing();
    return c;
}

void Data::customisedPoints(const AutomaticThinningMethod&, const Transformation& transformation,
                            const std::set<string>& need, CustomisedPointsList& out) {
    customisedPoints(transformation, need, out, false);
}

void Data::customisedPoints(const BasicThinningMethod& thinning, const Transformation& transformation,
                            const std::set<string>& need, CustomisedPointsList& out) {
    thinningFactor_ = thinning.factor();
    customisedPoints(transformation, need, out, false);
}

void Data::visit(TextVisitor&) {}

void Data::visit(LegendVisitor&) {}

void Data::visit(AnimationRules&) {}

void Data::visit(AnimationStep&) {}

void Data::visit(MetaDataVisitor&) {}

void Data::visit(Layer& layer) {
    MetviewIcon::visit(layer);
    layer.name(name());
    layer.validTime(from(), to());
}

bool Data::valid() {
    return valid_;
}

void Data::visit(MetaDataCollector& collector) {
    MetviewIcon::visit(collector);
}

void Data::visit(DataIndexCollector& dc) {
    dc.setDataIndex(dataIndex_);
}

void Data::visit(MagnifierCollector& magnifier) {
    const Transformation& transformation = magnifier.transformation();
    PointsHandler& list                  = this->points(transformation, true);

    list.setToFirst();
    while (list.more()) {
        magnifier.push_back(transformation(list.current()));
        list.advance();
    }
}

void Data::initInfo() {
    MetviewIcon::initInfo();
}

string Data::legend() {
    return legend_;
}

string Data::layerId() {
    return (layerId_.empty()) ? iconName_ + "/ " + iconClass_ : layerId_;
}

string Data::name() {
    return (iconName_.empty()) ? name_ : iconName_;
}

const DateTime& Data::from() {
    return from_;
}

const DateTime& Data::to() {
    return to_;
}

const DateDescription& Data::timeStamp() {
    return timeStamp_;
}

const LevelDescription& Data::level() {
    return dataLevel_;
}

string Data::legendText(double, double) {
    return string();
}

int Data::dimension() const {
    return dimension_;
}

void Data::dimension(int dim) {
    dimension_ = dim;
}

void Data::index(int i) {
    index_ = i;
}

int Data::getUniqueOwnerId() {
    uniqueOwnerId_++;
    return uniqueOwnerId_;
}

void Data::print(ostream& out) const {
    out << "Data<P>";
}


void Data::computeStats() {
    map<string, vector<double> >::iterator itX, itY, itV;
    itX = stats_.find("x");
    itY = stats_.find("y");
    itV = stats_.find("value");

    // X and Y for scatterplots
    if (info("statsType") == "scatter" && itX != stats_.end() && itY != stats_.end()) {
        DataStats stX(itX->second);
        DataStats stY(itY->second);

        std::map<string, DataStats*> st;
        st["_x"] = &stX;
        st["_y"] = &stY;

        for (std::map<string, DataStats*>::iterator it = st.begin(); it != st.end(); it++) {
            setInfo("stats::points" + it->first, tostring(it->second->num()));
            setInfo("stats::min" + it->first, tostring(it->second->min()));
            setInfo("stats::max" + it->first, tostring(it->second->max()));
            setInfo("stats::avg" + it->first, tostring(it->second->mean()));
            if (it->second->hasStDev())
                setInfo("stats::stdev" + it->first, tostring(it->second->stDev()));
            else
                setInfo("stats::stdev" + it->first, "-");
        }

        setInfo("stats::correlation", tostring(DataStats::correlation(itX->second, itY->second, stX, stY)));
    }

    else if (info("statsType") == "vector" && itX != stats_.end() && itY != stats_.end()) {
        DataStats stX(itX->second);
        DataStats stY(itY->second);

        std::map<string, DataStats*> st;
        st["_x"] = &stX;
        st["_y"] = &stY;

        for (std::map<string, DataStats*>::iterator it = st.begin(); it != st.end(); it++) {
            setInfo("stats::points" + it->first, tostring(it->second->num()));
            setInfo("stats::min" + it->first, tostring(it->second->min()));
            setInfo("stats::max" + it->first, tostring(it->second->max()));
            setInfo("stats::avg" + it->first, tostring(it->second->mean()));
            setInfo("stats::stdev" + it->first, "-");
            setInfo("stats::skewness" + it->first, "-");
            setInfo("stats::kurtosis" + it->first, "-");

            if (it->second->hasStDev()) {
                setInfo("stats::stdev" + it->first, tostring(it->second->stDev()));
                if (it->second->hasThirdMoment()) {
                    setInfo("stats::skewness" + it->first, tostring(it->second->skewness()));
                    setInfo("stats::kurtosis" + it->first, tostring(it->second->kurtosis()));
                }
            }
        }
    }

    // Value
    if (itV != stats_.end()) {
        if (itV->second.size() == 0) {
            setInfo("stats::min", "");
            setInfo("stats::max", "");
            setInfo("stats::avg", "");
            setInfo("stats::points", "");
            return;
        }

        DataStats st(itV->second);
        setInfo("stats::points", tostring(st.num()));
        setInfo("stats::min", tostring(st.min()));
        setInfo("stats::max", tostring(st.max()));
        setInfo("stats::avg", tostring(st.mean()));
        setInfo("stats::stdev", "-");
        setInfo("stats::skewness", "-");
        setInfo("stats::kurtosis", "-");

        if (st.hasStDev()) {
            setInfo("stats::stdev", tostring(st.stDev()));
            if (st.hasThirdMoment()) {
                setInfo("stats::skewness", tostring(st.skewness()));
                setInfo("stats::kurtosis", tostring(st.kurtosis()));
            }
        }
    }

    stats_.clear();
}

std::string Data::getUnits() const {
    NOTIMP;
}


void Data::applyScaling(const std::string& target_units) {
    ASSERT(!scaled_);
    scaled_ = true;

    double scaling = 1;
    double offset  = 0;

    if (target_units.empty()) {
        // Not asked by user or contour
        defaultScaling(scaling, offset);
        if (scaling != 1 || offset != 0) {
            applyScaling(scaling, offset);
        }
    }

    std::string data_units = getUnits();

    if (!Units::convert(data_units, target_units, scaling, offset)) {
        return;
    }

    if (scaling != 1 || offset != 0) {
        applyScaling(scaling, offset);
    }
}


void Data::defaultScaling(double& scaling, double& offset) {
    scaling = 1;
    offset  = 0;
}


void Data::applyScaling(double scaling, double offset) {
    NOTIMP;
}


DataList::DataList() {
    current_ = data_.begin();
}
DataList::~DataList() {}

void DataList::setToFirst() {
    current_ = data_.begin();
}

Data* DataList::current() {
    return *current_;
}

bool DataList::hasMore() {
    return (current_ != data_.end());
}

void DataList::next() {
    ++current_;
}

void DataList::add(Data* data) {
    data_.push_back(data);
}

DataLoop::DataLoop() {}

DataLoop::~DataLoop() {}

void DataLoop::set(const map<string, string>&) {}

void DataLoop::set(const XmlNode&) {}

void DataLoop::set(LayerNode&) {}

void DataLoop::setToFirst() {}

void DataLoop::add(Data*) {}

string DataLoop::layerId() {
    return iconName_ + "/ " + iconClass_;
}

string DataLoop::name() {
    return iconName_;
}

void DataLoop::visit(Transformation&) {}

void DataLoop::visit(Layer& layer) {
    MetviewIcon::visit(layer);
}

DataInMemory::DataInMemory() : MagicsException("Data in Memory...") {}
