
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file BinaryObjectAttributes.h
    \\brief Definition of BinaryObject Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "BinaryObjectAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

BinaryObjectAttributes::BinaryObjectAttributes():
	path_(ParameterManager::getString("mgb_filename")),
	transparency_(ParameterManager::getDouble("mgb_transparency")),
	mgb_x_(ParameterManager::getDouble("mgb_x")),
	mgb_y_(ParameterManager::getDouble("mgb_y")),
	mgb_width_(ParameterManager::getDouble("mgb_width")),
	mgb_height_(ParameterManager::getDouble("mgb_height")),
	mgb_blur_radius_(ParameterManager::getInt("mgb_blur_radius"))
	
	 
{
} 


BinaryObjectAttributes::~BinaryObjectAttributes()
{
	
}

    
void BinaryObjectAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "mgb";
	
	setAttribute(prefix, "mgb_filename", path_, params);
	setAttribute(prefix, "mgb_transparency", transparency_, params);
	setAttribute(prefix, "mgb_x", mgb_x_, params);
	setAttribute(prefix, "mgb_y", mgb_y_, params);
	setAttribute(prefix, "mgb_width", mgb_width_, params);
	setAttribute(prefix, "mgb_height", mgb_height_, params);
	setAttribute(prefix, "mgb_blur_radius", mgb_blur_radius_, params);
	
	
}

void BinaryObjectAttributes::copy(const BinaryObjectAttributes& other)
{
	path_ = other.path_;
	transparency_ = other.transparency_;
	mgb_x_ = other.mgb_x_;
	mgb_y_ = other.mgb_y_;
	mgb_width_ = other.mgb_width_;
	mgb_height_ = other.mgb_height_;
	mgb_blur_radius_ = other.mgb_blur_radius_;
	
} 


bool BinaryObjectAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "mgb")  )
		return true;
	
	return false;
}

void BinaryObjectAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "mgb")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void BinaryObjectAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	out << " transparency = " <<  transparency_;
	out << " mgb_x = " <<  mgb_x_;
	out << " mgb_y = " <<  mgb_y_;
	out << " mgb_width = " <<  mgb_width_;
	out << " mgb_height = " <<  mgb_height_;
	out << " mgb_blur_radius = " <<  mgb_blur_radius_;
	
	out << "]" << "\n";
}

void BinaryObjectAttributes::toxml(ostream& out)  const
{
	out <<  "\"mgb\""; 
	out << ", \"mgb_filename\":";
	niceprint(out,path_);
	out << ", \"mgb_transparency\":";
	niceprint(out,transparency_);
	out << ", \"mgb_x\":";
	niceprint(out,mgb_x_);
	out << ", \"mgb_y\":";
	niceprint(out,mgb_y_);
	out << ", \"mgb_width\":";
	niceprint(out,mgb_width_);
	out << ", \"mgb_height\":";
	niceprint(out,mgb_height_);
	out << ", \"mgb_blur_radius\":";
	niceprint(out,mgb_blur_radius_);
	
}

static MagicsParameter<string> mgb_filename("mgb_filename", "", "");
static MagicsParameter<double> mgb_transparency("mgb_transparency", 1.0, "");
static MagicsParameter<double> mgb_x("mgb_x", 0, "");
static MagicsParameter<double> mgb_y("mgb_y", 0, "");
static MagicsParameter<double> mgb_width("mgb_width", 100, "");
static MagicsParameter<double> mgb_height("mgb_height", 100, "");
static MagicsParameter<int> mgb_blur_radius("mgb_blur_radius", -1, "");
