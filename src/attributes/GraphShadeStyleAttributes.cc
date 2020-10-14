
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GraphShadeStyleAttributes.h
    \\brief Definition of GraphShadeStyle Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "GraphShadeStyleAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

GraphShadeStyleAttributes::GraphShadeStyleAttributes():
	
	colour_(MagTranslator<string, Colour>().magics("graph_shade_colour"))
	
{
}


GraphShadeStyleAttributes::~GraphShadeStyleAttributes()
{

}


void GraphShadeStyleAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	
	setMember(prefix, "graph_shade_colour", colour_, params);
	
}

void GraphShadeStyleAttributes::copy(const GraphShadeStyleAttributes& other)
{
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	
}


bool GraphShadeStyleAttributes::accept(const string& node)
{

	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void GraphShadeStyleAttributes::set(const XmlNode& node)
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

void GraphShadeStyleAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " colour = " <<  *colour_;
	
	out << "]" << "\n";
}

void GraphShadeStyleAttributes::toxml(ostream& out)  const
{
	out <<  "\"\"";
	out << ", \"graph_shade_colour\":";
	niceprint(out, *colour_);
	
}

static MagicsParameter<string> graph_shade_colour("graph_shade_colour", "blue");
