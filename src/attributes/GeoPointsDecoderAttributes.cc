
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GeoPointsDecoderAttributes.h
    \\brief Definition of GeoPointsDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "GeoPointsDecoderAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

GeoPointsDecoderAttributes::GeoPointsDecoderAttributes():
	path_(ParameterManager::getString("geo_input_file_name")),
	missing_(ParameterManager::getDouble("geo_missing_value"))
	
	 
{
} 


GeoPointsDecoderAttributes::~GeoPointsDecoderAttributes()
{
	
}

    
void GeoPointsDecoderAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "geo";
	prefix[i++] = "geo_input";
	
	setAttribute(prefix, "geo_input_file_name", path_, params);
	setAttribute(prefix, "geo_missing_value", missing_, params);
	
	
}

void GeoPointsDecoderAttributes::copy(const GeoPointsDecoderAttributes& other)
{
	path_ = other.path_;
	missing_ = other.missing_;
	
} 


bool GeoPointsDecoderAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "geopoints")  )
		return true;
	
	return false;
}

void GeoPointsDecoderAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "geopoints")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void GeoPointsDecoderAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	out << " missing = " <<  missing_;
	
	out << "]" << "\n";
}

void GeoPointsDecoderAttributes::toxml(ostream& out)  const
{
	out <<  "\"geopoints\""; 
	out << ", \"geo_input_file_name\":";
	niceprint(out,path_);
	out << ", \"geo_missing_value\":";
	niceprint(out,missing_);
	
}

static MagicsParameter<string> geo_input_file_name("geo_input_file_name", "", "");
static MagicsParameter<double> geo_missing_value("geo_missing_value", 3.0E+38, "");
