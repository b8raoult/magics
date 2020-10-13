
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SymbolAdvancedTableModeAttributes.h
    \\brief Definition of SymbolAdvancedTableMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "SymbolAdvancedTableModeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

SymbolAdvancedTableModeAttributes::SymbolAdvancedTableModeAttributes():
	min_(ParameterManager::getDouble("symbol_advanced_table_min_value")),
	max_(ParameterManager::getDouble("symbol_advanced_table_max_value")),
	count_(ParameterManager::getInt("symbol_advanced_table_level_count")),
	tolerance_(ParameterManager::getInt("symbol_advanced_table_level_tolerance")),
	interval_(ParameterManager::getDouble("symbol_advanced_table_interval")),
	reference_(ParameterManager::getDouble("symbol_advanced_table_reference_level")),
	list_(ParameterManager::getDoubleArray("symbol_advanced_table_level_list")),
	direction_(ParameterManager::getString("symbol_advanced_table_colour_direction")),
	colours_(ParameterManager::getStringArray("symbol_advanced_table_colour_list")),
	markers_(ParameterManager::getIntArray("symbol_advanced_table_marker_list")),
	markers_names_(ParameterManager::getStringArray("symbol_advanced_table_marker_name_list")),
	height_max_(ParameterManager::getDouble("symbol_advanced_table_height_max_value")),
	height_min_(ParameterManager::getDouble("symbol_advanced_table_height_min_value")),
	heights_(ParameterManager::getDoubleArray("symbol_advanced_table_height_list")),
	text_list_(ParameterManager::getStringArray("symbol_advanced_table_text_list")),
	text_font_name_(ParameterManager::getString("symbol_advanced_table_text_font")),
	text_font_size_(ParameterManager::getDouble("symbol_advanced_table_text_font_size")),
	text_font_style_(ParameterManager::getString("symbol_advanced_table_text_font_style")),
	text_display_type_(ParameterManager::getString("symbol_advanced_table_text_display_type")),
	outlayer_min_(ParameterManager::getDouble("symbol_advanced_table_outlayer_min_value")),
	outlayer_max_(ParameterManager::getDouble("symbol_advanced_table_outlayer_max_value"))
	,
	levels_(MagTranslator<string, LevelSelection>().magics("symbol_advanced_table_selection_type")),
	colourMethod_(MagTranslator<string, ColourTechnique>().magics("symbol_advanced_table_colour_method")),
	maxColour_(MagTranslator<string, Colour>().magics("symbol_advanced_table_max_level_colour")),
	minColour_(MagTranslator<string, Colour>().magics("symbol_advanced_table_min_level_colour")),
	colour_policy_(MagTranslator<string, ListPolicy>().magics("symbol_advanced_table_colour_list_policy")),
	marker_policy_(MagTranslator<string, ListPolicy>().magics("symbol_advanced_table_marker_list_policy")),
	height_method_(MagTranslator<string, HeightTechnique>().magics("symbol_advanced_table_height_method")),
	height_policy_(MagTranslator<string, ListPolicy>().magics("symbol_advanced_table_height_list_policy")),
	text_policy_(MagTranslator<string, ListPolicy>().magics("symbol_advanced_table_text_list_policy")),
	text_font_colour_(MagTranslator<string, Colour>().magics("symbol_advanced_table_text_font_colour")),
	outlayer_(MagTranslator<string, NoOutLayerTechnique>().magics("symbol_advanced_table_outlayer_method"))
	
{
}


SymbolAdvancedTableModeAttributes::~SymbolAdvancedTableModeAttributes()
{

}


void SymbolAdvancedTableModeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "symbol";
	prefix[i++] = "symbol_advanced_table";
	
	setAttribute(prefix, "symbol_advanced_table_min_value", min_, params);
	setAttribute(prefix, "symbol_advanced_table_max_value", max_, params);
	setAttribute(prefix, "symbol_advanced_table_level_count", count_, params);
	setAttribute(prefix, "symbol_advanced_table_level_tolerance", tolerance_, params);
	setAttribute(prefix, "symbol_advanced_table_interval", interval_, params);
	setAttribute(prefix, "symbol_advanced_table_reference_level", reference_, params);
	setAttribute(prefix, "symbol_advanced_table_level_list", list_, params);
	setAttribute(prefix, "symbol_advanced_table_colour_direction", direction_, params);
	setAttribute(prefix, "symbol_advanced_table_colour_list", colours_, params);
	setAttribute(prefix, "symbol_advanced_table_marker_list", markers_, params);
	setAttribute(prefix, "symbol_advanced_table_marker_name_list", markers_names_, params);
	setAttribute(prefix, "symbol_advanced_table_height_max_value", height_max_, params);
	setAttribute(prefix, "symbol_advanced_table_height_min_value", height_min_, params);
	setAttribute(prefix, "symbol_advanced_table_height_list", heights_, params);
	setAttribute(prefix, "symbol_advanced_table_text_list", text_list_, params);
	setAttribute(prefix, "symbol_advanced_table_text_font", text_font_name_, params);
	setAttribute(prefix, "symbol_advanced_table_text_font_size", text_font_size_, params);
	setAttribute(prefix, "symbol_advanced_table_text_font_style", text_font_style_, params);
	setAttribute(prefix, "symbol_advanced_table_text_display_type", text_display_type_, params);
	setAttribute(prefix, "symbol_advanced_table_outlayer_min_value", outlayer_min_, params);
	setAttribute(prefix, "symbol_advanced_table_outlayer_max_value", outlayer_max_, params);
	
	setMember(prefix, "symbol_advanced_table_selection_type", levels_, params);
	setMember(prefix, "symbol_advanced_table_colour_method", colourMethod_, params);
	setMember(prefix, "symbol_advanced_table_max_level_colour", maxColour_, params);
	setMember(prefix, "symbol_advanced_table_min_level_colour", minColour_, params);
	setAttribute(prefix, "symbol_advanced_table_colour_list_policy", colour_policy_, params);
	setAttribute(prefix, "symbol_advanced_table_marker_list_policy", marker_policy_, params);
	setMember(prefix, "symbol_advanced_table_height_method", height_method_, params);
	setAttribute(prefix, "symbol_advanced_table_height_list_policy", height_policy_, params);
	setAttribute(prefix, "symbol_advanced_table_text_list_policy", text_policy_, params);
	setMember(prefix, "symbol_advanced_table_text_font_colour", text_font_colour_, params);
	setMember(prefix, "symbol_advanced_table_outlayer_method", outlayer_, params);
	
}

void SymbolAdvancedTableModeAttributes::copy(const SymbolAdvancedTableModeAttributes& other)
{
	min_ = other.min_;
	max_ = other.max_;
	count_ = other.count_;
	tolerance_ = other.tolerance_;
	interval_ = other.interval_;
	reference_ = other.reference_;
	list_ = other.list_;
	direction_ = other.direction_;
	colours_ = other.colours_;
	markers_ = other.markers_;
	markers_names_ = other.markers_names_;
	height_max_ = other.height_max_;
	height_min_ = other.height_min_;
	heights_ = other.heights_;
	text_list_ = other.text_list_;
	text_font_name_ = other.text_font_name_;
	text_font_size_ = other.text_font_size_;
	text_font_style_ = other.text_font_style_;
	text_display_type_ = other.text_display_type_;
	outlayer_min_ = other.outlayer_min_;
	outlayer_max_ = other.outlayer_max_;
	levels_ = unique_ptr<LevelSelection>(other.levels_->clone());
	colourMethod_ = unique_ptr<ColourTechnique>(other.colourMethod_->clone());
	maxColour_ = unique_ptr<Colour>(other.maxColour_->clone());
	minColour_ = unique_ptr<Colour>(other.minColour_->clone());
	colour_policy_ = other.colour_policy_;
	marker_policy_ = other.marker_policy_;
	height_method_ = unique_ptr<HeightTechnique>(other.height_method_->clone());
	height_policy_ = other.height_policy_;
	text_policy_ = other.text_policy_;
	text_font_colour_ = unique_ptr<Colour>(other.text_font_colour_->clone());
	outlayer_ = unique_ptr<NoOutLayerTechnique>(other.outlayer_->clone());
	
}


bool SymbolAdvancedTableModeAttributes::accept(const string& node)
{

	if ( magCompare(node, "advanced")  )
		return true;
	if ( acceptNode(node, levels_) )
		return true;
	if ( acceptNode(node, colourMethod_) )
		return true;
	if ( acceptNode(node, height_method_) )
		return true;
	if ( acceptNode(node, outlayer_) )
		return true;
	
	return false;
}

void SymbolAdvancedTableModeAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "advanced")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), levels_, node);
		setMember(node.name(), colourMethod_, node);
		setMember(node.name(), height_method_, node);
		setMember(node.name(), outlayer_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), levels_, *elt);
		setMember(elt->name(), colourMethod_, *elt);
		setMember(elt->name(), height_method_, *elt);
		setMember(elt->name(), outlayer_, *elt);
		
	}
}

void SymbolAdvancedTableModeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " min = " <<  min_;
	out << " max = " <<  max_;
	out << " count = " <<  count_;
	out << " tolerance = " <<  tolerance_;
	out << " interval = " <<  interval_;
	out << " reference = " <<  reference_;
	out << " list = " <<  list_;
	out << " direction = " <<  direction_;
	out << " colours = " <<  colours_;
	out << " markers = " <<  markers_;
	out << " markers_names = " <<  markers_names_;
	out << " height_max = " <<  height_max_;
	out << " height_min = " <<  height_min_;
	out << " heights = " <<  heights_;
	out << " text_list = " <<  text_list_;
	out << " text_font_name = " <<  text_font_name_;
	out << " text_font_size = " <<  text_font_size_;
	out << " text_font_style = " <<  text_font_style_;
	out << " text_display_type = " <<  text_display_type_;
	out << " outlayer_min = " <<  outlayer_min_;
	out << " outlayer_max = " <<  outlayer_max_;
	out << " levels = " <<  *levels_;
	out << " colourMethod = " <<  *colourMethod_;
	out << " maxColour = " <<  *maxColour_;
	out << " minColour = " <<  *minColour_;
	out << " colour_policy = " <<  colour_policy_;
	out << " marker_policy = " <<  marker_policy_;
	out << " height_method = " <<  *height_method_;
	out << " height_policy = " <<  height_policy_;
	out << " text_policy = " <<  text_policy_;
	out << " text_font_colour = " <<  *text_font_colour_;
	out << " outlayer = " <<  *outlayer_;
	
	out << "]" << "\n";
}

void SymbolAdvancedTableModeAttributes::toxml(ostream& out)  const
{
	out <<  "\"advanced\"";
	out << ", \"symbol_advanced_table_min_value\":";
	niceprint(out,min_);
	out << ", \"symbol_advanced_table_max_value\":";
	niceprint(out,max_);
	out << ", \"symbol_advanced_table_level_count\":";
	niceprint(out,count_);
	out << ", \"symbol_advanced_table_level_tolerance\":";
	niceprint(out,tolerance_);
	out << ", \"symbol_advanced_table_interval\":";
	niceprint(out,interval_);
	out << ", \"symbol_advanced_table_reference_level\":";
	niceprint(out,reference_);
	out << ", \"symbol_advanced_table_level_list\":";
	niceprint(out,list_);
	out << ", \"symbol_advanced_table_colour_direction\":";
	niceprint(out,direction_);
	out << ", \"symbol_advanced_table_colour_list\":";
	niceprint(out,colours_);
	out << ", \"symbol_advanced_table_marker_list\":";
	niceprint(out,markers_);
	out << ", \"symbol_advanced_table_marker_name_list\":";
	niceprint(out,markers_names_);
	out << ", \"symbol_advanced_table_height_max_value\":";
	niceprint(out,height_max_);
	out << ", \"symbol_advanced_table_height_min_value\":";
	niceprint(out,height_min_);
	out << ", \"symbol_advanced_table_height_list\":";
	niceprint(out,heights_);
	out << ", \"symbol_advanced_table_text_list\":";
	niceprint(out,text_list_);
	out << ", \"symbol_advanced_table_text_font\":";
	niceprint(out,text_font_name_);
	out << ", \"symbol_advanced_table_text_font_size\":";
	niceprint(out,text_font_size_);
	out << ", \"symbol_advanced_table_text_font_style\":";
	niceprint(out,text_font_style_);
	out << ", \"symbol_advanced_table_text_display_type\":";
	niceprint(out,text_display_type_);
	out << ", \"symbol_advanced_table_outlayer_min_value\":";
	niceprint(out,outlayer_min_);
	out << ", \"symbol_advanced_table_outlayer_max_value\":";
	niceprint(out,outlayer_max_);
	out << ", \"symbol_advanced_table_selection_type\":";
	levels_->toxml(out);
	out << ", \"symbol_advanced_table_colour_method\":";
	colourMethod_->toxml(out);
	out << ", \"symbol_advanced_table_max_level_colour\":";
	niceprint(out, *maxColour_);
	out << ", \"symbol_advanced_table_min_level_colour\":";
	niceprint(out, *minColour_);
	out << ", \"symbol_advanced_table_colour_list_policy\":";
	niceprint(out, colour_policy_);
	out << ", \"symbol_advanced_table_marker_list_policy\":";
	niceprint(out, marker_policy_);
	out << ", \"symbol_advanced_table_height_method\":";
	height_method_->toxml(out);
	out << ", \"symbol_advanced_table_height_list_policy\":";
	niceprint(out, height_policy_);
	out << ", \"symbol_advanced_table_text_list_policy\":";
	niceprint(out, text_policy_);
	out << ", \"symbol_advanced_table_text_font_colour\":";
	niceprint(out, *text_font_colour_);
	out << ", \"symbol_advanced_table_outlayer_method\":";
	outlayer_->toxml(out);
	
}

static MagicsParameter<double> symbol_advanced_table_min_value("symbol_advanced_table_min_value", -1.e21);
static MagicsParameter<double> symbol_advanced_table_max_value("symbol_advanced_table_max_value", 1.e21);
static MagicsParameter<int> symbol_advanced_table_level_count("symbol_advanced_table_level_count", 10);
static MagicsParameter<int> symbol_advanced_table_level_tolerance("symbol_advanced_table_level_tolerance", 2);
static MagicsParameter<double> symbol_advanced_table_interval("symbol_advanced_table_interval", 8.0);
static MagicsParameter<double> symbol_advanced_table_reference_level("symbol_advanced_table_reference_level", 0.0);
static MagicsParameter<doublearray> symbol_advanced_table_level_list("symbol_advanced_table_level_list", floatarray());
static MagicsParameter<string> symbol_advanced_table_colour_direction("symbol_advanced_table_colour_direction", "anti_clockwise");
static MagicsParameter<stringarray> symbol_advanced_table_colour_list("symbol_advanced_table_colour_list", stringarray());
static MagicsParameter<intarray> symbol_advanced_table_marker_list("symbol_advanced_table_marker_list", intarray());
static MagicsParameter<stringarray> symbol_advanced_table_marker_name_list("symbol_advanced_table_marker_name_list", stringarray());
static MagicsParameter<double> symbol_advanced_table_height_max_value("symbol_advanced_table_height_max_value", 0.2);
static MagicsParameter<double> symbol_advanced_table_height_min_value("symbol_advanced_table_height_min_value", 0.1);
static MagicsParameter<doublearray> symbol_advanced_table_height_list("symbol_advanced_table_height_list", floatarray());
static MagicsParameter<stringarray> symbol_advanced_table_text_list("symbol_advanced_table_text_list", stringarray());
static MagicsParameter<string> symbol_advanced_table_text_font("symbol_advanced_table_text_font", "sansserif");
static MagicsParameter<double> symbol_advanced_table_text_font_size("symbol_advanced_table_text_font_size", 0.25);
static MagicsParameter<string> symbol_advanced_table_text_font_style("symbol_advanced_table_text_font_style", "normal");
static MagicsParameter<string> symbol_advanced_table_text_display_type("symbol_advanced_table_text_display_type", "none");
static MagicsParameter<double> symbol_advanced_table_outlayer_min_value("symbol_advanced_table_outlayer_min_value", -1.e21);
static MagicsParameter<double> symbol_advanced_table_outlayer_max_value("symbol_advanced_table_outlayer_max_value", 1.e21);
static MagicsParameter<string> symbol_advanced_table_selection_type("symbol_advanced_table_selection_type", "count");
static MagicsParameter<string> symbol_advanced_table_colour_method("symbol_advanced_table_colour_method", "calculate");
static MagicsParameter<string> symbol_advanced_table_max_level_colour("symbol_advanced_table_max_level_colour", "blue");
static MagicsParameter<string> symbol_advanced_table_min_level_colour("symbol_advanced_table_min_level_colour", "red");
static MagicsParameter<string> symbol_advanced_table_colour_list_policy("symbol_advanced_table_colour_list_policy", "lastone");
static MagicsParameter<string> symbol_advanced_table_marker_list_policy("symbol_advanced_table_marker_list_policy", "lastone");
static MagicsParameter<string> symbol_advanced_table_height_method("symbol_advanced_table_height_method", "list");
static MagicsParameter<string> symbol_advanced_table_height_list_policy("symbol_advanced_table_height_list_policy", "lastone");
static MagicsParameter<string> symbol_advanced_table_text_list_policy("symbol_advanced_table_text_list_policy", "cycle");
static MagicsParameter<string> symbol_advanced_table_text_font_colour("symbol_advanced_table_text_font_colour", "automatic");
static MagicsParameter<string> symbol_advanced_table_outlayer_method("symbol_advanced_table_outlayer_method", "none");
#include "CountSelectionType.h"
#include "IntervalSelectionType.h"
#include "LevelListSelectionType.h"
#include "CalculateColourTechnique.h"
#include "ListColourTechnique.h"
#include "HeightTechnique.h"
#include "OutLayerTechnique.h"
static SimpleObjectMaker<CountSelectionType , LevelSelection> count_CountSelectionType("count");
static SimpleObjectMaker<IntervalSelectionType , LevelSelection> interval_IntervalSelectionType("interval");
static SimpleObjectMaker<LevelListSelectionType , LevelSelection> list_LevelListSelectionType("list");
static SimpleObjectMaker<CalculateColourTechnique , ColourTechnique> calculate_CalculateColourTechnique("calculate");
static SimpleObjectMaker<ListColourTechnique , ColourTechnique> list_ListColourTechnique("list");
static SimpleObjectMaker<CalculateHeightTechnique , HeightTechnique> calculate_CalculateHeightTechnique("calculate");
static SimpleObjectMaker<ListHeightTechnique , HeightTechnique> list_ListHeightTechnique("list");
static SimpleObjectMaker<NoOutLayerTechnique , NoOutLayerTechnique> nooutlayer_NoOutLayerTechnique("nooutlayer");
static SimpleObjectMaker<NoOutLayerTechnique , NoOutLayerTechnique> none_NoOutLayerTechnique("none");
static SimpleObjectMaker<SimpleOutLayerTechnique , NoOutLayerTechnique> simple_SimpleOutLayerTechnique("simple");
