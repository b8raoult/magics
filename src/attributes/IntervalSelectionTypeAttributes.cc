
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file IntervalSelectionTypeAttributes.h
    \\brief Definition of IntervalSelectionType Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "IntervalSelectionTypeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

IntervalSelectionTypeAttributes::IntervalSelectionTypeAttributes():
	reference_(ParameterManager::getDouble("contour_reference_level")),
	interval_(ParameterManager::getDouble("contour_interval"))
	
	 
{
} 


IntervalSelectionTypeAttributes::~IntervalSelectionTypeAttributes()
{
	
}

    
void IntervalSelectionTypeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(3);
	int i = 0;
	prefix[i++] = "contour";
	prefix[i++] = "contour";
	prefix[i++] = "contour";
	
	setAttribute(prefix, "contour_reference_level", reference_, params);
	setAttribute(prefix, "contour_interval", interval_, params);
	
	
}

void IntervalSelectionTypeAttributes::copy(const IntervalSelectionTypeAttributes& other)
{
	reference_ = other.reference_;
	interval_ = other.interval_;
	
} 


bool IntervalSelectionTypeAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "interval")  )
		return true;
	
	return false;
}

void IntervalSelectionTypeAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "interval")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void IntervalSelectionTypeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " reference = " <<  reference_;
	out << " interval = " <<  interval_;
	
	out << "]" << "\n";
}

void IntervalSelectionTypeAttributes::toxml(ostream& out)  const
{
	out <<  "\"interval\""; 
	out << ", \"contour_reference_level\":";
	niceprint(out,reference_);
	out << ", \"contour_interval\":";
	niceprint(out,interval_);
	
}

static MagicsParameter<double> contour_reference_level("contour_reference_level", 0.0, "");
static MagicsParameter<double> contour_interval("contour_interval", 8.0, "");
