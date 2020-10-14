
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file NoBoxPlotMedianAttributes.h
    \\brief Definition of NoBoxPlotMedian Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "NoBoxPlotMedianAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

NoBoxPlotMedianAttributes::NoBoxPlotMedianAttributes()
	
	 
{
} 


NoBoxPlotMedianAttributes::~NoBoxPlotMedianAttributes()
{
	
}

    
void NoBoxPlotMedianAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "boxplot";
	prefix[i++] = "boxplot_median";
	
	
	
}

void NoBoxPlotMedianAttributes::copy(const NoBoxPlotMedianAttributes& other)
{
	
} 


bool NoBoxPlotMedianAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "median")  )
		return true;
	
	return false;
}

void NoBoxPlotMedianAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "median")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void NoBoxPlotMedianAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	
	out << "]" << "\n";
}

void NoBoxPlotMedianAttributes::toxml(ostream& out)  const
{
	out <<  "\"median\""; 
	
}

