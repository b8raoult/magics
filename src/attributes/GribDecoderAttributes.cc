
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GribDecoderAttributes.h
    \\brief Definition of GribDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "GribDecoderAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

GribDecoderAttributes::GribDecoderAttributes():
	file_name_(ParameterManager::getString("grib_input_file_name")),
	id_(ParameterManager::getString("grib_id")),
	loop_(ParameterManager::getBool("grib_loop")),
	scaling_(ParameterManager::getBool("grib_automatic_scaling")),
	derived_scaling_(ParameterManager::getBool("grib_automatic_derived_scaling")),
	scaling_factor_(ParameterManager::getDouble("grib_scaling_factor")),
	scaling_offset_(ParameterManager::getDouble("grib_scaling_offset")),
	regular_resolution_(ParameterManager::getDouble("grib_interpolation_regular_resolution")),
	interpolation_method_(ParameterManager::getString("grib_interpolation_method")),
	missing_fill_count_(ParameterManager::getInt("grib_interpolation_method_missing_fill_count")),
	expver_(ParameterManager::getBool("grib_text_experiment")),
	units_(ParameterManager::getBool("grib_text_units")),
	field_position_(ParameterManager::getInt("grib_field_position")),
	position_1_(ParameterManager::getInt("grib_wind_position_1")),
	position_2_(ParameterManager::getInt("grib_wind_position_2")),
	colour_position_(ParameterManager::getInt("grib_wind_position_colour")),
	missing_value_(ParameterManager::getDouble("grib_missing_value_indicator"))
	,
	address_mode_(MagTranslator<string, GribAddressMode>().magics("grib_file_address_mode")),
	wind_mode_(MagTranslator<string, WindMode>().magics("grib_wind_mode"))
	
{
}


GribDecoderAttributes::~GribDecoderAttributes()
{

}


void GribDecoderAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "grib";
	prefix[i++] = "grib";
	
	setAttribute(prefix, "grib_input_file_name", file_name_, params);
	setAttribute(prefix, "grib_id", id_, params);
	setAttribute(prefix, "grib_loop", loop_, params);
	setAttribute(prefix, "grib_automatic_scaling", scaling_, params);
	setAttribute(prefix, "grib_automatic_derived_scaling", derived_scaling_, params);
	setAttribute(prefix, "grib_scaling_factor", scaling_factor_, params);
	setAttribute(prefix, "grib_scaling_offset", scaling_offset_, params);
	setAttribute(prefix, "grib_interpolation_regular_resolution", regular_resolution_, params);
	setAttribute(prefix, "grib_interpolation_method", interpolation_method_, params);
	setAttribute(prefix, "grib_interpolation_method_missing_fill_count", missing_fill_count_, params);
	setAttribute(prefix, "grib_text_experiment", expver_, params);
	setAttribute(prefix, "grib_text_units", units_, params);
	setAttribute(prefix, "grib_field_position", field_position_, params);
	setAttribute(prefix, "grib_wind_position_1", position_1_, params);
	setAttribute(prefix, "grib_wind_position_2", position_2_, params);
	setAttribute(prefix, "grib_wind_position_colour", colour_position_, params);
	setAttribute(prefix, "grib_missing_value_indicator", missing_value_, params);
	
	setMember(prefix, "grib_file_address_mode", address_mode_, params);
	setMember(prefix, "grib_wind_mode", wind_mode_, params);
	
}

void GribDecoderAttributes::copy(const GribDecoderAttributes& other)
{
	file_name_ = other.file_name_;
	id_ = other.id_;
	loop_ = other.loop_;
	scaling_ = other.scaling_;
	derived_scaling_ = other.derived_scaling_;
	scaling_factor_ = other.scaling_factor_;
	scaling_offset_ = other.scaling_offset_;
	regular_resolution_ = other.regular_resolution_;
	interpolation_method_ = other.interpolation_method_;
	missing_fill_count_ = other.missing_fill_count_;
	expver_ = other.expver_;
	units_ = other.units_;
	field_position_ = other.field_position_;
	position_1_ = other.position_1_;
	position_2_ = other.position_2_;
	colour_position_ = other.colour_position_;
	missing_value_ = other.missing_value_;
	address_mode_ = unique_ptr<GribAddressMode>(other.address_mode_->clone());
	wind_mode_ = unique_ptr<WindMode>(other.wind_mode_->clone());
	
}


bool GribDecoderAttributes::accept(const string& node)
{

	if ( magCompare(node, "grib")  )
		return true;
	if ( acceptNode(node, address_mode_) )
		return true;
	if ( acceptNode(node, wind_mode_) )
		return true;
	
	return false;
}

void GribDecoderAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "grib")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), address_mode_, node);
		setMember(node.name(), wind_mode_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), address_mode_, *elt);
		setMember(elt->name(), wind_mode_, *elt);
		
	}
}

void GribDecoderAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " file_name = " <<  file_name_;
	out << " id = " <<  id_;
	out << " loop = " <<  loop_;
	out << " scaling = " <<  scaling_;
	out << " derived_scaling = " <<  derived_scaling_;
	out << " scaling_factor = " <<  scaling_factor_;
	out << " scaling_offset = " <<  scaling_offset_;
	out << " regular_resolution = " <<  regular_resolution_;
	out << " interpolation_method = " <<  interpolation_method_;
	out << " missing_fill_count = " <<  missing_fill_count_;
	out << " expver = " <<  expver_;
	out << " units = " <<  units_;
	out << " field_position = " <<  field_position_;
	out << " position_1 = " <<  position_1_;
	out << " position_2 = " <<  position_2_;
	out << " colour_position = " <<  colour_position_;
	out << " missing_value = " <<  missing_value_;
	out << " address_mode = " <<  *address_mode_;
	out << " wind_mode = " <<  *wind_mode_;
	
	out << "]" << "\n";
}

void GribDecoderAttributes::toxml(ostream& out)  const
{
	out <<  "\"grib\"";
	out << ", \"grib_input_file_name\":";
	niceprint(out,file_name_);
	out << ", \"grib_id\":";
	niceprint(out,id_);
	out << ", \"grib_loop\":";
	niceprint(out,loop_);
	out << ", \"grib_automatic_scaling\":";
	niceprint(out,scaling_);
	out << ", \"grib_automatic_derived_scaling\":";
	niceprint(out,derived_scaling_);
	out << ", \"grib_scaling_factor\":";
	niceprint(out,scaling_factor_);
	out << ", \"grib_scaling_offset\":";
	niceprint(out,scaling_offset_);
	out << ", \"grib_interpolation_regular_resolution\":";
	niceprint(out,regular_resolution_);
	out << ", \"grib_interpolation_method\":";
	niceprint(out,interpolation_method_);
	out << ", \"grib_interpolation_method_missing_fill_count\":";
	niceprint(out,missing_fill_count_);
	out << ", \"grib_text_experiment\":";
	niceprint(out,expver_);
	out << ", \"grib_text_units\":";
	niceprint(out,units_);
	out << ", \"grib_field_position\":";
	niceprint(out,field_position_);
	out << ", \"grib_wind_position_1\":";
	niceprint(out,position_1_);
	out << ", \"grib_wind_position_2\":";
	niceprint(out,position_2_);
	out << ", \"grib_wind_position_colour\":";
	niceprint(out,colour_position_);
	out << ", \"grib_missing_value_indicator\":";
	niceprint(out,missing_value_);
	out << ", \"grib_file_address_mode\":";
	address_mode_->toxml(out);
	out << ", \"grib_wind_mode\":";
	wind_mode_->toxml(out);
	
}

static MagicsParameter<string> grib_input_file_name("grib_input_file_name", "");
static MagicsParameter<string> grib_id("grib_id", "");
static MagicsParameter<string> grib_loop("grib_loop", "off");
static MagicsParameter<string> grib_automatic_scaling("grib_automatic_scaling", "on");
static MagicsParameter<string> grib_automatic_derived_scaling("grib_automatic_derived_scaling", "off");
static MagicsParameter<double> grib_scaling_factor("grib_scaling_factor", 1);
static MagicsParameter<double> grib_scaling_offset("grib_scaling_offset", 0);
static MagicsParameter<double> grib_interpolation_regular_resolution("grib_interpolation_regular_resolution", 0.1);
static MagicsParameter<string> grib_interpolation_method("grib_interpolation_method", "interpolate");
static MagicsParameter<int> grib_interpolation_method_missing_fill_count("grib_interpolation_method_missing_fill_count", 1);
static MagicsParameter<string> grib_text_experiment("grib_text_experiment", "off");
static MagicsParameter<string> grib_text_units("grib_text_units", "off");
static MagicsParameter<int> grib_field_position("grib_field_position", 1);
static MagicsParameter<int> grib_wind_position_1("grib_wind_position_1", 1);
static MagicsParameter<int> grib_wind_position_2("grib_wind_position_2", 2);
static MagicsParameter<int> grib_wind_position_colour("grib_wind_position_colour", 3);
static MagicsParameter<double> grib_missing_value_indicator("grib_missing_value_indicator", -1.5e+21);
static MagicsParameter<string> grib_file_address_mode("grib_file_address_mode", "record");
static MagicsParameter<string> grib_wind_mode("grib_wind_mode", "uv");
#include "GribAddressMode.h"
#include "WindMode.h"
static SimpleObjectMaker<GribAddressRecordMode , GribAddressMode> record_GribAddressRecordMode("record");
static SimpleObjectMaker<GribAddressByteMode , GribAddressMode> byte_offset_GribAddressByteMode("byte_offset");
static SimpleObjectMaker<UVWindMode , WindMode> uvmode_UVWindMode("uvmode");
static SimpleObjectMaker<UVWindMode , WindMode> uv_UVWindMode("uv");
static SimpleObjectMaker<SDWindMode , WindMode> vdmode_SDWindMode("vdmode");
static SimpleObjectMaker<SDWindMode , WindMode> sd_SDWindMode("sd");
