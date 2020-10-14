
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ShapeDecoderAttributes.h
    \\brief Definition of ShapeDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "ShapeDecoderAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

ShapeDecoderAttributes::ShapeDecoderAttributes():
	path_(ParameterManager::getString("shape_input_file_name"))
	
	
{
}


ShapeDecoderAttributes::~ShapeDecoderAttributes()
{

}


void ShapeDecoderAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "shape";
	
	setAttribute(prefix, "shape_input_file_name", path_, params);
	
	
}

void ShapeDecoderAttributes::copy(const ShapeDecoderAttributes& other)
{
	path_ = other.path_;
	
}


bool ShapeDecoderAttributes::accept(const string& node)
{

	if ( magCompare(node, "shape")  )
		return true;
	
	return false;
}

void ShapeDecoderAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "shape")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void ShapeDecoderAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	
	out << "]" << "\n";
}

void ShapeDecoderAttributes::toxml(ostream& out)  const
{
	out <<  "\"shape\"";
	out << ", \"shape_input_file_name\":";
	niceprint(out,path_);
	
}

static MagicsParameter<string> shape_input_file_name("shape_input_file_name", "");
