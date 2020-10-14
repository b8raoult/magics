
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file OdaXYDecoderAttributes.h
    \\brief Definition of OdaXYDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "OdaXYDecoderAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

OdaXYDecoderAttributes::OdaXYDecoderAttributes():
	path_(ParameterManager::getString("odb_filename")),
	x_(ParameterManager::getString("odb_x_variable")),
	y_(ParameterManager::getString("odb_y_variable")),
	value_(ParameterManager::getString("odb_value_variable")),
	y_component_(ParameterManager::getString("odb_y_component_variable")),
	x_component_(ParameterManager::getString("odb_x_component_variable")),
	nb_rows_(ParameterManager::getInt("odb_nb_rows")),
	title_(ParameterManager::getString("odb_user_title"))
	,
	odb_binning_(MagTranslator<string, BinningObject>().magics("odb_binning"))
	 
{
} 


OdaXYDecoderAttributes::~OdaXYDecoderAttributes()
{
	
}

    
void OdaXYDecoderAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "odb";
	
	setAttribute(prefix, "odb_filename", path_, params);
	setAttribute(prefix, "odb_x_variable", x_, params);
	setAttribute(prefix, "odb_y_variable", y_, params);
	setAttribute(prefix, "odb_value_variable", value_, params);
	setAttribute(prefix, "odb_y_component_variable", y_component_, params);
	setAttribute(prefix, "odb_x_component_variable", x_component_, params);
	setAttribute(prefix, "odb_nb_rows", nb_rows_, params);
	setAttribute(prefix, "odb_user_title", title_, params);
	
	setMember(prefix, "odb_binning", odb_binning_, params);
	
}

void OdaXYDecoderAttributes::copy(const OdaXYDecoderAttributes& other)
{
	path_ = other.path_;
	x_ = other.x_;
	y_ = other.y_;
	value_ = other.value_;
	y_component_ = other.y_component_;
	x_component_ = other.x_component_;
	nb_rows_ = other.nb_rows_;
	title_ = other.title_;
	odb_binning_ = unique_ptr<BinningObject>(other.odb_binning_->clone());
	
} 


bool OdaXYDecoderAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "odb")  )
		return true;
	if ( acceptNode(node, odb_binning_) )
		return true;
	
	return false;
}

void OdaXYDecoderAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "odb")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), odb_binning_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), odb_binning_, *elt); 
		
	}
}

void OdaXYDecoderAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	out << " x = " <<  x_;
	out << " y = " <<  y_;
	out << " value = " <<  value_;
	out << " y_component = " <<  y_component_;
	out << " x_component = " <<  x_component_;
	out << " nb_rows = " <<  nb_rows_;
	out << " title = " <<  title_;
	out << " odb_binning = " <<  *odb_binning_;
	
	out << "]" << "\n";
}

void OdaXYDecoderAttributes::toxml(ostream& out)  const
{
	out <<  "\"odb\""; 
	out << ", \"odb_filename\":";
	niceprint(out,path_);
	out << ", \"odb_x_variable\":";
	niceprint(out,x_);
	out << ", \"odb_y_variable\":";
	niceprint(out,y_);
	out << ", \"odb_value_variable\":";
	niceprint(out,value_);
	out << ", \"odb_y_component_variable\":";
	niceprint(out,y_component_);
	out << ", \"odb_x_component_variable\":";
	niceprint(out,x_component_);
	out << ", \"odb_nb_rows\":";
	niceprint(out,nb_rows_);
	out << ", \"odb_user_title\":";
	niceprint(out,title_);
	out << ", \"odb_binning\":";
	odb_binning_->toxml(out);
	
}

static MagicsParameter<string> odb_filename("odb_filename", "", "");
static MagicsParameter<string> odb_x_variable("odb_x_variable", "lat", "");
static MagicsParameter<string> odb_y_variable("odb_y_variable", "lon", "");
static MagicsParameter<string> odb_value_variable("odb_value_variable", "", "");
static MagicsParameter<string> odb_y_component_variable("odb_y_component_variable", "", "");
static MagicsParameter<string> odb_x_component_variable("odb_x_component_variable", "", "");
static MagicsParameter<int> odb_nb_rows("odb_nb_rows", -1, "");
static MagicsParameter<string> odb_user_title("odb_user_title", "", "");
static MagicsParameter<string> odb_binning("odb_binning", "off", ""); 
#include "BinningObject.h"
static SimpleObjectMaker<BinningObject , BinningObject> binning_BinningObject("binning");
static SimpleObjectMaker<BinningObject , BinningObject> on_BinningObject("on");
static SimpleObjectMaker<NoBinningObject , BinningObject> nobinning_NoBinningObject("nobinning");
static SimpleObjectMaker<NoBinningObject , BinningObject> off_NoBinningObject("off");
