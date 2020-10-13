
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file TaylorProjectionAttributes.h
    \\brief Definition of TaylorProjection Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "TaylorProjectionAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

TaylorProjectionAttributes::TaylorProjectionAttributes():
	min_(ParameterManager::getDouble("taylor_standard_deviation_min")),
	max_(ParameterManager::getDouble("taylor_standard_deviation_max"))
	
	
{
}


TaylorProjectionAttributes::~TaylorProjectionAttributes()
{

}


void TaylorProjectionAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(3);
	int i = 0;
	prefix[i++] = "taylor";
	prefix[i++] = "taylor";
	prefix[i++] = "taylor_standard_deviation";
	
	setAttribute(prefix, "taylor_standard_deviation_min", min_, params);
	setAttribute(prefix, "taylor_standard_deviation_max", max_, params);
	
	
}

void TaylorProjectionAttributes::copy(const TaylorProjectionAttributes& other)
{
	min_ = other.min_;
	max_ = other.max_;
	
}


bool TaylorProjectionAttributes::accept(const string& node)
{

	if ( magCompare(node, "taylor")  )
		return true;
	
	return false;
}

void TaylorProjectionAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "taylor")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void TaylorProjectionAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " min = " <<  min_;
	out << " max = " <<  max_;
	
	out << "]" << "\n";
}

void TaylorProjectionAttributes::toxml(ostream& out)  const
{
	out <<  "\"taylor\"";
	out << ", \"taylor_standard_deviation_min\":";
	niceprint(out,min_);
	out << ", \"taylor_standard_deviation_max\":";
	niceprint(out,max_);
	
}

static MagicsParameter<double> taylor_standard_deviation_min("taylor_standard_deviation_min", 0);
static MagicsParameter<double> taylor_standard_deviation_max("taylor_standard_deviation_max", 1);
