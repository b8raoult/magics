
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LandgramDecoderAttributes.h
    \\brief Definition of LandgramDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "LandgramDecoderAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

LandgramDecoderAttributes::LandgramDecoderAttributes():
	path_(ParameterManager::getString("landgram_input_file_name")),
	scaling_(ParameterManager::getDouble("landgram_input_scaling_factor")),
	offset_(ParameterManager::getDouble("landgram_input_offset_factor")),
	title_(ParameterManager::getString("landgram_title"))
	
	
{
}


LandgramDecoderAttributes::~LandgramDecoderAttributes()
{

}


void LandgramDecoderAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "landgram";
	
	setAttribute(prefix, "landgram_input_file_name", path_, params);
	setAttribute(prefix, "landgram_input_scaling_factor", scaling_, params);
	setAttribute(prefix, "landgram_input_offset_factor", offset_, params);
	setAttribute(prefix, "landgram_title", title_, params);
	
	
}

void LandgramDecoderAttributes::copy(const LandgramDecoderAttributes& other)
{
	path_ = other.path_;
	scaling_ = other.scaling_;
	offset_ = other.offset_;
	title_ = other.title_;
	
}


bool LandgramDecoderAttributes::accept(const string& node)
{

	if ( magCompare(node, "landgram")  )
		return true;
	
	return false;
}

void LandgramDecoderAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "landgram")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void LandgramDecoderAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	out << " scaling = " <<  scaling_;
	out << " offset = " <<  offset_;
	out << " title = " <<  title_;
	
	out << "]" << "\n";
}

void LandgramDecoderAttributes::toxml(ostream& out)  const
{
	out <<  "\"landgram\"";
	out << ", \"landgram_input_file_name\":";
	niceprint(out,path_);
	out << ", \"landgram_input_scaling_factor\":";
	niceprint(out,scaling_);
	out << ", \"landgram_input_offset_factor\":";
	niceprint(out,offset_);
	out << ", \"landgram_title\":";
	niceprint(out,title_);
	
}

static MagicsParameter<string> landgram_input_file_name("landgram_input_file_name", "");
static MagicsParameter<double> landgram_input_scaling_factor("landgram_input_scaling_factor", 1);
static MagicsParameter<double> landgram_input_offset_factor("landgram_input_offset_factor", 0);
static MagicsParameter<string> landgram_title("landgram_title", "landgram parameter");
