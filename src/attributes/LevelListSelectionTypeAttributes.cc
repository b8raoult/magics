
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LevelListSelectionTypeAttributes.h
    \\brief Definition of LevelListSelectionType Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "LevelListSelectionTypeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

LevelListSelectionTypeAttributes::LevelListSelectionTypeAttributes():
	list_(ParameterManager::getDoubleArray("contour_level_list"))
	
	
{
}


LevelListSelectionTypeAttributes::~LevelListSelectionTypeAttributes()
{

}


void LevelListSelectionTypeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "contour";
	
	setAttribute(prefix, "contour_level_list", list_, params);
	
	
}

void LevelListSelectionTypeAttributes::copy(const LevelListSelectionTypeAttributes& other)
{
	list_ = other.list_;
	
}


bool LevelListSelectionTypeAttributes::accept(const string& node)
{

	if ( magCompare(node, "list")  )
		return true;
	
	return false;
}

void LevelListSelectionTypeAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "list")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void LevelListSelectionTypeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " list = " <<  list_;
	
	out << "]" << "\n";
}

void LevelListSelectionTypeAttributes::toxml(ostream& out)  const
{
	out <<  "\"list\"";
	out << ", \"contour_level_list\":";
	niceprint(out,list_);
	
}

static MagicsParameter<doublearray> contour_level_list("contour_level_list", floatarray());
