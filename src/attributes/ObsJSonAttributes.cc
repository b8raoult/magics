
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ObsJSonAttributes.h
    \\brief Definition of ObsJSon Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "ObsJSonAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

ObsJSonAttributes::ObsJSonAttributes():
	path_(ParameterManager::getString("obsjson_input_filename")),
	values_(ParameterManager::getStringArray("obsjson_info_list"))
	
	 
{
} 


ObsJSonAttributes::~ObsJSonAttributes()
{
	
}

    
void ObsJSonAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "obsjson";
	
	setAttribute(prefix, "obsjson_input_filename", path_, params);
	setAttribute(prefix, "obsjson_info_list", values_, params);
	
	
}

void ObsJSonAttributes::copy(const ObsJSonAttributes& other)
{
	path_ = other.path_;
	values_ = other.values_;
	
} 


bool ObsJSonAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "obsjson")  )
		return true;
	
	return false;
}

void ObsJSonAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "obsjson")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void ObsJSonAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	out << " values = " <<  values_;
	
	out << "]" << "\n";
}

void ObsJSonAttributes::toxml(ostream& out)  const
{
	out <<  "\"obsjson\""; 
	out << ", \"obsjson_input_filename\":";
	niceprint(out,path_);
	out << ", \"obsjson_info_list\":";
	niceprint(out,values_);
	
}

static MagicsParameter<string> obsjson_input_filename("obsjson_input_filename", "", "");
static MagicsParameter<stringarray> obsjson_info_list("obsjson_info_list", stringarray(), "");
