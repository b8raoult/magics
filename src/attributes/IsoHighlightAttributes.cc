
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file IsoHighlightAttributes.h
    \\brief Definition of IsoHighlight Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "IsoHighlightAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

IsoHighlightAttributes::IsoHighlightAttributes():
	reference_(ParameterManager::getDouble("contour_reference_level")),
	thickness_(ParameterManager::getInt("contour_highlight_thickness")),
	frequency_(ParameterManager::getInt("contour_highlight_frequency"))
	,
	style_(MagTranslator<string, LineStyle>().magics("contour_highlight_style")),
	colour_(MagTranslator<string, Colour>().magics("contour_highlight_colour"))
	
{
}


IsoHighlightAttributes::~IsoHighlightAttributes()
{

}


void IsoHighlightAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(3);
	int i = 0;
	prefix[i++] = "contour";
	prefix[i++] = "contour";
	prefix[i++] = "contour_highlight";
	
	setAttribute(prefix, "contour_reference_level", reference_, params);
	setAttribute(prefix, "contour_highlight_thickness", thickness_, params);
	setAttribute(prefix, "contour_highlight_frequency", frequency_, params);
	
	setAttribute(prefix, "contour_highlight_style", style_, params);
	setMember(prefix, "contour_highlight_colour", colour_, params);
	
}

void IsoHighlightAttributes::copy(const IsoHighlightAttributes& other)
{
	reference_ = other.reference_;
	thickness_ = other.thickness_;
	frequency_ = other.frequency_;
	style_ = other.style_;
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	
}


bool IsoHighlightAttributes::accept(const string& node)
{

	if ( magCompare(node, "highlight")  )
		return true;
	
	return false;
}

void IsoHighlightAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "highlight")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void IsoHighlightAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " reference = " <<  reference_;
	out << " thickness = " <<  thickness_;
	out << " frequency = " <<  frequency_;
	out << " style = " <<  style_;
	out << " colour = " <<  *colour_;
	
	out << "]" << "\n";
}

void IsoHighlightAttributes::toxml(ostream& out)  const
{
	out <<  "\"highlight\"";
	out << ", \"contour_reference_level\":";
	niceprint(out,reference_);
	out << ", \"contour_highlight_thickness\":";
	niceprint(out,thickness_);
	out << ", \"contour_highlight_frequency\":";
	niceprint(out,frequency_);
	out << ", \"contour_highlight_style\":";
	niceprint(out, style_);
	out << ", \"contour_highlight_colour\":";
	niceprint(out, *colour_);
	
}

static MagicsParameter<double> contour_reference_level("contour_reference_level", 0.0);
static MagicsParameter<int> contour_highlight_thickness("contour_highlight_thickness", 3);
static MagicsParameter<int> contour_highlight_frequency("contour_highlight_frequency", 4);
static MagicsParameter<string> contour_highlight_style("contour_highlight_style", "solid");
static MagicsParameter<string> contour_highlight_colour("contour_highlight_colour", "blue");
