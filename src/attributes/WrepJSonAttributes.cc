
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file WrepJSonAttributes.h
    \\brief Definition of WrepJSon Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "WrepJSonAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

WrepJSonAttributes::WrepJSonAttributes():
	path_(ParameterManager::getString("wrepjson_input_filename")),
	param_info_(ParameterManager::getString("wrepjson_parameter_information")),
	title_(ParameterManager::getBool("wrepjson_title")),
	position_info_(ParameterManager::getBool("wrepjson_position_information")),
	product_info_(ParameterManager::getString("wrepjson_product_information")),
	family_(ParameterManager::getString("wrepjson_family")),
	key_(ParameterManager::getString("wrepjson_key")),
	plumes_(ParameterManager::getDouble("wrepjson_plumes_interval")),
	information_(ParameterManager::getBool("wrepjson_information")),
	keyword_(ParameterManager::getString("wrepjson_keyword")),
	station_name_(ParameterManager::getString("wrepjson_station_name")),
	param_(ParameterManager::getString("wrepjson_parameter")),
	param_scaling_factor_(ParameterManager::getDouble("wrepjson_parameter_scaling_factor")),
	param_offset_factor_(ParameterManager::getDouble("wrepjson_parameter_offset_factor")),
	clim_param_(ParameterManager::getString("wrepjson_clim_parameter")),
	clim_step_(ParameterManager::getInt("wrepjson_clim_step")),
	steps_(ParameterManager::getIntArray("wrepjson_steps")),
	percentile_(ParameterManager::getDouble("wrepjson_y_axis_percentile")),
	threshold_(ParameterManager::getDouble("wrepjson_y_axis_threshold")),
	y_max_threshold_(ParameterManager::getDouble("wrepjson_y_max_threshold")),
	y_percent_(ParameterManager::getDouble("wrepjson_y_percentage")),
	correction_(ParameterManager::getBool("wrepjson_temperature_correction")),
	missing_value_(ParameterManager::getDouble("wrepjson_missing_value")),
	ignore_keys_(ParameterManager::getStringArray("wrepjson_ignore_keys")),
	profile_quantile_(ParameterManager::getString("wrepjson_profile_quantile")),
	hodograph_grid_(ParameterManager::getBool("wrepjson_hodograph_grid")),
	hodograph_tephi_(ParameterManager::getBool("wrepjson_hodograph_tephi")),
	hodograph_member_(ParameterManager::getInt("wrepjson_hodograph_member"))
	
	
{
}


WrepJSonAttributes::~WrepJSonAttributes()
{

}


void WrepJSonAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "wrepjson";
	
	setAttribute(prefix, "wrepjson_input_filename", path_, params);
	setAttribute(prefix, "wrepjson_parameter_information", param_info_, params);
	setAttribute(prefix, "wrepjson_title", title_, params);
	setAttribute(prefix, "wrepjson_position_information", position_info_, params);
	setAttribute(prefix, "wrepjson_product_information", product_info_, params);
	setAttribute(prefix, "wrepjson_family", family_, params);
	setAttribute(prefix, "wrepjson_key", key_, params);
	setAttribute(prefix, "wrepjson_plumes_interval", plumes_, params);
	setAttribute(prefix, "wrepjson_information", information_, params);
	setAttribute(prefix, "wrepjson_keyword", keyword_, params);
	setAttribute(prefix, "wrepjson_station_name", station_name_, params);
	setAttribute(prefix, "wrepjson_parameter", param_, params);
	setAttribute(prefix, "wrepjson_parameter_scaling_factor", param_scaling_factor_, params);
	setAttribute(prefix, "wrepjson_parameter_offset_factor", param_offset_factor_, params);
	setAttribute(prefix, "wrepjson_clim_parameter", clim_param_, params);
	setAttribute(prefix, "wrepjson_clim_step", clim_step_, params);
	setAttribute(prefix, "wrepjson_steps", steps_, params);
	setAttribute(prefix, "wrepjson_y_axis_percentile", percentile_, params);
	setAttribute(prefix, "wrepjson_y_axis_threshold", threshold_, params);
	setAttribute(prefix, "wrepjson_y_max_threshold", y_max_threshold_, params);
	setAttribute(prefix, "wrepjson_y_percentage", y_percent_, params);
	setAttribute(prefix, "wrepjson_temperature_correction", correction_, params);
	setAttribute(prefix, "wrepjson_missing_value", missing_value_, params);
	setAttribute(prefix, "wrepjson_ignore_keys", ignore_keys_, params);
	setAttribute(prefix, "wrepjson_profile_quantile", profile_quantile_, params);
	setAttribute(prefix, "wrepjson_hodograph_grid", hodograph_grid_, params);
	setAttribute(prefix, "wrepjson_hodograph_tephi", hodograph_tephi_, params);
	setAttribute(prefix, "wrepjson_hodograph_member", hodograph_member_, params);
	
	
}

void WrepJSonAttributes::copy(const WrepJSonAttributes& other)
{
	path_ = other.path_;
	param_info_ = other.param_info_;
	title_ = other.title_;
	position_info_ = other.position_info_;
	product_info_ = other.product_info_;
	family_ = other.family_;
	key_ = other.key_;
	plumes_ = other.plumes_;
	information_ = other.information_;
	keyword_ = other.keyword_;
	station_name_ = other.station_name_;
	param_ = other.param_;
	param_scaling_factor_ = other.param_scaling_factor_;
	param_offset_factor_ = other.param_offset_factor_;
	clim_param_ = other.clim_param_;
	clim_step_ = other.clim_step_;
	steps_ = other.steps_;
	percentile_ = other.percentile_;
	threshold_ = other.threshold_;
	y_max_threshold_ = other.y_max_threshold_;
	y_percent_ = other.y_percent_;
	correction_ = other.correction_;
	missing_value_ = other.missing_value_;
	ignore_keys_ = other.ignore_keys_;
	profile_quantile_ = other.profile_quantile_;
	hodograph_grid_ = other.hodograph_grid_;
	hodograph_tephi_ = other.hodograph_tephi_;
	hodograph_member_ = other.hodograph_member_;
	
}


bool WrepJSonAttributes::accept(const string& node)
{

	if ( magCompare(node, "wrepjson")  )
		return true;
	
	return false;
}

void WrepJSonAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "wrepjson")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void WrepJSonAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	out << " param_info = " <<  param_info_;
	out << " title = " <<  title_;
	out << " position_info = " <<  position_info_;
	out << " product_info = " <<  product_info_;
	out << " family = " <<  family_;
	out << " key = " <<  key_;
	out << " plumes = " <<  plumes_;
	out << " information = " <<  information_;
	out << " keyword = " <<  keyword_;
	out << " station_name = " <<  station_name_;
	out << " param = " <<  param_;
	out << " param_scaling_factor = " <<  param_scaling_factor_;
	out << " param_offset_factor = " <<  param_offset_factor_;
	out << " clim_param = " <<  clim_param_;
	out << " clim_step = " <<  clim_step_;
	out << " steps = " <<  steps_;
	out << " percentile = " <<  percentile_;
	out << " threshold = " <<  threshold_;
	out << " y_max_threshold = " <<  y_max_threshold_;
	out << " y_percent = " <<  y_percent_;
	out << " correction = " <<  correction_;
	out << " missing_value = " <<  missing_value_;
	out << " ignore_keys = " <<  ignore_keys_;
	out << " profile_quantile = " <<  profile_quantile_;
	out << " hodograph_grid = " <<  hodograph_grid_;
	out << " hodograph_tephi = " <<  hodograph_tephi_;
	out << " hodograph_member = " <<  hodograph_member_;
	
	out << "]" << "\n";
}

void WrepJSonAttributes::toxml(ostream& out)  const
{
	out <<  "\"wrepjson\"";
	out << ", \"wrepjson_input_filename\":";
	niceprint(out,path_);
	out << ", \"wrepjson_parameter_information\":";
	niceprint(out,param_info_);
	out << ", \"wrepjson_title\":";
	niceprint(out,title_);
	out << ", \"wrepjson_position_information\":";
	niceprint(out,position_info_);
	out << ", \"wrepjson_product_information\":";
	niceprint(out,product_info_);
	out << ", \"wrepjson_family\":";
	niceprint(out,family_);
	out << ", \"wrepjson_key\":";
	niceprint(out,key_);
	out << ", \"wrepjson_plumes_interval\":";
	niceprint(out,plumes_);
	out << ", \"wrepjson_information\":";
	niceprint(out,information_);
	out << ", \"wrepjson_keyword\":";
	niceprint(out,keyword_);
	out << ", \"wrepjson_station_name\":";
	niceprint(out,station_name_);
	out << ", \"wrepjson_parameter\":";
	niceprint(out,param_);
	out << ", \"wrepjson_parameter_scaling_factor\":";
	niceprint(out,param_scaling_factor_);
	out << ", \"wrepjson_parameter_offset_factor\":";
	niceprint(out,param_offset_factor_);
	out << ", \"wrepjson_clim_parameter\":";
	niceprint(out,clim_param_);
	out << ", \"wrepjson_clim_step\":";
	niceprint(out,clim_step_);
	out << ", \"wrepjson_steps\":";
	niceprint(out,steps_);
	out << ", \"wrepjson_y_axis_percentile\":";
	niceprint(out,percentile_);
	out << ", \"wrepjson_y_axis_threshold\":";
	niceprint(out,threshold_);
	out << ", \"wrepjson_y_max_threshold\":";
	niceprint(out,y_max_threshold_);
	out << ", \"wrepjson_y_percentage\":";
	niceprint(out,y_percent_);
	out << ", \"wrepjson_temperature_correction\":";
	niceprint(out,correction_);
	out << ", \"wrepjson_missing_value\":";
	niceprint(out,missing_value_);
	out << ", \"wrepjson_ignore_keys\":";
	niceprint(out,ignore_keys_);
	out << ", \"wrepjson_profile_quantile\":";
	niceprint(out,profile_quantile_);
	out << ", \"wrepjson_hodograph_grid\":";
	niceprint(out,hodograph_grid_);
	out << ", \"wrepjson_hodograph_tephi\":";
	niceprint(out,hodograph_tephi_);
	out << ", \"wrepjson_hodograph_member\":";
	niceprint(out,hodograph_member_);
	
}

static MagicsParameter<string> wrepjson_input_filename("wrepjson_input_filename", "");
static MagicsParameter<string> wrepjson_parameter_information("wrepjson_parameter_information", "");
static MagicsParameter<string> wrepjson_title("wrepjson_title", "on");
static MagicsParameter<string> wrepjson_position_information("wrepjson_position_information", "on");
static MagicsParameter<string> wrepjson_product_information("wrepjson_product_information", "");
static MagicsParameter<string> wrepjson_family("wrepjson_family", "eps");
static MagicsParameter<string> wrepjson_key("wrepjson_key", "");
static MagicsParameter<double> wrepjson_plumes_interval("wrepjson_plumes_interval", 1);
static MagicsParameter<string> wrepjson_information("wrepjson_information", "on");
static MagicsParameter<string> wrepjson_keyword("wrepjson_keyword", "");
static MagicsParameter<string> wrepjson_station_name("wrepjson_station_name", "");
static MagicsParameter<string> wrepjson_parameter("wrepjson_parameter", "1");
static MagicsParameter<double> wrepjson_parameter_scaling_factor("wrepjson_parameter_scaling_factor", 1);
static MagicsParameter<double> wrepjson_parameter_offset_factor("wrepjson_parameter_offset_factor", 0);
static MagicsParameter<string> wrepjson_clim_parameter("wrepjson_clim_parameter", "");
static MagicsParameter<int> wrepjson_clim_step("wrepjson_clim_step", 36);
static MagicsParameter<intarray> wrepjson_steps("wrepjson_steps", intarray());
static MagicsParameter<double> wrepjson_y_axis_percentile("wrepjson_y_axis_percentile", 1);
static MagicsParameter<double> wrepjson_y_axis_threshold("wrepjson_y_axis_threshold", 50);
static MagicsParameter<double> wrepjson_y_max_threshold("wrepjson_y_max_threshold", INT_MAX);
static MagicsParameter<double> wrepjson_y_percentage("wrepjson_y_percentage", 0.01);
static MagicsParameter<string> wrepjson_temperature_correction("wrepjson_temperature_correction", "off");
static MagicsParameter<double> wrepjson_missing_value("wrepjson_missing_value", -9999);
static MagicsParameter<stringarray> wrepjson_ignore_keys("wrepjson_ignore_keys", stringarray());
static MagicsParameter<string> wrepjson_profile_quantile("wrepjson_profile_quantile", "");
static MagicsParameter<string> wrepjson_hodograph_grid("wrepjson_hodograph_grid", "off");
static MagicsParameter<string> wrepjson_hodograph_tephi("wrepjson_hodograph_tephi", "off");
static MagicsParameter<int> wrepjson_hodograph_member("wrepjson_hodograph_member", -1);
