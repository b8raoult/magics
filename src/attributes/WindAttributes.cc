
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file WindAttributes.h
    \\brief Definition of Wind Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "WindAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

WindAttributes::WindAttributes():
	thinning_method_(ParameterManager::getString("wind_thinning_method")),
	thinning_factor_(ParameterManager::getDouble("wind_thinning_factor")),
	thinning_debug_(ParameterManager::getBool("wind_thinning_debug"))
	,
	type_(MagTranslator<string, WindPlotting>().magics("wind_field_type"))
	
{
}


WindAttributes::~WindAttributes()
{

}


void WindAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "wind";
	
	setAttribute(prefix, "wind_thinning_method", thinning_method_, params);
	setAttribute(prefix, "wind_thinning_factor", thinning_factor_, params);
	setAttribute(prefix, "wind_thinning_debug", thinning_debug_, params);
	
	setMember(prefix, "wind_field_type", type_, params);
	
}

void WindAttributes::copy(const WindAttributes& other)
{
	thinning_method_ = other.thinning_method_;
	thinning_factor_ = other.thinning_factor_;
	thinning_debug_ = other.thinning_debug_;
	type_ = unique_ptr<WindPlotting>(other.type_->clone());
	
}


bool WindAttributes::accept(const string& node)
{

	if ( magCompare(node, "wind")  )
		return true;
	if ( acceptNode(node, type_) )
		return true;
	
	return false;
}

void WindAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "wind")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), type_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), type_, *elt);
		
	}
}

void WindAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " thinning_method = " <<  thinning_method_;
	out << " thinning_factor = " <<  thinning_factor_;
	out << " thinning_debug = " <<  thinning_debug_;
	out << " type = " <<  *type_;
	
	out << "]" << "\n";
}

void WindAttributes::toxml(ostream& out)  const
{
	out <<  "\"wind\"";
	out << ", \"wind_thinning_method\":";
	niceprint(out,thinning_method_);
	out << ", \"wind_thinning_factor\":";
	niceprint(out,thinning_factor_);
	out << ", \"wind_thinning_debug\":";
	niceprint(out,thinning_debug_);
	out << ", \"wind_field_type\":";
	type_->toxml(out);
	
}

static MagicsParameter<string> wind_thinning_method("wind_thinning_method", "data");
static MagicsParameter<double> wind_thinning_factor("wind_thinning_factor", 2.0);
static MagicsParameter<string> wind_thinning_debug("wind_thinning_debug", "off");
static MagicsParameter<string> wind_field_type("wind_field_type", "arrows");
#include "FlagPlotting.h"
#include "ArrowPlotting.h"
#include "Streamlines.h"
static SimpleObjectMaker<FlagPlotting , WindPlotting> flags_FlagPlotting("flags");
static SimpleObjectMaker<ArrowPlotting , WindPlotting> arrows_ArrowPlotting("arrows");
static SimpleObjectMaker<Streamlines , WindPlotting> streamlines_Streamlines("streamlines");
