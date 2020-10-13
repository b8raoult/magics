
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file CairoDriverAttributes.h
    \\brief Definition of CairoDriver Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "CairoDriverAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

CairoDriverAttributes::CairoDriverAttributes():
	transparent_(ParameterManager::getString("output_cairo_transparent_background")),
	antialias_(ParameterManager::getString("output_cairo_antialias")),
	palette_(ParameterManager::getString("output_cairo_palette")),
	quality_(ParameterManager::getInt("output_geotiff_quality"))
	
	
{
}


CairoDriverAttributes::~CairoDriverAttributes()
{

}


void CairoDriverAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "output";
	prefix[i++] = "output_cairo";
	
	setAttribute(prefix, "output_cairo_transparent_background", transparent_, params);
	setAttribute(prefix, "output_cairo_antialias", antialias_, params);
	setAttribute(prefix, "output_cairo_palette", palette_, params);
	setAttribute(prefix, "output_geotiff_quality", quality_, params);
	
	
}

void CairoDriverAttributes::copy(const CairoDriverAttributes& other)
{
	transparent_ = other.transparent_;
	antialias_ = other.antialias_;
	palette_ = other.palette_;
	quality_ = other.quality_;
	
}


bool CairoDriverAttributes::accept(const string& node)
{

	if ( magCompare(node, "cairo")  )
		return true;
	
	return false;
}

void CairoDriverAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "cairo")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void CairoDriverAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " transparent = " <<  transparent_;
	out << " antialias = " <<  antialias_;
	out << " palette = " <<  palette_;
	out << " quality = " <<  quality_;
	
	out << "]" << "\n";
}

void CairoDriverAttributes::toxml(ostream& out)  const
{
	out <<  "\"cairo\"";
	out << ", \"output_cairo_transparent_background\":";
	niceprint(out,transparent_);
	out << ", \"output_cairo_antialias\":";
	niceprint(out,antialias_);
	out << ", \"output_cairo_palette\":";
	niceprint(out,palette_);
	out << ", \"output_geotiff_quality\":";
	niceprint(out,quality_);
	
}

static MagicsParameter<string> output_cairo_transparent_background("output_cairo_transparent_background", "off");
static MagicsParameter<string> output_cairo_antialias("output_cairo_antialias", "on");
static MagicsParameter<string> output_cairo_palette("output_cairo_palette", "off");
static MagicsParameter<int> output_geotiff_quality("output_geotiff_quality", 1);
