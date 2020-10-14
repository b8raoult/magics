
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LegendVisitorAttributes.h
    \\brief Definition of LegendVisitor Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "LegendVisitorAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

LegendVisitorAttributes::LegendVisitorAttributes():
	title_(ParameterManager::getBool("legend_title")),
	title_text_(ParameterManager::getString("legend_title_text")),
	title_orientation_(ParameterManager::getString("legend_title_orientation")),
	title_font_size_(ParameterManager::getDouble("legend_title_font_size")),
	title_ratio_(ParameterManager::getDouble("legend_title_position_ratio")),
	units_text_(ParameterManager::getString("legend_units_text")),
	use_min_(ParameterManager::getBool("legend_user_minimum")),
	use_min_text_(ParameterManager::getString("legend_user_minimum_text")),
	use_max_(ParameterManager::getBool("legend_user_maximum")),
	use_max_text_(ParameterManager::getString("legend_user_maximum_text")),
	format_(ParameterManager::getString("legend_text_format")),
	box_(ParameterManager::getString("legend_box_mode")),
	box_position_(ParameterManager::getString("legend_automatic_position")),
	box_margin_(ParameterManager::getDouble("legend_automatic_box_margin")),
	font_(ParameterManager::getString("legend_text_font")),
	font_style_(ParameterManager::getString("legend_text_font_style")),
	font_dimension_(ParameterManager::getString("legend_text_font_size")),
	text_quality_(ParameterManager::getString("legend_text_quality")),
	orientation_(ParameterManager::getDouble("legend_text_orientation")),
	lines_(ParameterManager::getStringArray("legend_user_lines")),
	columns_(ParameterManager::getInt("legend_column_count")),
	direction_(ParameterManager::getString("legend_entry_plot_direction")),
	entry_orientation_(ParameterManager::getString("legend_entry_plot_orientation")),
	composition_(ParameterManager::getString("legend_text_composition")),
	values_list_(ParameterManager::getDoubleArray("legend_values_list")),
	text_(ParameterManager::getString("legend_user_text")),
	text1_(ParameterManager::getString("legend_user_text_1")),
	text2_(ParameterManager::getString("legend_user_text_2")),
	text3_(ParameterManager::getString("legend_user_text_3")),
	text4_(ParameterManager::getString("legend_user_text_4")),
	text5_(ParameterManager::getString("legend_user_text_5")),
	text6_(ParameterManager::getString("legend_user_text_6")),
	text7_(ParameterManager::getString("legend_user_text_7")),
	text8_(ParameterManager::getString("legend_user_text_8")),
	text9_(ParameterManager::getString("legend_user_text_9")),
	text10_(ParameterManager::getString("legend_user_text_10")),
	symbol_factor_(ParameterManager::getDouble("legend_symbol_height_factor")),
	box_x_(ParameterManager::getDouble("legend_box_x_position")),
	box_y_(ParameterManager::getDouble("legend_box_y_position")),
	box_width_(ParameterManager::getDouble("legend_box_x_length")),
	box_height_(ParameterManager::getDouble("legend_box_y_length")),
	blanking_(ParameterManager::getBool("legend_box_blanking")),
	border_(ParameterManager::getBool("legend_border")),
	border_thickness_(ParameterManager::getInt("legend_border_thickness")),
	wrep_(ParameterManager::getBool("legend_wrep")),
	only_(ParameterManager::getBool("legend_only")),
	text_width_(ParameterManager::getDouble("legend_entry_text_width")),
	entry_border_(ParameterManager::getBool("legend_entry_border"))
	,
	colour_(MagTranslator<string, Colour>().magics("legend_text_colour")),
	title_font_colour_(MagTranslator<string, Colour>().magics("legend_title_font_colour")),
	title_position_(MagTranslator<string, Position>().magics("legend_title_position")),
	method_(MagTranslator<string, LegendMethod>().magics("legend_display_type")),
	border_line_style_(MagTranslator<string, LineStyle>().magics("legend_border_line_style")),
	border_colour_(MagTranslator<string, Colour>().magics("legend_border_colour")),
	entry_border_colour_(MagTranslator<string, Colour>().magics("legend_entry_border_colour"))
	
{
}


LegendVisitorAttributes::~LegendVisitorAttributes()
{

}


void LegendVisitorAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "legend";
	
	setAttribute(prefix, "legend_title", title_, params);
	setAttribute(prefix, "legend_title_text", title_text_, params);
	setAttribute(prefix, "legend_title_orientation", title_orientation_, params);
	setAttribute(prefix, "legend_title_font_size", title_font_size_, params);
	setAttribute(prefix, "legend_title_position_ratio", title_ratio_, params);
	setAttribute(prefix, "legend_units_text", units_text_, params);
	setAttribute(prefix, "legend_user_minimum", use_min_, params);
	setAttribute(prefix, "legend_user_minimum_text", use_min_text_, params);
	setAttribute(prefix, "legend_user_maximum", use_max_, params);
	setAttribute(prefix, "legend_user_maximum_text", use_max_text_, params);
	setAttribute(prefix, "legend_text_format", format_, params);
	setAttribute(prefix, "legend_box_mode", box_, params);
	setAttribute(prefix, "legend_automatic_position", box_position_, params);
	setAttribute(prefix, "legend_automatic_box_margin", box_margin_, params);
	setAttribute(prefix, "legend_text_font", font_, params);
	setAttribute(prefix, "legend_text_font_style", font_style_, params);
	setAttribute(prefix, "legend_text_font_size", font_dimension_, params);
	setAttribute(prefix, "legend_text_quality", text_quality_, params);
	setAttribute(prefix, "legend_text_orientation", orientation_, params);
	setAttribute(prefix, "legend_user_lines", lines_, params);
	setAttribute(prefix, "legend_column_count", columns_, params);
	setAttribute(prefix, "legend_entry_plot_direction", direction_, params);
	setAttribute(prefix, "legend_entry_plot_orientation", entry_orientation_, params);
	setAttribute(prefix, "legend_text_composition", composition_, params);
	setAttribute(prefix, "legend_values_list", values_list_, params);
	setAttribute(prefix, "legend_user_text", text_, params);
	setAttribute(prefix, "legend_user_text_1", text1_, params);
	setAttribute(prefix, "legend_user_text_2", text2_, params);
	setAttribute(prefix, "legend_user_text_3", text3_, params);
	setAttribute(prefix, "legend_user_text_4", text4_, params);
	setAttribute(prefix, "legend_user_text_5", text5_, params);
	setAttribute(prefix, "legend_user_text_6", text6_, params);
	setAttribute(prefix, "legend_user_text_7", text7_, params);
	setAttribute(prefix, "legend_user_text_8", text8_, params);
	setAttribute(prefix, "legend_user_text_9", text9_, params);
	setAttribute(prefix, "legend_user_text_10", text10_, params);
	setAttribute(prefix, "legend_symbol_height_factor", symbol_factor_, params);
	setAttribute(prefix, "legend_box_x_position", box_x_, params);
	setAttribute(prefix, "legend_box_y_position", box_y_, params);
	setAttribute(prefix, "legend_box_x_length", box_width_, params);
	setAttribute(prefix, "legend_box_y_length", box_height_, params);
	setAttribute(prefix, "legend_box_blanking", blanking_, params);
	setAttribute(prefix, "legend_border", border_, params);
	setAttribute(prefix, "legend_border_thickness", border_thickness_, params);
	setAttribute(prefix, "legend_wrep", wrep_, params);
	setAttribute(prefix, "legend_only", only_, params);
	setAttribute(prefix, "legend_entry_text_width", text_width_, params);
	setAttribute(prefix, "legend_entry_border", entry_border_, params);
	
	setMember(prefix, "legend_text_colour", colour_, params);
	setMember(prefix, "legend_title_font_colour", title_font_colour_, params);
	setAttribute(prefix, "legend_title_position", title_position_, params);
	setMember(prefix, "legend_display_type", method_, params);
	setAttribute(prefix, "legend_border_line_style", border_line_style_, params);
	setMember(prefix, "legend_border_colour", border_colour_, params);
	setMember(prefix, "legend_entry_border_colour", entry_border_colour_, params);
	
}

void LegendVisitorAttributes::copy(const LegendVisitorAttributes& other)
{
	title_ = other.title_;
	title_text_ = other.title_text_;
	title_orientation_ = other.title_orientation_;
	title_font_size_ = other.title_font_size_;
	title_ratio_ = other.title_ratio_;
	units_text_ = other.units_text_;
	use_min_ = other.use_min_;
	use_min_text_ = other.use_min_text_;
	use_max_ = other.use_max_;
	use_max_text_ = other.use_max_text_;
	format_ = other.format_;
	box_ = other.box_;
	box_position_ = other.box_position_;
	box_margin_ = other.box_margin_;
	font_ = other.font_;
	font_style_ = other.font_style_;
	font_dimension_ = other.font_dimension_;
	text_quality_ = other.text_quality_;
	orientation_ = other.orientation_;
	lines_ = other.lines_;
	columns_ = other.columns_;
	direction_ = other.direction_;
	entry_orientation_ = other.entry_orientation_;
	composition_ = other.composition_;
	values_list_ = other.values_list_;
	text_ = other.text_;
	text1_ = other.text1_;
	text2_ = other.text2_;
	text3_ = other.text3_;
	text4_ = other.text4_;
	text5_ = other.text5_;
	text6_ = other.text6_;
	text7_ = other.text7_;
	text8_ = other.text8_;
	text9_ = other.text9_;
	text10_ = other.text10_;
	symbol_factor_ = other.symbol_factor_;
	box_x_ = other.box_x_;
	box_y_ = other.box_y_;
	box_width_ = other.box_width_;
	box_height_ = other.box_height_;
	blanking_ = other.blanking_;
	border_ = other.border_;
	border_thickness_ = other.border_thickness_;
	wrep_ = other.wrep_;
	only_ = other.only_;
	text_width_ = other.text_width_;
	entry_border_ = other.entry_border_;
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	title_font_colour_ = unique_ptr<Colour>(other.title_font_colour_->clone());
	title_position_ = other.title_position_;
	method_ = unique_ptr<LegendMethod>(other.method_->clone());
	border_line_style_ = other.border_line_style_;
	border_colour_ = unique_ptr<Colour>(other.border_colour_->clone());
	entry_border_colour_ = unique_ptr<Colour>(other.entry_border_colour_->clone());
	
}


bool LegendVisitorAttributes::accept(const string& node)
{

	if ( magCompare(node, "legend")  )
		return true;
	if ( magCompare(node, "zlegend")  )
		return true;
	if ( acceptNode(node, method_) )
		return true;
	
	return false;
}

void LegendVisitorAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "legend")  )
		apply = true;
	if ( magCompare(node.name(), "zlegend")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), method_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), method_, *elt);
		
	}
}

void LegendVisitorAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " title = " <<  title_;
	out << " title_text = " <<  title_text_;
	out << " title_orientation = " <<  title_orientation_;
	out << " title_font_size = " <<  title_font_size_;
	out << " title_ratio = " <<  title_ratio_;
	out << " units_text = " <<  units_text_;
	out << " use_min = " <<  use_min_;
	out << " use_min_text = " <<  use_min_text_;
	out << " use_max = " <<  use_max_;
	out << " use_max_text = " <<  use_max_text_;
	out << " format = " <<  format_;
	out << " box = " <<  box_;
	out << " box_position = " <<  box_position_;
	out << " box_margin = " <<  box_margin_;
	out << " font = " <<  font_;
	out << " font_style = " <<  font_style_;
	out << " font_dimension = " <<  font_dimension_;
	out << " text_quality = " <<  text_quality_;
	out << " orientation = " <<  orientation_;
	out << " lines = " <<  lines_;
	out << " columns = " <<  columns_;
	out << " direction = " <<  direction_;
	out << " entry_orientation = " <<  entry_orientation_;
	out << " composition = " <<  composition_;
	out << " values_list = " <<  values_list_;
	out << " text = " <<  text_;
	out << " text1 = " <<  text1_;
	out << " text2 = " <<  text2_;
	out << " text3 = " <<  text3_;
	out << " text4 = " <<  text4_;
	out << " text5 = " <<  text5_;
	out << " text6 = " <<  text6_;
	out << " text7 = " <<  text7_;
	out << " text8 = " <<  text8_;
	out << " text9 = " <<  text9_;
	out << " text10 = " <<  text10_;
	out << " symbol_factor = " <<  symbol_factor_;
	out << " box_x = " <<  box_x_;
	out << " box_y = " <<  box_y_;
	out << " box_width = " <<  box_width_;
	out << " box_height = " <<  box_height_;
	out << " blanking = " <<  blanking_;
	out << " border = " <<  border_;
	out << " border_thickness = " <<  border_thickness_;
	out << " wrep = " <<  wrep_;
	out << " only = " <<  only_;
	out << " text_width = " <<  text_width_;
	out << " entry_border = " <<  entry_border_;
	out << " colour = " <<  *colour_;
	out << " title_font_colour = " <<  *title_font_colour_;
	out << " title_position = " <<  title_position_;
	out << " method = " <<  *method_;
	out << " border_line_style = " <<  border_line_style_;
	out << " border_colour = " <<  *border_colour_;
	out << " entry_border_colour = " <<  *entry_border_colour_;
	
	out << "]" << "\n";
}

void LegendVisitorAttributes::toxml(ostream& out)  const
{
	out <<  "\"legend\"";
	out << ", \"legend_title\":";
	niceprint(out,title_);
	out << ", \"legend_title_text\":";
	niceprint(out,title_text_);
	out << ", \"legend_title_orientation\":";
	niceprint(out,title_orientation_);
	out << ", \"legend_title_font_size\":";
	niceprint(out,title_font_size_);
	out << ", \"legend_title_position_ratio\":";
	niceprint(out,title_ratio_);
	out << ", \"legend_units_text\":";
	niceprint(out,units_text_);
	out << ", \"legend_user_minimum\":";
	niceprint(out,use_min_);
	out << ", \"legend_user_minimum_text\":";
	niceprint(out,use_min_text_);
	out << ", \"legend_user_maximum\":";
	niceprint(out,use_max_);
	out << ", \"legend_user_maximum_text\":";
	niceprint(out,use_max_text_);
	out << ", \"legend_text_format\":";
	niceprint(out,format_);
	out << ", \"legend_box_mode\":";
	niceprint(out,box_);
	out << ", \"legend_automatic_position\":";
	niceprint(out,box_position_);
	out << ", \"legend_automatic_box_margin\":";
	niceprint(out,box_margin_);
	out << ", \"legend_text_font\":";
	niceprint(out,font_);
	out << ", \"legend_text_font_style\":";
	niceprint(out,font_style_);
	out << ", \"legend_text_font_size\":";
	niceprint(out,font_dimension_);
	out << ", \"legend_text_quality\":";
	niceprint(out,text_quality_);
	out << ", \"legend_text_orientation\":";
	niceprint(out,orientation_);
	out << ", \"legend_user_lines\":";
	niceprint(out,lines_);
	out << ", \"legend_column_count\":";
	niceprint(out,columns_);
	out << ", \"legend_entry_plot_direction\":";
	niceprint(out,direction_);
	out << ", \"legend_entry_plot_orientation\":";
	niceprint(out,entry_orientation_);
	out << ", \"legend_text_composition\":";
	niceprint(out,composition_);
	out << ", \"legend_values_list\":";
	niceprint(out,values_list_);
	out << ", \"legend_user_text\":";
	niceprint(out,text_);
	out << ", \"legend_user_text_1\":";
	niceprint(out,text1_);
	out << ", \"legend_user_text_2\":";
	niceprint(out,text2_);
	out << ", \"legend_user_text_3\":";
	niceprint(out,text3_);
	out << ", \"legend_user_text_4\":";
	niceprint(out,text4_);
	out << ", \"legend_user_text_5\":";
	niceprint(out,text5_);
	out << ", \"legend_user_text_6\":";
	niceprint(out,text6_);
	out << ", \"legend_user_text_7\":";
	niceprint(out,text7_);
	out << ", \"legend_user_text_8\":";
	niceprint(out,text8_);
	out << ", \"legend_user_text_9\":";
	niceprint(out,text9_);
	out << ", \"legend_user_text_10\":";
	niceprint(out,text10_);
	out << ", \"legend_symbol_height_factor\":";
	niceprint(out,symbol_factor_);
	out << ", \"legend_box_x_position\":";
	niceprint(out,box_x_);
	out << ", \"legend_box_y_position\":";
	niceprint(out,box_y_);
	out << ", \"legend_box_x_length\":";
	niceprint(out,box_width_);
	out << ", \"legend_box_y_length\":";
	niceprint(out,box_height_);
	out << ", \"legend_box_blanking\":";
	niceprint(out,blanking_);
	out << ", \"legend_border\":";
	niceprint(out,border_);
	out << ", \"legend_border_thickness\":";
	niceprint(out,border_thickness_);
	out << ", \"legend_wrep\":";
	niceprint(out,wrep_);
	out << ", \"legend_only\":";
	niceprint(out,only_);
	out << ", \"legend_entry_text_width\":";
	niceprint(out,text_width_);
	out << ", \"legend_entry_border\":";
	niceprint(out,entry_border_);
	out << ", \"legend_text_colour\":";
	niceprint(out, *colour_);
	out << ", \"legend_title_font_colour\":";
	niceprint(out, *title_font_colour_);
	out << ", \"legend_title_position\":";
	niceprint(out, title_position_);
	out << ", \"legend_display_type\":";
	method_->toxml(out);
	out << ", \"legend_border_line_style\":";
	niceprint(out, border_line_style_);
	out << ", \"legend_border_colour\":";
	niceprint(out, *border_colour_);
	out << ", \"legend_entry_border_colour\":";
	niceprint(out, *entry_border_colour_);
	
}

static MagicsParameter<string> legend_title("legend_title", "off");
static MagicsParameter<string> legend_title_text("legend_title_text", "legend");
static MagicsParameter<string> legend_title_orientation("legend_title_orientation", "automatic");
static MagicsParameter<double> legend_title_font_size("legend_title_font_size", -1);
static MagicsParameter<double> legend_title_position_ratio("legend_title_position_ratio", 25);
static MagicsParameter<string> legend_units_text("legend_units_text", "");
static MagicsParameter<string> legend_user_minimum("legend_user_minimum", "off");
static MagicsParameter<string> legend_user_minimum_text("legend_user_minimum_text", "");
static MagicsParameter<string> legend_user_maximum("legend_user_maximum", "off");
static MagicsParameter<string> legend_user_maximum_text("legend_user_maximum_text", "");
static MagicsParameter<string> legend_text_format("legend_text_format", "(automatic)");
static MagicsParameter<string> legend_box_mode("legend_box_mode", "automatic");
static MagicsParameter<string> legend_automatic_position("legend_automatic_position", "top");
static MagicsParameter<double> legend_automatic_box_margin("legend_automatic_box_margin", 5);
static MagicsParameter<string> legend_text_font("legend_text_font", "sansserif");
static MagicsParameter<string> legend_text_font_style("legend_text_font_style", "normal");
static MagicsParameter<string> legend_text_font_size("legend_text_font_size", "0.3");
static MagicsParameter<string> legend_text_quality("legend_text_quality", "medium");
static MagicsParameter<double> legend_text_orientation("legend_text_orientation", 0);
static MagicsParameter<stringarray> legend_user_lines("legend_user_lines", stringarray());
static MagicsParameter<int> legend_column_count("legend_column_count", 1);
static MagicsParameter<string> legend_entry_plot_direction("legend_entry_plot_direction", "automatic");
static MagicsParameter<string> legend_entry_plot_orientation("legend_entry_plot_orientation", "bottom_top");
static MagicsParameter<string> legend_text_composition("legend_text_composition", "automatic_text_only");
static MagicsParameter<doublearray> legend_values_list("legend_values_list", floatarray());
static MagicsParameter<string> legend_user_text("legend_user_text", "");
static MagicsParameter<string> legend_user_text_1("legend_user_text_1", "");
static MagicsParameter<string> legend_user_text_2("legend_user_text_2", "");
static MagicsParameter<string> legend_user_text_3("legend_user_text_3", "");
static MagicsParameter<string> legend_user_text_4("legend_user_text_4", "");
static MagicsParameter<string> legend_user_text_5("legend_user_text_5", "");
static MagicsParameter<string> legend_user_text_6("legend_user_text_6", "");
static MagicsParameter<string> legend_user_text_7("legend_user_text_7", "");
static MagicsParameter<string> legend_user_text_8("legend_user_text_8", "");
static MagicsParameter<string> legend_user_text_9("legend_user_text_9", "");
static MagicsParameter<string> legend_user_text_10("legend_user_text_10", "");
static MagicsParameter<double> legend_symbol_height_factor("legend_symbol_height_factor", 1);
static MagicsParameter<double> legend_box_x_position("legend_box_x_position", -1);
static MagicsParameter<double> legend_box_y_position("legend_box_y_position", -1);
static MagicsParameter<double> legend_box_x_length("legend_box_x_length", -1);
static MagicsParameter<double> legend_box_y_length("legend_box_y_length", 0);
static MagicsParameter<string> legend_box_blanking("legend_box_blanking", "off");
static MagicsParameter<string> legend_border("legend_border", "off");
static MagicsParameter<int> legend_border_thickness("legend_border_thickness", 1);
static MagicsParameter<string> legend_wrep("legend_wrep", "off");
static MagicsParameter<string> legend_only("legend_only", "off");
static MagicsParameter<double> legend_entry_text_width("legend_entry_text_width", 60);
static MagicsParameter<string> legend_entry_border("legend_entry_border", "on");
static MagicsParameter<string> legend_text_colour("legend_text_colour", "blue");
static MagicsParameter<string> legend_title_font_colour("legend_title_font_colour", "automatic");
static MagicsParameter<string> legend_title_position("legend_title_position", "automatic");
static MagicsParameter<string> legend_display_type("legend_display_type", "disjoint");
static MagicsParameter<string> legend_border_line_style("legend_border_line_style", "solid");
static MagicsParameter<string> legend_border_colour("legend_border_colour", "blue");
static MagicsParameter<string> legend_entry_border_colour("legend_entry_border_colour", "black");
#include "LegendMethod.h"
static SimpleObjectMaker<LegendMethod , LegendMethod> disjoint_LegendMethod("disjoint");
static SimpleObjectMaker<ContinuousLegendMethod , LegendMethod> continuous_ContinuousLegendMethod("continuous");
static SimpleObjectMaker<HistogramLegendMethod , LegendMethod> histogram_HistogramLegendMethod("histogram");
