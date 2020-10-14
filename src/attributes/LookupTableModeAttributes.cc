
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LookupTableModeAttributes.h
    \\brief Definition of LookupTableMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "LookupTableModeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

LookupTableModeAttributes::LookupTableModeAttributes():
	minLevel_(ParameterManager::getInt("image_min_level")),
	maxLevel_(ParameterManager::getInt("image_max_level")),
	outlayer_(ParameterManager::getDouble("image_outlayer_rejection"))
	
	 
{
} 


LookupTableModeAttributes::~LookupTableModeAttributes()
{
	
}

    
void LookupTableModeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "image";
	
	setAttribute(prefix, "image_min_level", minLevel_, params);
	setAttribute(prefix, "image_max_level", maxLevel_, params);
	setAttribute(prefix, "image_outlayer_rejection", outlayer_, params);
	
	
}

void LookupTableModeAttributes::copy(const LookupTableModeAttributes& other)
{
	minLevel_ = other.minLevel_;
	maxLevel_ = other.maxLevel_;
	outlayer_ = other.outlayer_;
	
} 


bool LookupTableModeAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void LookupTableModeAttributes::set(const XmlNode& node)
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

void LookupTableModeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " minLevel = " <<  minLevel_;
	out << " maxLevel = " <<  maxLevel_;
	out << " outlayer = " <<  outlayer_;
	
	out << "]" << "\n";
}

void LookupTableModeAttributes::toxml(ostream& out)  const
{
	out <<  "\"\""; 
	out << ", \"image_min_level\":";
	niceprint(out,minLevel_);
	out << ", \"image_max_level\":";
	niceprint(out,maxLevel_);
	out << ", \"image_outlayer_rejection\":";
	niceprint(out,outlayer_);
	
}

static MagicsParameter<int> image_min_level("image_min_level", INT_MIN, "");
static MagicsParameter<int> image_max_level("image_max_level", INT_MAX, "");
static MagicsParameter<double> image_outlayer_rejection("image_outlayer_rejection", 0, "");
