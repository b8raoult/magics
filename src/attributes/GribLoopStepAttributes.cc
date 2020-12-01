
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GribLoopStepAttributes.h
    \\brief Definition of GribLoopStep Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "GribLoopStepAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

GribLoopStepAttributes::GribLoopStepAttributes()
	
	 
{
} 


GribLoopStepAttributes::~GribLoopStepAttributes()
{
	
}

    
void GribLoopStepAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "grib";
	prefix[i++] = "grib_loop_step";
	
	
	
}

void GribLoopStepAttributes::copy(const GribLoopStepAttributes& other)
{
	
} 


bool GribLoopStepAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "loopondate")  )
		return true;
	
	return false;
}

void GribLoopStepAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "loopondate")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void GribLoopStepAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	
	out << "]" << "\n";
}

void GribLoopStepAttributes::toxml(ostream& out)  const
{
	out <<  "\"loopondate\""; 
	
}

