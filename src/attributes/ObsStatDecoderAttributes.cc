
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ObsStatDecoderAttributes.h
    \\brief Definition of ObsStatDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "ObsStatDecoderAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

ObsStatDecoderAttributes::ObsStatDecoderAttributes():
	path_(ParameterManager::getString("obsstat_filename"))
	
	
{
}


ObsStatDecoderAttributes::~ObsStatDecoderAttributes()
{

}


void ObsStatDecoderAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	setAttribute(prefix, "obsstat_filename", path_, params);
	
	
}

void ObsStatDecoderAttributes::copy(const ObsStatDecoderAttributes& other)
{
	path_ = other.path_;
	
}


bool ObsStatDecoderAttributes::accept(const string& node)
{

	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void ObsStatDecoderAttributes::set(const XmlNode& node)
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

void ObsStatDecoderAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	
	out << "]" << "\n";
}

void ObsStatDecoderAttributes::toxml(ostream& out)  const
{
	out <<  "\"\"";
	out << ", \"obsstat_filename\":";
	niceprint(out,path_);
	
}

static MagicsParameter<string> obsstat_filename("obsstat_filename", "");
