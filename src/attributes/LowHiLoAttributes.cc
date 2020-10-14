
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LowHiLoAttributes.h
    \\brief Definition of LowHiLo Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "LowHiLoAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

LowHiLoAttributes::LowHiLoAttributes()
	
	 
{
} 


LowHiLoAttributes::~LowHiLoAttributes()
{
	
}

    
void LowHiLoAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	
	
}

void LowHiLoAttributes::copy(const LowHiLoAttributes& other)
{
	
} 


bool LowHiLoAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "low")  )
		return true;
	
	return false;
}

void LowHiLoAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "low")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void LowHiLoAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	
	out << "]" << "\n";
}

void LowHiLoAttributes::toxml(ostream& out)  const
{
	out <<  "\"low\""; 
	
}

