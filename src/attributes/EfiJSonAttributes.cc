
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EfiJSonAttributes.h
    \\brief Definition of EfiJSon Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "EfiJSonAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

EfiJSonAttributes::EfiJSonAttributes():
	path_(ParameterManager::getString("efijson_input_filename")),
	long_title_(ParameterManager::getBool("efi_long_title")),
	title_(ParameterManager::getBool("efi_title")),
	legend_(ParameterManager::getBool("efi_legend")),
	legend_colours_(ParameterManager::getStringArray("efi_legend_colour_list")),
	legend_type_(ParameterManager::getString("efi_legend_box_type")),
	legend_normal_thickness_(ParameterManager::getInt("efi_legend_normal_thickness"))
	,
	legend_normal_colour_(MagTranslator<string, Colour>().magics("efi_legend_normal_colour"))
	 
{
} 


EfiJSonAttributes::~EfiJSonAttributes()
{
	
}

    
void EfiJSonAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "efijson";
	
	setAttribute(prefix, "efijson_input_filename", path_, params);
	setAttribute(prefix, "efi_long_title", long_title_, params);
	setAttribute(prefix, "efi_title", title_, params);
	setAttribute(prefix, "efi_legend", legend_, params);
	setAttribute(prefix, "efi_legend_colour_list", legend_colours_, params);
	setAttribute(prefix, "efi_legend_box_type", legend_type_, params);
	setAttribute(prefix, "efi_legend_normal_thickness", legend_normal_thickness_, params);
	
	setMember(prefix, "efi_legend_normal_colour", legend_normal_colour_, params);
	
}

void EfiJSonAttributes::copy(const EfiJSonAttributes& other)
{
	path_ = other.path_;
	long_title_ = other.long_title_;
	title_ = other.title_;
	legend_ = other.legend_;
	legend_colours_ = other.legend_colours_;
	legend_type_ = other.legend_type_;
	legend_normal_thickness_ = other.legend_normal_thickness_;
	legend_normal_colour_ = unique_ptr<Colour>(other.legend_normal_colour_->clone());
	
} 


bool EfiJSonAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "efijson")  )
		return true;
	
	return false;
}

void EfiJSonAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "efijson")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void EfiJSonAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	out << " long_title = " <<  long_title_;
	out << " title = " <<  title_;
	out << " legend = " <<  legend_;
	out << " legend_colours = " <<  legend_colours_;
	out << " legend_type = " <<  legend_type_;
	out << " legend_normal_thickness = " <<  legend_normal_thickness_;
	out << " legend_normal_colour = " <<  *legend_normal_colour_;
	
	out << "]" << "\n";
}

void EfiJSonAttributes::toxml(ostream& out)  const
{
	out <<  "\"efijson\""; 
	out << ", \"efijson_input_filename\":";
	niceprint(out,path_);
	out << ", \"efi_long_title\":";
	niceprint(out,long_title_);
	out << ", \"efi_title\":";
	niceprint(out,title_);
	out << ", \"efi_legend\":";
	niceprint(out,legend_);
	out << ", \"efi_legend_colour_list\":";
	niceprint(out,legend_colours_);
	out << ", \"efi_legend_box_type\":";
	niceprint(out,legend_type_);
	out << ", \"efi_legend_normal_thickness\":";
	niceprint(out,legend_normal_thickness_);
	out << ", \"efi_legend_normal_colour\":";
	niceprint(out, *legend_normal_colour_);
	
}

static MagicsParameter<string> efijson_input_filename("efijson_input_filename", "", "");
static MagicsParameter<string> efi_long_title("efi_long_title", "off", "");
static MagicsParameter<string> efi_title("efi_title", "off", "");
static MagicsParameter<string> efi_legend("efi_legend", "on", "");
static MagicsParameter<stringarray> efi_legend_colour_list("efi_legend_colour_list", stringarray(), "");
static MagicsParameter<string> efi_legend_box_type("efi_legend_box_type", "both", "");
static MagicsParameter<int> efi_legend_normal_thickness("efi_legend_normal_thickness", 4, "");
static MagicsParameter<string> efi_legend_normal_colour("efi_legend_normal_colour", "black", ""); 
