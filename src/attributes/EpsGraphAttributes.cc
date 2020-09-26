
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EpsGraphAttributes.h
    \\brief Definition of EpsGraph Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "EpsGraphAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

EpsGraphAttributes::EpsGraphAttributes():
	font_(ParameterManager::getString("eps_font")),
	font_size_(ParameterManager::getDouble("eps_font_size")),
	font_style_(ParameterManager::getString("eps_font_style")),
	box_shift_(ParameterManager::getInt("eps_box_shift")),
	quantiles_colour_(ParameterManager::getStringArray("eps_box_quantiles_colour")),
	border_thickness_(ParameterManager::getInt("eps_box_border_thickness")),
	median_thickness_(ParameterManager::getInt("eps_box_median_thickness")),
	max_(ParameterManager::getDouble("eps_maximum")),
	max_font_name_(ParameterManager::getString("eps_maximum_font")),
	max_font_style_(ParameterManager::getString("eps_maximum_font_style")),
	max_font_size_(ParameterManager::getDouble("eps_maximum_font_size")),
	box_width_(ParameterManager::getDouble("eps_box_width")),
	whisker_(ParameterManager::getBool("eps_whisker")),
	legend_resolution_(ParameterManager::getString("eps_legend_resolution")),
	legend_control_text_(ParameterManager::getString("eps_legend_control_text")),
	legend_size_(ParameterManager::getDouble("eps_legend_font_size")),
	legend_forecast_text_(ParameterManager::getString("eps_legend_forecast_text")),
	deterministic_(ParameterManager::getBool("eps_deterministic")),
	deterministic_thickness_(ParameterManager::getInt("eps_deterministic_line_thickness")),
	deterministic_legend_(ParameterManager::getString("eps_deterministic_legend_text")),
	control_(ParameterManager::getBool("eps_control")),
	control_thickness_(ParameterManager::getInt("eps_control_line_thickness")),
	control_legend_(ParameterManager::getString("eps_control_legend_text")),
	legend_(ParameterManager::getBool("legend")),
	grey_legend_(ParameterManager::getBool("eps_grey_legend"))
	,
	font_colour_(MagTranslator<string, Colour>().magics("eps_font_colour")),
	colour_(MagTranslator<string, Colour>().magics("eps_box_colour")),
	right_colour_(MagTranslator<string, Colour>().magics("eps_right_box_colour")),
	left_colour_(MagTranslator<string, Colour>().magics("eps_left_box_colour")),
	border_colour_(MagTranslator<string, Colour>().magics("eps_box_border_colour")),
	median_colour_(MagTranslator<string, Colour>().magics("eps_box_median_colour")),
	max_font_colour_(MagTranslator<string, Colour>().magics("eps_maximum_font_colour")),
	deterministic_colour_(MagTranslator<string, Colour>().magics("eps_deterministic_line_colour")),
	deterministic_style_(MagTranslator<string, LineStyle>().magics("eps_deterministic_line_style")),
	control_colour_(MagTranslator<string, Colour>().magics("eps_control_line_colour")),
	control_style_(MagTranslator<string, LineStyle>().magics("eps_control_line_style"))
	 
{
} 


EpsGraphAttributes::~EpsGraphAttributes()
{
	
}

    
void EpsGraphAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "eps";
	
	setAttribute(prefix, "eps_font", font_, params);
	setAttribute(prefix, "eps_font_size", font_size_, params);
	setAttribute(prefix, "eps_font_style", font_style_, params);
	setAttribute(prefix, "eps_box_shift", box_shift_, params);
	setAttribute(prefix, "eps_box_quantiles_colour", quantiles_colour_, params);
	setAttribute(prefix, "eps_box_border_thickness", border_thickness_, params);
	setAttribute(prefix, "eps_box_median_thickness", median_thickness_, params);
	setAttribute(prefix, "eps_maximum", max_, params);
	setAttribute(prefix, "eps_maximum_font", max_font_name_, params);
	setAttribute(prefix, "eps_maximum_font_style", max_font_style_, params);
	setAttribute(prefix, "eps_maximum_font_size", max_font_size_, params);
	setAttribute(prefix, "eps_box_width", box_width_, params);
	setAttribute(prefix, "eps_whisker", whisker_, params);
	setAttribute(prefix, "eps_legend_resolution", legend_resolution_, params);
	setAttribute(prefix, "eps_legend_control_text", legend_control_text_, params);
	setAttribute(prefix, "eps_legend_font_size", legend_size_, params);
	setAttribute(prefix, "eps_legend_forecast_text", legend_forecast_text_, params);
	setAttribute(prefix, "eps_deterministic", deterministic_, params);
	setAttribute(prefix, "eps_deterministic_line_thickness", deterministic_thickness_, params);
	setAttribute(prefix, "eps_deterministic_legend_text", deterministic_legend_, params);
	setAttribute(prefix, "eps_control", control_, params);
	setAttribute(prefix, "eps_control_line_thickness", control_thickness_, params);
	setAttribute(prefix, "eps_control_legend_text", control_legend_, params);
	setAttribute(prefix, "legend", legend_, params);
	setAttribute(prefix, "eps_grey_legend", grey_legend_, params);
	
	setMember(prefix, "eps_font_colour", font_colour_, params);
	setMember(prefix, "eps_box_colour", colour_, params);
	setMember(prefix, "eps_right_box_colour", right_colour_, params);
	setMember(prefix, "eps_left_box_colour", left_colour_, params);
	setMember(prefix, "eps_box_border_colour", border_colour_, params);
	setMember(prefix, "eps_box_median_colour", median_colour_, params);
	setMember(prefix, "eps_maximum_font_colour", max_font_colour_, params);
	setMember(prefix, "eps_deterministic_line_colour", deterministic_colour_, params);
	setAttribute(prefix, "eps_deterministic_line_style", deterministic_style_, params);
	setMember(prefix, "eps_control_line_colour", control_colour_, params);
	setAttribute(prefix, "eps_control_line_style", control_style_, params);
	
}

void EpsGraphAttributes::copy(const EpsGraphAttributes& other)
{
	font_ = other.font_;
	font_size_ = other.font_size_;
	font_style_ = other.font_style_;
	box_shift_ = other.box_shift_;
	quantiles_colour_ = other.quantiles_colour_;
	border_thickness_ = other.border_thickness_;
	median_thickness_ = other.median_thickness_;
	max_ = other.max_;
	max_font_name_ = other.max_font_name_;
	max_font_style_ = other.max_font_style_;
	max_font_size_ = other.max_font_size_;
	box_width_ = other.box_width_;
	whisker_ = other.whisker_;
	legend_resolution_ = other.legend_resolution_;
	legend_control_text_ = other.legend_control_text_;
	legend_size_ = other.legend_size_;
	legend_forecast_text_ = other.legend_forecast_text_;
	deterministic_ = other.deterministic_;
	deterministic_thickness_ = other.deterministic_thickness_;
	deterministic_legend_ = other.deterministic_legend_;
	control_ = other.control_;
	control_thickness_ = other.control_thickness_;
	control_legend_ = other.control_legend_;
	legend_ = other.legend_;
	grey_legend_ = other.grey_legend_;
	font_colour_ = unique_ptr<Colour>(other.font_colour_->clone());
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	right_colour_ = unique_ptr<Colour>(other.right_colour_->clone());
	left_colour_ = unique_ptr<Colour>(other.left_colour_->clone());
	border_colour_ = unique_ptr<Colour>(other.border_colour_->clone());
	median_colour_ = unique_ptr<Colour>(other.median_colour_->clone());
	max_font_colour_ = unique_ptr<Colour>(other.max_font_colour_->clone());
	deterministic_colour_ = unique_ptr<Colour>(other.deterministic_colour_->clone());
	deterministic_style_ = other.deterministic_style_;
	control_colour_ = unique_ptr<Colour>(other.control_colour_->clone());
	control_style_ = other.control_style_;
	
} 


bool EpsGraphAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "epsgraph")  )
		return true;
	
	return false;
}

void EpsGraphAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "epsgraph")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void EpsGraphAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " font = " <<  font_;
	out << " font_size = " <<  font_size_;
	out << " font_style = " <<  font_style_;
	out << " box_shift = " <<  box_shift_;
	out << " quantiles_colour = " <<  quantiles_colour_;
	out << " border_thickness = " <<  border_thickness_;
	out << " median_thickness = " <<  median_thickness_;
	out << " max = " <<  max_;
	out << " max_font_name = " <<  max_font_name_;
	out << " max_font_style = " <<  max_font_style_;
	out << " max_font_size = " <<  max_font_size_;
	out << " box_width = " <<  box_width_;
	out << " whisker = " <<  whisker_;
	out << " legend_resolution = " <<  legend_resolution_;
	out << " legend_control_text = " <<  legend_control_text_;
	out << " legend_size = " <<  legend_size_;
	out << " legend_forecast_text = " <<  legend_forecast_text_;
	out << " deterministic = " <<  deterministic_;
	out << " deterministic_thickness = " <<  deterministic_thickness_;
	out << " deterministic_legend = " <<  deterministic_legend_;
	out << " control = " <<  control_;
	out << " control_thickness = " <<  control_thickness_;
	out << " control_legend = " <<  control_legend_;
	out << " legend = " <<  legend_;
	out << " grey_legend = " <<  grey_legend_;
	out << " font_colour = " <<  *font_colour_;
	out << " colour = " <<  *colour_;
	out << " right_colour = " <<  *right_colour_;
	out << " left_colour = " <<  *left_colour_;
	out << " border_colour = " <<  *border_colour_;
	out << " median_colour = " <<  *median_colour_;
	out << " max_font_colour = " <<  *max_font_colour_;
	out << " deterministic_colour = " <<  *deterministic_colour_;
	out << " deterministic_style = " <<  deterministic_style_;
	out << " control_colour = " <<  *control_colour_;
	out << " control_style = " <<  control_style_;
	
	out << "]" << "\n";
}

void EpsGraphAttributes::toxml(ostream& out)  const
{
	out <<  "\"epsgraph\""; 
	out << ", \"eps_font\":";
	niceprint(out,font_);
	out << ", \"eps_font_size\":";
	niceprint(out,font_size_);
	out << ", \"eps_font_style\":";
	niceprint(out,font_style_);
	out << ", \"eps_box_shift\":";
	niceprint(out,box_shift_);
	out << ", \"eps_box_quantiles_colour\":";
	niceprint(out,quantiles_colour_);
	out << ", \"eps_box_border_thickness\":";
	niceprint(out,border_thickness_);
	out << ", \"eps_box_median_thickness\":";
	niceprint(out,median_thickness_);
	out << ", \"eps_maximum\":";
	niceprint(out,max_);
	out << ", \"eps_maximum_font\":";
	niceprint(out,max_font_name_);
	out << ", \"eps_maximum_font_style\":";
	niceprint(out,max_font_style_);
	out << ", \"eps_maximum_font_size\":";
	niceprint(out,max_font_size_);
	out << ", \"eps_box_width\":";
	niceprint(out,box_width_);
	out << ", \"eps_whisker\":";
	niceprint(out,whisker_);
	out << ", \"eps_legend_resolution\":";
	niceprint(out,legend_resolution_);
	out << ", \"eps_legend_control_text\":";
	niceprint(out,legend_control_text_);
	out << ", \"eps_legend_font_size\":";
	niceprint(out,legend_size_);
	out << ", \"eps_legend_forecast_text\":";
	niceprint(out,legend_forecast_text_);
	out << ", \"eps_deterministic\":";
	niceprint(out,deterministic_);
	out << ", \"eps_deterministic_line_thickness\":";
	niceprint(out,deterministic_thickness_);
	out << ", \"eps_deterministic_legend_text\":";
	niceprint(out,deterministic_legend_);
	out << ", \"eps_control\":";
	niceprint(out,control_);
	out << ", \"eps_control_line_thickness\":";
	niceprint(out,control_thickness_);
	out << ", \"eps_control_legend_text\":";
	niceprint(out,control_legend_);
	out << ", \"legend\":";
	niceprint(out,legend_);
	out << ", \"eps_grey_legend\":";
	niceprint(out,grey_legend_);
	out << ", \"eps_font_colour\":";
	niceprint(out, *font_colour_);
	out << ", \"eps_box_colour\":";
	niceprint(out, *colour_);
	out << ", \"eps_right_box_colour\":";
	niceprint(out, *right_colour_);
	out << ", \"eps_left_box_colour\":";
	niceprint(out, *left_colour_);
	out << ", \"eps_box_border_colour\":";
	niceprint(out, *border_colour_);
	out << ", \"eps_box_median_colour\":";
	niceprint(out, *median_colour_);
	out << ", \"eps_maximum_font_colour\":";
	niceprint(out, *max_font_colour_);
	out << ", \"eps_deterministic_line_colour\":";
	niceprint(out, *deterministic_colour_);
	out << ", \"eps_deterministic_line_style\":";
	niceprint(out, deterministic_style_);
	out << ", \"eps_control_line_colour\":";
	niceprint(out, *control_colour_);
	out << ", \"eps_control_line_style\":";
	niceprint(out, control_style_);
	
}

static MagicsParameter<string> eps_font("eps_font", "sansserif", "");
static MagicsParameter<double> eps_font_size("eps_font_size", 0.25, "");
static MagicsParameter<string> eps_font_style("eps_font_style", "", "");
static MagicsParameter<int> eps_box_shift("eps_box_shift", 0, "");
static MagicsParameter<stringarray> eps_box_quantiles_colour("eps_box_quantiles_colour", stringarray(), "");
static MagicsParameter<int> eps_box_border_thickness("eps_box_border_thickness", 3, "");
static MagicsParameter<int> eps_box_median_thickness("eps_box_median_thickness", 3, "");
static MagicsParameter<double> eps_maximum("eps_maximum", INT_MAX, "");
static MagicsParameter<string> eps_maximum_font("eps_maximum_font", "sansserif", "");
static MagicsParameter<string> eps_maximum_font_style("eps_maximum_font_style", "normal", "");
static MagicsParameter<double> eps_maximum_font_size("eps_maximum_font_size", 0.25, "");
static MagicsParameter<double> eps_box_width("eps_box_width", -1, "");
static MagicsParameter<string> eps_whisker("eps_whisker", "on", "");
static MagicsParameter<string> eps_legend_resolution("eps_legend_resolution", "truncature", "");
static MagicsParameter<string> eps_legend_control_text("eps_legend_control_text", "", "");
static MagicsParameter<double> eps_legend_font_size("eps_legend_font_size", 0.3, "");
static MagicsParameter<string> eps_legend_forecast_text("eps_legend_forecast_text", "", "");
static MagicsParameter<string> eps_deterministic("eps_deterministic", "on", "");
static MagicsParameter<int> eps_deterministic_line_thickness("eps_deterministic_line_thickness", 2, "");
static MagicsParameter<string> eps_deterministic_legend_text("eps_deterministic_legend_text", "High Resolution", "");
static MagicsParameter<string> eps_control("eps_control", "on", "");
static MagicsParameter<int> eps_control_line_thickness("eps_control_line_thickness", 2, "");
static MagicsParameter<string> eps_control_legend_text("eps_control_legend_text", "ENS Control", "");
static MagicsParameter<string> legend("legend", "on", "");
static MagicsParameter<string> eps_grey_legend("eps_grey_legend", "on", "");
static MagicsParameter<string> eps_font_colour("eps_font_colour", "blue", ""); 
static MagicsParameter<string> eps_box_colour("eps_box_colour", "cyan", ""); 
static MagicsParameter<string> eps_right_box_colour("eps_right_box_colour", "red", ""); 
static MagicsParameter<string> eps_left_box_colour("eps_left_box_colour", "blue", ""); 
static MagicsParameter<string> eps_box_border_colour("eps_box_border_colour", "black", ""); 
static MagicsParameter<string> eps_box_median_colour("eps_box_median_colour", "black", ""); 
static MagicsParameter<string> eps_maximum_font_colour("eps_maximum_font_colour", "red", ""); 
static MagicsParameter<string> eps_deterministic_line_colour("eps_deterministic_line_colour", "blue", ""); 
static MagicsParameter<string> eps_deterministic_line_style("eps_deterministic_line_style", "solid", ""); 
static MagicsParameter<string> eps_control_line_colour("eps_control_line_colour", "red", ""); 
static MagicsParameter<string> eps_control_line_style("eps_control_line_style", "dash", ""); 
