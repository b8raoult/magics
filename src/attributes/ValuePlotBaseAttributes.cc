
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ValuePlotBaseAttributes.h
    \\brief Definition of ValuePlotBase Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "ValuePlotBaseAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

ValuePlotBaseAttributes::ValuePlotBaseAttributes()
	
	 
{
} 


ValuePlotBaseAttributes::~ValuePlotBaseAttributes()
{
	
}

    
void ValuePlotBaseAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	
	
}

void ValuePlotBaseAttributes::copy(const ValuePlotBaseAttributes& other)
{
	
} 


bool ValuePlotBaseAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void ValuePlotBaseAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void ValuePlotBaseAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	
	out << "]" << "\n";
}

void ValuePlotBaseAttributes::toxml(ostream& out)  const
{
	out <<  "\"\""; 
	
}

