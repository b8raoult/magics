
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4ProjectionAttributes.h
    \\brief Definition of Proj4Projection Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "Proj4ProjectionAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

Proj4ProjectionAttributes::Proj4ProjectionAttributes():
	setting_(ParameterManager::getString("subpage_map_area_definition")),
	min_latitude_(ParameterManager::getDouble("subpage_lower_left_latitude")),
	min_longitude_(ParameterManager::getDouble("subpage_lower_left_longitude")),
	max_latitude_(ParameterManager::getDouble("subpage_upper_right_latitude")),
	max_longitude_(ParameterManager::getDouble("subpage_upper_right_longitude")),
	vertical_longitude_(ParameterManager::getDouble("subpage_map_vertical_longitude")),
	true_scale_north_(ParameterManager::getDouble("subpage_map_true_scale_north")),
	true_scale_south_(ParameterManager::getDouble("subpage_map_true_scale_south")),
	projection_height_(ParameterManager::getDouble("subpage_map_projection_height")),
	projection_tilt_(ParameterManager::getDouble("subpage_map_projection_tilt")),
	projection_azimuth_(ParameterManager::getDouble("subpage_map_projection_azimuth")),
	projection_view_latitude_(ParameterManager::getDouble("subpage_map_projection_view_latitude")),
	projection_view_longitude_(ParameterManager::getDouble("subpage_map_projection_view_longitude")),
	sweep_(ParameterManager::getDouble("subpage_map_geos_sweep")),
	proj4_definition_(ParameterManager::getString("subpage_map_proj4_definition")),
	coordinates_system_(ParameterManager::getString("subpage_coordinates_system"))
	
	
{
}


Proj4ProjectionAttributes::~Proj4ProjectionAttributes()
{

}


void Proj4ProjectionAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(3);
	int i = 0;
	prefix[i++] = "subpage";
	prefix[i++] = "subpage_map";
	prefix[i++] = "subpage_map_area";
	
	setAttribute(prefix, "subpage_map_area_definition", setting_, params);
	setAttribute(prefix, "subpage_lower_left_latitude", min_latitude_, params);
	setAttribute(prefix, "subpage_lower_left_longitude", min_longitude_, params);
	setAttribute(prefix, "subpage_upper_right_latitude", max_latitude_, params);
	setAttribute(prefix, "subpage_upper_right_longitude", max_longitude_, params);
	setAttribute(prefix, "subpage_map_vertical_longitude", vertical_longitude_, params);
	setAttribute(prefix, "subpage_map_true_scale_north", true_scale_north_, params);
	setAttribute(prefix, "subpage_map_true_scale_south", true_scale_south_, params);
	setAttribute(prefix, "subpage_map_projection_height", projection_height_, params);
	setAttribute(prefix, "subpage_map_projection_tilt", projection_tilt_, params);
	setAttribute(prefix, "subpage_map_projection_azimuth", projection_azimuth_, params);
	setAttribute(prefix, "subpage_map_projection_view_latitude", projection_view_latitude_, params);
	setAttribute(prefix, "subpage_map_projection_view_longitude", projection_view_longitude_, params);
	setAttribute(prefix, "subpage_map_geos_sweep", sweep_, params);
	setAttribute(prefix, "subpage_map_proj4_definition", proj4_definition_, params);
	setAttribute(prefix, "subpage_coordinates_system", coordinates_system_, params);
	
	
}

void Proj4ProjectionAttributes::copy(const Proj4ProjectionAttributes& other)
{
	setting_ = other.setting_;
	min_latitude_ = other.min_latitude_;
	min_longitude_ = other.min_longitude_;
	max_latitude_ = other.max_latitude_;
	max_longitude_ = other.max_longitude_;
	vertical_longitude_ = other.vertical_longitude_;
	true_scale_north_ = other.true_scale_north_;
	true_scale_south_ = other.true_scale_south_;
	projection_height_ = other.projection_height_;
	projection_tilt_ = other.projection_tilt_;
	projection_azimuth_ = other.projection_azimuth_;
	projection_view_latitude_ = other.projection_view_latitude_;
	projection_view_longitude_ = other.projection_view_longitude_;
	sweep_ = other.sweep_;
	proj4_definition_ = other.proj4_definition_;
	coordinates_system_ = other.coordinates_system_;
	
}


bool Proj4ProjectionAttributes::accept(const string& node)
{

	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void Proj4ProjectionAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void Proj4ProjectionAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " setting = " <<  setting_;
	out << " min_latitude = " <<  min_latitude_;
	out << " min_longitude = " <<  min_longitude_;
	out << " max_latitude = " <<  max_latitude_;
	out << " max_longitude = " <<  max_longitude_;
	out << " vertical_longitude = " <<  vertical_longitude_;
	out << " true_scale_north = " <<  true_scale_north_;
	out << " true_scale_south = " <<  true_scale_south_;
	out << " projection_height = " <<  projection_height_;
	out << " projection_tilt = " <<  projection_tilt_;
	out << " projection_azimuth = " <<  projection_azimuth_;
	out << " projection_view_latitude = " <<  projection_view_latitude_;
	out << " projection_view_longitude = " <<  projection_view_longitude_;
	out << " sweep = " <<  sweep_;
	out << " proj4_definition = " <<  proj4_definition_;
	out << " coordinates_system = " <<  coordinates_system_;
	
	out << "]" << "\n";
}

void Proj4ProjectionAttributes::toxml(ostream& out)  const
{
	out <<  "\"\"";
	out << ", \"subpage_map_area_definition\":";
	niceprint(out,setting_);
	out << ", \"subpage_lower_left_latitude\":";
	niceprint(out,min_latitude_);
	out << ", \"subpage_lower_left_longitude\":";
	niceprint(out,min_longitude_);
	out << ", \"subpage_upper_right_latitude\":";
	niceprint(out,max_latitude_);
	out << ", \"subpage_upper_right_longitude\":";
	niceprint(out,max_longitude_);
	out << ", \"subpage_map_vertical_longitude\":";
	niceprint(out,vertical_longitude_);
	out << ", \"subpage_map_true_scale_north\":";
	niceprint(out,true_scale_north_);
	out << ", \"subpage_map_true_scale_south\":";
	niceprint(out,true_scale_south_);
	out << ", \"subpage_map_projection_height\":";
	niceprint(out,projection_height_);
	out << ", \"subpage_map_projection_tilt\":";
	niceprint(out,projection_tilt_);
	out << ", \"subpage_map_projection_azimuth\":";
	niceprint(out,projection_azimuth_);
	out << ", \"subpage_map_projection_view_latitude\":";
	niceprint(out,projection_view_latitude_);
	out << ", \"subpage_map_projection_view_longitude\":";
	niceprint(out,projection_view_longitude_);
	out << ", \"subpage_map_geos_sweep\":";
	niceprint(out,sweep_);
	out << ", \"subpage_map_proj4_definition\":";
	niceprint(out,proj4_definition_);
	out << ", \"subpage_coordinates_system\":";
	niceprint(out,coordinates_system_);
	
}

static MagicsParameter<string> subpage_map_area_definition("subpage_map_area_definition", "full");
static MagicsParameter<double> subpage_lower_left_latitude("subpage_lower_left_latitude", -90.0);
static MagicsParameter<double> subpage_lower_left_longitude("subpage_lower_left_longitude", -180.0);
static MagicsParameter<double> subpage_upper_right_latitude("subpage_upper_right_latitude", 90.0);
static MagicsParameter<double> subpage_upper_right_longitude("subpage_upper_right_longitude", 180.0);
static MagicsParameter<double> subpage_map_vertical_longitude("subpage_map_vertical_longitude", 0);
static MagicsParameter<double> subpage_map_true_scale_north("subpage_map_true_scale_north", 06);
static MagicsParameter<double> subpage_map_true_scale_south("subpage_map_true_scale_south", -60);
static MagicsParameter<double> subpage_map_projection_height("subpage_map_projection_height", 42164000);
static MagicsParameter<double> subpage_map_projection_tilt("subpage_map_projection_tilt", 0);
static MagicsParameter<double> subpage_map_projection_azimuth("subpage_map_projection_azimuth", 20);
static MagicsParameter<double> subpage_map_projection_view_latitude("subpage_map_projection_view_latitude", 20);
static MagicsParameter<double> subpage_map_projection_view_longitude("subpage_map_projection_view_longitude", -60);
static MagicsParameter<double> subpage_map_geos_sweep("subpage_map_geos_sweep", 0);
static MagicsParameter<string> subpage_map_proj4_definition("subpage_map_proj4_definition", "");
static MagicsParameter<string> subpage_coordinates_system("subpage_coordinates_system", "latlon");
