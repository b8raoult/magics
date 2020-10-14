
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SymbolTableModeAttributes.h
    \\brief Definition of SymbolTableMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "SymbolTableModeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

SymbolTableModeAttributes::SymbolTableModeAttributes():
	min_(ParameterManager::getDoubleArray("symbol_min_table")),
	max_(ParameterManager::getDoubleArray("symbol_max_table")),
	marker_(ParameterManager::getIntArray("symbol_marker_table")),
	symbol_(ParameterManager::getStringArray("symbol_name_table")),
	colour_(ParameterManager::getStringArray("symbol_colour_table")),
	height_(ParameterManager::getDoubleArray("symbol_height_table"))
	
	
{
}


SymbolTableModeAttributes::~SymbolTableModeAttributes()
{

}


void SymbolTableModeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "symbol";
	
	setAttribute(prefix, "symbol_min_table", min_, params);
	setAttribute(prefix, "symbol_max_table", max_, params);
	setAttribute(prefix, "symbol_marker_table", marker_, params);
	setAttribute(prefix, "symbol_name_table", symbol_, params);
	setAttribute(prefix, "symbol_colour_table", colour_, params);
	setAttribute(prefix, "symbol_height_table", height_, params);
	
	
}

void SymbolTableModeAttributes::copy(const SymbolTableModeAttributes& other)
{
	min_ = other.min_;
	max_ = other.max_;
	marker_ = other.marker_;
	symbol_ = other.symbol_;
	colour_ = other.colour_;
	height_ = other.height_;
	
}


bool SymbolTableModeAttributes::accept(const string& node)
{

	if ( magCompare(node, "table")  )
		return true;
	
	return false;
}

void SymbolTableModeAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "table")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void SymbolTableModeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " min = " <<  min_;
	out << " max = " <<  max_;
	out << " marker = " <<  marker_;
	out << " symbol = " <<  symbol_;
	out << " colour = " <<  colour_;
	out << " height = " <<  height_;
	
	out << "]" << "\n";
}

void SymbolTableModeAttributes::toxml(ostream& out)  const
{
	out <<  "\"table\"";
	out << ", \"symbol_min_table\":";
	niceprint(out,min_);
	out << ", \"symbol_max_table\":";
	niceprint(out,max_);
	out << ", \"symbol_marker_table\":";
	niceprint(out,marker_);
	out << ", \"symbol_name_table\":";
	niceprint(out,symbol_);
	out << ", \"symbol_colour_table\":";
	niceprint(out,colour_);
	out << ", \"symbol_height_table\":";
	niceprint(out,height_);
	
}

static MagicsParameter<doublearray> symbol_min_table("symbol_min_table", floatarray());
static MagicsParameter<doublearray> symbol_max_table("symbol_max_table", floatarray());
static MagicsParameter<intarray> symbol_marker_table("symbol_marker_table", intarray());
static MagicsParameter<stringarray> symbol_name_table("symbol_name_table", stringarray());
static MagicsParameter<stringarray> symbol_colour_table("symbol_colour_table", stringarray());
static MagicsParameter<doublearray> symbol_height_table("symbol_height_table", floatarray());
