
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GraphArrowAttributes.h
    \\brief Definition of GraphArrow Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "GraphArrowAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

GraphArrowAttributes::GraphArrowAttributes():
	unit_velocity_(ParameterManager::getDouble("graph_arrow_unit_velocity"))
	,
	colour_(MagTranslator<string, Colour>().magics("graph_arrow_colour"))
	
{
}


GraphArrowAttributes::~GraphArrowAttributes()
{

}


void GraphArrowAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	setAttribute(prefix, "graph_arrow_unit_velocity", unit_velocity_, params);
	
	setMember(prefix, "graph_arrow_colour", colour_, params);
	
}

void GraphArrowAttributes::copy(const GraphArrowAttributes& other)
{
	unit_velocity_ = other.unit_velocity_;
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	
}


bool GraphArrowAttributes::accept(const string& node)
{

	if ( magCompare(node, "arrow")  )
		return true;
	
	return false;
}

void GraphArrowAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "arrow")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void GraphArrowAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " unit_velocity = " <<  unit_velocity_;
	out << " colour = " <<  *colour_;
	
	out << "]" << "\n";
}

void GraphArrowAttributes::toxml(ostream& out)  const
{
	out <<  "\"arrow\"";
	out << ", \"graph_arrow_unit_velocity\":";
	niceprint(out,unit_velocity_);
	out << ", \"graph_arrow_colour\":";
	niceprint(out, *colour_);
	
}

static MagicsParameter<double> graph_arrow_unit_velocity("graph_arrow_unit_velocity", 25.0);
static MagicsParameter<string> graph_arrow_colour("graph_arrow_colour", "black");
