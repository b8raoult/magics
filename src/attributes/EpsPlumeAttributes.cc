
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EpsPlumeAttributes.h
    \\brief Definition of EpsPlume Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "EpsPlumeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

EpsPlumeAttributes::EpsPlumeAttributes():
	method_(ParameterManager::getString("eps_plume_method")),
	legend_(ParameterManager::getBool("eps_plume_legend")),
	line_(ParameterManager::getBool("eps_plume_members")),
	line_thickness_(ParameterManager::getInt("eps_plume_line_thickness")),
	forecast_(ParameterManager::getBool("eps_plume_forecast")),
	forecast_line_thickness_(ParameterManager::getInt("eps_plume_forecast_line_thickness")),
	control_(ParameterManager::getBool("eps_plume_control")),
	control_line_thickness_(ParameterManager::getInt("eps_plume_control_line_thickness")),
	median_(ParameterManager::getBool("eps_plume_median")),
	median_line_thickness_(ParameterManager::getInt("eps_plume_median_line_thickness")),
	shading_(ParameterManager::getBool("eps_plume_shading")),
	shading_levels_(ParameterManager::getDoubleArray("eps_plume_shading_level_list")),
	shading_colours_(ParameterManager::getStringArray("eps_plume_shading_colour_list"))
	,
	line_colour_(MagTranslator<string, Colour>().magics("eps_plume_line_colour")),
	line_style_(MagTranslator<string, LineStyle>().magics("eps_plume_line_style")),
	forecast_line_colour_(MagTranslator<string, Colour>().magics("eps_plume_forecast_line_colour")),
	forecast_line_style_(MagTranslator<string, LineStyle>().magics("eps_plume_forecast_line_style")),
	control_line_colour_(MagTranslator<string, Colour>().magics("eps_plume_control_line_colour")),
	control_line_style_(MagTranslator<string, LineStyle>().magics("eps_plume_control_line_style")),
	median_line_colour_(MagTranslator<string, Colour>().magics("eps_plume_median_line_colour")),
	median_line_style_(MagTranslator<string, LineStyle>().magics("eps_plume_median_line_style"))
	
{
}


EpsPlumeAttributes::~EpsPlumeAttributes()
{

}


void EpsPlumeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "eps";
	prefix[i++] = "eps_plume";
	
	setAttribute(prefix, "eps_plume_method", method_, params);
	setAttribute(prefix, "eps_plume_legend", legend_, params);
	setAttribute(prefix, "eps_plume_members", line_, params);
	setAttribute(prefix, "eps_plume_line_thickness", line_thickness_, params);
	setAttribute(prefix, "eps_plume_forecast", forecast_, params);
	setAttribute(prefix, "eps_plume_forecast_line_thickness", forecast_line_thickness_, params);
	setAttribute(prefix, "eps_plume_control", control_, params);
	setAttribute(prefix, "eps_plume_control_line_thickness", control_line_thickness_, params);
	setAttribute(prefix, "eps_plume_median", median_, params);
	setAttribute(prefix, "eps_plume_median_line_thickness", median_line_thickness_, params);
	setAttribute(prefix, "eps_plume_shading", shading_, params);
	setAttribute(prefix, "eps_plume_shading_level_list", shading_levels_, params);
	setAttribute(prefix, "eps_plume_shading_colour_list", shading_colours_, params);
	
	setMember(prefix, "eps_plume_line_colour", line_colour_, params);
	setAttribute(prefix, "eps_plume_line_style", line_style_, params);
	setMember(prefix, "eps_plume_forecast_line_colour", forecast_line_colour_, params);
	setAttribute(prefix, "eps_plume_forecast_line_style", forecast_line_style_, params);
	setMember(prefix, "eps_plume_control_line_colour", control_line_colour_, params);
	setAttribute(prefix, "eps_plume_control_line_style", control_line_style_, params);
	setMember(prefix, "eps_plume_median_line_colour", median_line_colour_, params);
	setAttribute(prefix, "eps_plume_median_line_style", median_line_style_, params);
	
}

void EpsPlumeAttributes::copy(const EpsPlumeAttributes& other)
{
	method_ = other.method_;
	legend_ = other.legend_;
	line_ = other.line_;
	line_thickness_ = other.line_thickness_;
	forecast_ = other.forecast_;
	forecast_line_thickness_ = other.forecast_line_thickness_;
	control_ = other.control_;
	control_line_thickness_ = other.control_line_thickness_;
	median_ = other.median_;
	median_line_thickness_ = other.median_line_thickness_;
	shading_ = other.shading_;
	shading_levels_ = other.shading_levels_;
	shading_colours_ = other.shading_colours_;
	line_colour_ = unique_ptr<Colour>(other.line_colour_->clone());
	line_style_ = other.line_style_;
	forecast_line_colour_ = unique_ptr<Colour>(other.forecast_line_colour_->clone());
	forecast_line_style_ = other.forecast_line_style_;
	control_line_colour_ = unique_ptr<Colour>(other.control_line_colour_->clone());
	control_line_style_ = other.control_line_style_;
	median_line_colour_ = unique_ptr<Colour>(other.median_line_colour_->clone());
	median_line_style_ = other.median_line_style_;
	
}


bool EpsPlumeAttributes::accept(const string& node)
{

	if ( magCompare(node, "epsplume")  )
		return true;
	
	return false;
}

void EpsPlumeAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "epsplume")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void EpsPlumeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " method = " <<  method_;
	out << " legend = " <<  legend_;
	out << " line = " <<  line_;
	out << " line_thickness = " <<  line_thickness_;
	out << " forecast = " <<  forecast_;
	out << " forecast_line_thickness = " <<  forecast_line_thickness_;
	out << " control = " <<  control_;
	out << " control_line_thickness = " <<  control_line_thickness_;
	out << " median = " <<  median_;
	out << " median_line_thickness = " <<  median_line_thickness_;
	out << " shading = " <<  shading_;
	out << " shading_levels = " <<  shading_levels_;
	out << " shading_colours = " <<  shading_colours_;
	out << " line_colour = " <<  *line_colour_;
	out << " line_style = " <<  line_style_;
	out << " forecast_line_colour = " <<  *forecast_line_colour_;
	out << " forecast_line_style = " <<  forecast_line_style_;
	out << " control_line_colour = " <<  *control_line_colour_;
	out << " control_line_style = " <<  control_line_style_;
	out << " median_line_colour = " <<  *median_line_colour_;
	out << " median_line_style = " <<  median_line_style_;
	
	out << "]" << "\n";
}

void EpsPlumeAttributes::toxml(ostream& out)  const
{
	out <<  "\"epsplume\"";
	out << ", \"eps_plume_method\":";
	niceprint(out,method_);
	out << ", \"eps_plume_legend\":";
	niceprint(out,legend_);
	out << ", \"eps_plume_members\":";
	niceprint(out,line_);
	out << ", \"eps_plume_line_thickness\":";
	niceprint(out,line_thickness_);
	out << ", \"eps_plume_forecast\":";
	niceprint(out,forecast_);
	out << ", \"eps_plume_forecast_line_thickness\":";
	niceprint(out,forecast_line_thickness_);
	out << ", \"eps_plume_control\":";
	niceprint(out,control_);
	out << ", \"eps_plume_control_line_thickness\":";
	niceprint(out,control_line_thickness_);
	out << ", \"eps_plume_median\":";
	niceprint(out,median_);
	out << ", \"eps_plume_median_line_thickness\":";
	niceprint(out,median_line_thickness_);
	out << ", \"eps_plume_shading\":";
	niceprint(out,shading_);
	out << ", \"eps_plume_shading_level_list\":";
	niceprint(out,shading_levels_);
	out << ", \"eps_plume_shading_colour_list\":";
	niceprint(out,shading_colours_);
	out << ", \"eps_plume_line_colour\":";
	niceprint(out, *line_colour_);
	out << ", \"eps_plume_line_style\":";
	niceprint(out, line_style_);
	out << ", \"eps_plume_forecast_line_colour\":";
	niceprint(out, *forecast_line_colour_);
	out << ", \"eps_plume_forecast_line_style\":";
	niceprint(out, forecast_line_style_);
	out << ", \"eps_plume_control_line_colour\":";
	niceprint(out, *control_line_colour_);
	out << ", \"eps_plume_control_line_style\":";
	niceprint(out, control_line_style_);
	out << ", \"eps_plume_median_line_colour\":";
	niceprint(out, *median_line_colour_);
	out << ", \"eps_plume_median_line_style\":";
	niceprint(out, median_line_style_);
	
}

static MagicsParameter<string> eps_plume_method("eps_plume_method", "time_serie");
static MagicsParameter<string> eps_plume_legend("eps_plume_legend", "on");
static MagicsParameter<string> eps_plume_members("eps_plume_members", "on");
static MagicsParameter<int> eps_plume_line_thickness("eps_plume_line_thickness", 1);
static MagicsParameter<string> eps_plume_forecast("eps_plume_forecast", "on");
static MagicsParameter<int> eps_plume_forecast_line_thickness("eps_plume_forecast_line_thickness", 5);
static MagicsParameter<string> eps_plume_control("eps_plume_control", "on");
static MagicsParameter<int> eps_plume_control_line_thickness("eps_plume_control_line_thickness", 5);
static MagicsParameter<string> eps_plume_median("eps_plume_median", "off");
static MagicsParameter<int> eps_plume_median_line_thickness("eps_plume_median_line_thickness", 5);
static MagicsParameter<string> eps_plume_shading("eps_plume_shading", "off");
static MagicsParameter<doublearray> eps_plume_shading_level_list("eps_plume_shading_level_list", floatarray());
static MagicsParameter<stringarray> eps_plume_shading_colour_list("eps_plume_shading_colour_list", stringarray());
static MagicsParameter<string> eps_plume_line_colour("eps_plume_line_colour", "magenta");
static MagicsParameter<string> eps_plume_line_style("eps_plume_line_style", "solid");
static MagicsParameter<string> eps_plume_forecast_line_colour("eps_plume_forecast_line_colour", "cyan");
static MagicsParameter<string> eps_plume_forecast_line_style("eps_plume_forecast_line_style", "dash");
static MagicsParameter<string> eps_plume_control_line_colour("eps_plume_control_line_colour", "cyan");
static MagicsParameter<string> eps_plume_control_line_style("eps_plume_control_line_style", "solid");
static MagicsParameter<string> eps_plume_median_line_colour("eps_plume_median_line_colour", "cyan");
static MagicsParameter<string> eps_plume_median_line_style("eps_plume_median_line_style", "solid");
