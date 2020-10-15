/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file BaseParameter.cc
    \brief Definition of Parameter base class.

    Magics Team - ECMWF 2004

    Started: Jan 2004

    Changes:

*/


#include "BaseParameter.h"
#include "ParameterManager.h"

using namespace magics;


BaseParameter::BaseParameter(const string& name) : name_(name) {
    ParameterManager::add(name_, this);
}


BaseParameter::~BaseParameter() {}

void BaseParameter::set(const double& value) {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::get(double& value) const {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::set(const bool& value) {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::get(bool& value) const {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::set(const magvector<double>& values) {
    // See first if we can accept ints instead

    magvector<int> int_values;
    if (type() == getType(int_values)) {
        bool ok = true;

        for (auto v : values) {
            if (int(v) == v) {
                int_values.push_back(v);
            }
            else {
                ok = false;
            }
        }

        if (ok) {
            try {
                set(int_values);
                return;
            }
            catch (MistmatchType&) {
                // Throw the original mismatch error
            }
        }
    }

    throw MistmatchType(name_, getType(values), type());
}

void BaseParameter::get(magvector<double>& values) const {
    throw MistmatchType(name_, getType(values), type());
}

void BaseParameter::set(const int& value) {
    // See first if we can accept double instead
    double double_value = value;
    if (type() == getType(double_value)) {
        try {
            set(double(value));
            return;
        }
        catch (MistmatchType&) {
            // Throw the original mismatch error
        }
    }

    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::get(int& value) const {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::set(const magvector<int>& values) {
    // See first if we can accept double instead

    magvector<double> double_values;
    if (type() == getType(double_values)) {
        for (auto v : values) {
            double_values.push_back(v);
        }

        try {
            set(double_values);
            return;
        }
        catch (MistmatchType&) {
            // Throw the original mismatch error
        }
    }

    throw MistmatchType(name_, getType(values), type());
}

void BaseParameter::get(magvector<int>& value) const {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::set(const magvector<long>& value) {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::get(magvector<long>& value) const {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::set(const string& value) {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::set(const char* s) {
    set(std::string(s));
}

void BaseParameter::get(string& value) const {
    throw MistmatchType(name_, "string", type());
}

void BaseParameter::set(const magvector<string>& value) {
    throw MistmatchType(name_, "stringarray", type());
}


void BaseParameter::get(magvector<string>& value) const {
    throw MistmatchType(name_, "stringarray", type());
}

void BaseParameter::set(const LineStyle& value) {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::get(LineStyle& value) const {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::set(const DisplayType& value) {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::get(DisplayType& value) const {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::set(const Justification& value) {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::get(Justification& value) const {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::set(const ListPolicy& value) {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::get(ListPolicy& value) const {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::set(const AxisAutomaticSetting& value) {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::get(AxisAutomaticSetting& value) const {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::set(const ArrowPosition& value) {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::get(ArrowPosition& value) const {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::set(const Matrix& value) {
    throw MistmatchType(name_, getType(value), type());
}

void BaseParameter::get(Matrix& value) const {
    throw MistmatchType(name_, getType(value), type());
}

string BaseParameter::getType(const string&) const {
    return "string";
}

string BaseParameter::getType(const int&) const {
    return "integer";
}

string BaseParameter::getType(const double&) const {
    return "real";
}

string BaseParameter::getType(const magvector<string>&) const {
    return "array of string";
}

string BaseParameter::getType(const magvector<int>&) const {
    return "array of integer";
}

string BaseParameter::getType(const magvector<long>&) const {
    return "array of long integer";
}

string BaseParameter::getType(const magvector<double>&) const {
    return "array of real";
}

string BaseParameter::getType(const LineStyle&) const {
    return "LineStyle";
}

string BaseParameter::getType(const AxisAutomaticSetting&) const {
    return "AxisAutomaticSetting";
}

string BaseParameter::getType(const Justification&) const {
    return "Justification";
}

string BaseParameter::getType(const ArrowPosition&) const {
    return "ArrowPosition";
}

string BaseParameter::getType(const Matrix&) const {
    return "2DMatrix";
}

string BaseParameter::getType(const DisplayType &) const {
    return "DisplayType";
}

string BaseParameter::getType(const ListPolicy &) const {
    return "ListPolicy";
}

void BaseParameter::print(ostream& out) const {
    out << name_ << "[]";
}

MistmatchType::MistmatchType(const string& name, const string& type, const string& wait) :
    MagicsException("Parameter '" + name + "': type mismatch -> type received '" + type + "', expected type '" + wait +
                    "'") {}
