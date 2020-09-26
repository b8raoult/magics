
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EpsShadeAttributes.h
    \\brief Definition of EpsShade Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "EpsShadeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

EpsShadeAttributes::EpsShadeAttributes():
	line_thickness_(ParameterManager::getInt("eps_shade_line_thickness"))
	,
	colour_(MagTranslator<string, Colour>().magics("eps_shade_colour")),
	line_colour_(MagTranslator<string, Colour>().magics("eps_shade_line_colour")),
	line_style_(MagTranslator<string, LineStyle>().magics("eps_shade_line_style"))
	 
{
} 


EpsShadeAttributes::~EpsShadeAttributes()
{
	
}

    
void EpsShadeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "eps";
	
	setAttribute(prefix, "eps_shade_line_thickness", line_thickness_, params);
	
	setMember(prefix, "eps_shade_colour", colour_, params);
	setMember(prefix, "eps_shade_line_colour", line_colour_, params);
	setAttribute(prefix, "eps_shade_line_style", line_style_, params);
	
}

void EpsShadeAttributes::copy(const EpsShadeAttributes& other)
{
	line_thickness_ = other.line_thickness_;
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	line_colour_ = unique_ptr<Colour>(other.line_colour_->clone());
	line_style_ = other.line_style_;
	
} 


bool EpsShadeAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "epsshade")  )
		return true;
	
	return false;
}

void EpsShadeAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "epsshade")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void EpsShadeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " line_thickness = " <<  line_thickness_;
	out << " colour = " <<  *colour_;
	out << " line_colour = " <<  *line_colour_;
	out << " line_style = " <<  line_style_;
	
	out << "]" << "\n";
}

void EpsShadeAttributes::toxml(ostream& out)  const
{
	out <<  "\"epsshade\""; 
	out << ", \"eps_shade_line_thickness\":";
	niceprint(out,line_thickness_);
	out << ", \"eps_shade_colour\":";
	niceprint(out, *colour_);
	out << ", \"eps_shade_line_colour\":";
	niceprint(out, *line_colour_);
	out << ", \"eps_shade_line_style\":";
	niceprint(out, line_style_);
	
}

static MagicsParameter<int> eps_shade_line_thickness("eps_shade_line_thickness", 1, "");
static MagicsParameter<string> eps_shade_colour("eps_shade_colour", "red", ""); 
static MagicsParameter<string> eps_shade_line_colour("eps_shade_line_colour", "red", ""); 
static MagicsParameter<string> eps_shade_line_style("eps_shade_line_style", "solid", ""); 
