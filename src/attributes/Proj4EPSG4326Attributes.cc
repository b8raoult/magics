
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4EPSG4326Attributes.h
    \\brief Definition of Proj4EPSG4326 Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "Proj4EPSG4326Attributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

Proj4EPSG4326Attributes::Proj4EPSG4326Attributes()
	
	 
{
} 


Proj4EPSG4326Attributes::~Proj4EPSG4326Attributes()
{
	
}

    
void Proj4EPSG4326Attributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "subpage";
	
	
	
}

void Proj4EPSG4326Attributes::copy(const Proj4EPSG4326Attributes& other)
{
	
} 


bool Proj4EPSG4326Attributes::accept(const string& node)
{	
	
	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void Proj4EPSG4326Attributes::set(const XmlNode& node)
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

void Proj4EPSG4326Attributes::print(ostream& out)  const
{
	out << "Attributes[";
	
	out << "]" << "\n";
}

void Proj4EPSG4326Attributes::toxml(ostream& out)  const
{
	out <<  "\"\""; 
	
}

