
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file TaylorGridAttributes.h
    \\brief Definition of TaylorGrid Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "TaylorGridAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

TaylorGridAttributes::TaylorGridAttributes():
	label_(ParameterManager::getString("taylor_label")),
	label_height_(ParameterManager::getDouble("taylor_label_height")),
	primary_increment_(ParameterManager::getDouble("taylor_primary_grid_increment")),
	primary_thickness_(ParameterManager::getInt("taylor_primary_grid_line_thickness")),
	primary_reference_(ParameterManager::getDouble("taylor_primary_grid_reference")),
	reference_thickness_(ParameterManager::getInt("taylor_reference_line_thickness")),
	primary_label_(ParameterManager::getBool("taylor_primary_label")),
	primary_label_height_(ParameterManager::getDouble("taylor_primary_label_height")),
	secondary_grid_(ParameterManager::getBool("taylor_secondary_grid")),
	secondary_reference_(ParameterManager::getDouble("taylor_secondary_grid_reference")),
	secondary_increment_(ParameterManager::getDouble("taylor_secondary_grid_increment")),
	secondary_thickness_(ParameterManager::getInt("taylor_secondary_grid_line_thickness")),
	secondary_label_(ParameterManager::getBool("taylor_secondary_label")),
	secondary_label_height_(ParameterManager::getDouble("taylor_secondary_label_height"))
	,
	label_colour_(MagTranslator<string, Colour>().magics("taylor_label_colour")),
	primary_colour_(MagTranslator<string, Colour>().magics("taylor_primary_grid_line_colour")),
	primary_style_(MagTranslator<string, LineStyle>().magics("taylor_primary_grid_line_style")),
	reference_colour_(MagTranslator<string, Colour>().magics("taylor_reference_line_colour")),
	reference_style_(MagTranslator<string, LineStyle>().magics("taylor_reference_line_style")),
	primary_label_colour_(MagTranslator<string, Colour>().magics("taylor_primary_label_colour")),
	secondary_colour_(MagTranslator<string, Colour>().magics("taylor_secondary_grid_line_colour")),
	secondary_style_(MagTranslator<string, LineStyle>().magics("taylor_secondary_grid_line_style")),
	secondary_label_colour_(MagTranslator<string, Colour>().magics("taylor_secondary_label_colour"))
	
{
}


TaylorGridAttributes::~TaylorGridAttributes()
{

}


void TaylorGridAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "taylor";
	prefix[i++] = "taylor";
	
	setAttribute(prefix, "taylor_label", label_, params);
	setAttribute(prefix, "taylor_label_height", label_height_, params);
	setAttribute(prefix, "taylor_primary_grid_increment", primary_increment_, params);
	setAttribute(prefix, "taylor_primary_grid_line_thickness", primary_thickness_, params);
	setAttribute(prefix, "taylor_primary_grid_reference", primary_reference_, params);
	setAttribute(prefix, "taylor_reference_line_thickness", reference_thickness_, params);
	setAttribute(prefix, "taylor_primary_label", primary_label_, params);
	setAttribute(prefix, "taylor_primary_label_height", primary_label_height_, params);
	setAttribute(prefix, "taylor_secondary_grid", secondary_grid_, params);
	setAttribute(prefix, "taylor_secondary_grid_reference", secondary_reference_, params);
	setAttribute(prefix, "taylor_secondary_grid_increment", secondary_increment_, params);
	setAttribute(prefix, "taylor_secondary_grid_line_thickness", secondary_thickness_, params);
	setAttribute(prefix, "taylor_secondary_label", secondary_label_, params);
	setAttribute(prefix, "taylor_secondary_label_height", secondary_label_height_, params);
	
	setMember(prefix, "taylor_label_colour", label_colour_, params);
	setMember(prefix, "taylor_primary_grid_line_colour", primary_colour_, params);
	setAttribute(prefix, "taylor_primary_grid_line_style", primary_style_, params);
	setMember(prefix, "taylor_reference_line_colour", reference_colour_, params);
	setAttribute(prefix, "taylor_reference_line_style", reference_style_, params);
	setMember(prefix, "taylor_primary_label_colour", primary_label_colour_, params);
	setMember(prefix, "taylor_secondary_grid_line_colour", secondary_colour_, params);
	setAttribute(prefix, "taylor_secondary_grid_line_style", secondary_style_, params);
	setMember(prefix, "taylor_secondary_label_colour", secondary_label_colour_, params);
	
}

void TaylorGridAttributes::copy(const TaylorGridAttributes& other)
{
	label_ = other.label_;
	label_height_ = other.label_height_;
	primary_increment_ = other.primary_increment_;
	primary_thickness_ = other.primary_thickness_;
	primary_reference_ = other.primary_reference_;
	reference_thickness_ = other.reference_thickness_;
	primary_label_ = other.primary_label_;
	primary_label_height_ = other.primary_label_height_;
	secondary_grid_ = other.secondary_grid_;
	secondary_reference_ = other.secondary_reference_;
	secondary_increment_ = other.secondary_increment_;
	secondary_thickness_ = other.secondary_thickness_;
	secondary_label_ = other.secondary_label_;
	secondary_label_height_ = other.secondary_label_height_;
	label_colour_ = unique_ptr<Colour>(other.label_colour_->clone());
	primary_colour_ = unique_ptr<Colour>(other.primary_colour_->clone());
	primary_style_ = other.primary_style_;
	reference_colour_ = unique_ptr<Colour>(other.reference_colour_->clone());
	reference_style_ = other.reference_style_;
	primary_label_colour_ = unique_ptr<Colour>(other.primary_label_colour_->clone());
	secondary_colour_ = unique_ptr<Colour>(other.secondary_colour_->clone());
	secondary_style_ = other.secondary_style_;
	secondary_label_colour_ = unique_ptr<Colour>(other.secondary_label_colour_->clone());
	
}


bool TaylorGridAttributes::accept(const string& node)
{

	if ( magCompare(node, "taylorgrid")  )
		return true;
	
	return false;
}

void TaylorGridAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "taylorgrid")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void TaylorGridAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " label = " <<  label_;
	out << " label_height = " <<  label_height_;
	out << " primary_increment = " <<  primary_increment_;
	out << " primary_thickness = " <<  primary_thickness_;
	out << " primary_reference = " <<  primary_reference_;
	out << " reference_thickness = " <<  reference_thickness_;
	out << " primary_label = " <<  primary_label_;
	out << " primary_label_height = " <<  primary_label_height_;
	out << " secondary_grid = " <<  secondary_grid_;
	out << " secondary_reference = " <<  secondary_reference_;
	out << " secondary_increment = " <<  secondary_increment_;
	out << " secondary_thickness = " <<  secondary_thickness_;
	out << " secondary_label = " <<  secondary_label_;
	out << " secondary_label_height = " <<  secondary_label_height_;
	out << " label_colour = " <<  *label_colour_;
	out << " primary_colour = " <<  *primary_colour_;
	out << " primary_style = " <<  primary_style_;
	out << " reference_colour = " <<  *reference_colour_;
	out << " reference_style = " <<  reference_style_;
	out << " primary_label_colour = " <<  *primary_label_colour_;
	out << " secondary_colour = " <<  *secondary_colour_;
	out << " secondary_style = " <<  secondary_style_;
	out << " secondary_label_colour = " <<  *secondary_label_colour_;
	
	out << "]" << "\n";
}

void TaylorGridAttributes::toxml(ostream& out)  const
{
	out <<  "\"taylorgrid\"";
	out << ", \"taylor_label\":";
	niceprint(out,label_);
	out << ", \"taylor_label_height\":";
	niceprint(out,label_height_);
	out << ", \"taylor_primary_grid_increment\":";
	niceprint(out,primary_increment_);
	out << ", \"taylor_primary_grid_line_thickness\":";
	niceprint(out,primary_thickness_);
	out << ", \"taylor_primary_grid_reference\":";
	niceprint(out,primary_reference_);
	out << ", \"taylor_reference_line_thickness\":";
	niceprint(out,reference_thickness_);
	out << ", \"taylor_primary_label\":";
	niceprint(out,primary_label_);
	out << ", \"taylor_primary_label_height\":";
	niceprint(out,primary_label_height_);
	out << ", \"taylor_secondary_grid\":";
	niceprint(out,secondary_grid_);
	out << ", \"taylor_secondary_grid_reference\":";
	niceprint(out,secondary_reference_);
	out << ", \"taylor_secondary_grid_increment\":";
	niceprint(out,secondary_increment_);
	out << ", \"taylor_secondary_grid_line_thickness\":";
	niceprint(out,secondary_thickness_);
	out << ", \"taylor_secondary_label\":";
	niceprint(out,secondary_label_);
	out << ", \"taylor_secondary_label_height\":";
	niceprint(out,secondary_label_height_);
	out << ", \"taylor_label_colour\":";
	niceprint(out, *label_colour_);
	out << ", \"taylor_primary_grid_line_colour\":";
	niceprint(out, *primary_colour_);
	out << ", \"taylor_primary_grid_line_style\":";
	niceprint(out, primary_style_);
	out << ", \"taylor_reference_line_colour\":";
	niceprint(out, *reference_colour_);
	out << ", \"taylor_reference_line_style\":";
	niceprint(out, reference_style_);
	out << ", \"taylor_primary_label_colour\":";
	niceprint(out, *primary_label_colour_);
	out << ", \"taylor_secondary_grid_line_colour\":";
	niceprint(out, *secondary_colour_);
	out << ", \"taylor_secondary_grid_line_style\":";
	niceprint(out, secondary_style_);
	out << ", \"taylor_secondary_label_colour\":";
	niceprint(out, *secondary_label_colour_);
	
}

static MagicsParameter<string> taylor_label("taylor_label", "Correlation");
static MagicsParameter<double> taylor_label_height("taylor_label_height", 0.35);
static MagicsParameter<double> taylor_primary_grid_increment("taylor_primary_grid_increment", 0.5);
static MagicsParameter<int> taylor_primary_grid_line_thickness("taylor_primary_grid_line_thickness", 1);
static MagicsParameter<double> taylor_primary_grid_reference("taylor_primary_grid_reference", 0.5);
static MagicsParameter<int> taylor_reference_line_thickness("taylor_reference_line_thickness", 2);
static MagicsParameter<string> taylor_primary_label("taylor_primary_label", "on");
static MagicsParameter<double> taylor_primary_label_height("taylor_primary_label_height", 0.35);
static MagicsParameter<string> taylor_secondary_grid("taylor_secondary_grid", "off");
static MagicsParameter<double> taylor_secondary_grid_reference("taylor_secondary_grid_reference", 0.5);
static MagicsParameter<double> taylor_secondary_grid_increment("taylor_secondary_grid_increment", 0.5);
static MagicsParameter<int> taylor_secondary_grid_line_thickness("taylor_secondary_grid_line_thickness", 1);
static MagicsParameter<string> taylor_secondary_label("taylor_secondary_label", "on");
static MagicsParameter<double> taylor_secondary_label_height("taylor_secondary_label_height", 0.35);
static MagicsParameter<string> taylor_label_colour("taylor_label_colour", "navy");
static MagicsParameter<string> taylor_primary_grid_line_colour("taylor_primary_grid_line_colour", "navy");
static MagicsParameter<string> taylor_primary_grid_line_style("taylor_primary_grid_line_style", "solid");
static MagicsParameter<string> taylor_reference_line_colour("taylor_reference_line_colour", "navy");
static MagicsParameter<string> taylor_reference_line_style("taylor_reference_line_style", "solid");
static MagicsParameter<string> taylor_primary_label_colour("taylor_primary_label_colour", "navy");
static MagicsParameter<string> taylor_secondary_grid_line_colour("taylor_secondary_grid_line_colour", "navy");
static MagicsParameter<string> taylor_secondary_grid_line_style("taylor_secondary_grid_line_style", "solid");
static MagicsParameter<string> taylor_secondary_label_colour("taylor_secondary_label_colour", "navy");
