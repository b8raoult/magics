
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LevelSelectionAttributes.h
    \\brief Definition of LevelSelection Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "LevelSelectionAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

LevelSelectionAttributes::LevelSelectionAttributes():
	max_(ParameterManager::getDouble("contour_max_level")),
	min_(ParameterManager::getDouble("contour_min_level")),
	max_shade_(ParameterManager::getDouble("contour_shade_max_level")),
	min_shade_(ParameterManager::getDouble("contour_shade_min_level"))
	
	
{
}


LevelSelectionAttributes::~LevelSelectionAttributes()
{

}


void LevelSelectionAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "contour";
	
	setAttribute(prefix, "contour_max_level", max_, params);
	setAttribute(prefix, "contour_min_level", min_, params);
	setAttribute(prefix, "contour_shade_max_level", max_shade_, params);
	setAttribute(prefix, "contour_shade_min_level", min_shade_, params);
	
	
}

void LevelSelectionAttributes::copy(const LevelSelectionAttributes& other)
{
	max_ = other.max_;
	min_ = other.min_;
	max_shade_ = other.max_shade_;
	min_shade_ = other.min_shade_;
	
}


bool LevelSelectionAttributes::accept(const string& node)
{

	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void LevelSelectionAttributes::set(const XmlNode& node)
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

void LevelSelectionAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " max = " <<  max_;
	out << " min = " <<  min_;
	out << " max_shade = " <<  max_shade_;
	out << " min_shade = " <<  min_shade_;
	
	out << "]" << "\n";
}

void LevelSelectionAttributes::toxml(ostream& out)  const
{
	out <<  "\"\"";
	out << ", \"contour_max_level\":";
	niceprint(out,max_);
	out << ", \"contour_min_level\":";
	niceprint(out,min_);
	out << ", \"contour_shade_max_level\":";
	niceprint(out,max_shade_);
	out << ", \"contour_shade_min_level\":";
	niceprint(out,min_shade_);
	
}

static MagicsParameter<double> contour_max_level("contour_max_level", 1.0e+21);
static MagicsParameter<double> contour_min_level("contour_min_level", -1.0e+21);
static MagicsParameter<double> contour_shade_max_level("contour_shade_max_level", 1.0e+21);
static MagicsParameter<double> contour_shade_min_level("contour_shade_min_level", -1.0e+21);
