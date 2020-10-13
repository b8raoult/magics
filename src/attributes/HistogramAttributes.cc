
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file HistogramAttributes.h
    \\brief Definition of Histogram Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "HistogramAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

HistogramAttributes::HistogramAttributes():
	min_(ParameterManager::getDouble("histogram_min_value")),
	max_(ParameterManager::getDouble("histogram_max_value")),
	count_(ParameterManager::getInt("histogram_level_count")),
	tolerance_(ParameterManager::getInt("histogram_level_tolerance")),
	reference_(ParameterManager::getDouble("histogram_reference_level")),
	interval_(ParameterManager::getDouble("histogram_interval")),
	list_(ParameterManager::getDoubleArray("histogram_level_list")),
	width_(ParameterManager::getDouble("histogram_bar_width"))
	,
	levels_(MagTranslator<string, LevelSelection>().magics("histogram_selection_type")),
	colour_(MagTranslator<string, Colour>().magics("histogram_bar_colour"))
	
{
}


HistogramAttributes::~HistogramAttributes()
{

}


void HistogramAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	setAttribute(prefix, "histogram_min_value", min_, params);
	setAttribute(prefix, "histogram_max_value", max_, params);
	setAttribute(prefix, "histogram_level_count", count_, params);
	setAttribute(prefix, "histogram_level_tolerance", tolerance_, params);
	setAttribute(prefix, "histogram_reference_level", reference_, params);
	setAttribute(prefix, "histogram_interval", interval_, params);
	setAttribute(prefix, "histogram_level_list", list_, params);
	setAttribute(prefix, "histogram_bar_width", width_, params);
	
	setMember(prefix, "histogram_selection_type", levels_, params);
	setMember(prefix, "histogram_bar_colour", colour_, params);
	
}

void HistogramAttributes::copy(const HistogramAttributes& other)
{
	min_ = other.min_;
	max_ = other.max_;
	count_ = other.count_;
	tolerance_ = other.tolerance_;
	reference_ = other.reference_;
	interval_ = other.interval_;
	list_ = other.list_;
	width_ = other.width_;
	levels_ = unique_ptr<LevelSelection>(other.levels_->clone());
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	
}


bool HistogramAttributes::accept(const string& node)
{

	if ( magCompare(node, "histogram")  )
		return true;
	if ( acceptNode(node, levels_) )
		return true;
	
	return false;
}

void HistogramAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "histogram")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), levels_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), levels_, *elt);
		
	}
}

void HistogramAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " min = " <<  min_;
	out << " max = " <<  max_;
	out << " count = " <<  count_;
	out << " tolerance = " <<  tolerance_;
	out << " reference = " <<  reference_;
	out << " interval = " <<  interval_;
	out << " list = " <<  list_;
	out << " width = " <<  width_;
	out << " levels = " <<  *levels_;
	out << " colour = " <<  *colour_;
	
	out << "]" << "\n";
}

void HistogramAttributes::toxml(ostream& out)  const
{
	out <<  "\"histogram\"";
	out << ", \"histogram_min_value\":";
	niceprint(out,min_);
	out << ", \"histogram_max_value\":";
	niceprint(out,max_);
	out << ", \"histogram_level_count\":";
	niceprint(out,count_);
	out << ", \"histogram_level_tolerance\":";
	niceprint(out,tolerance_);
	out << ", \"histogram_reference_level\":";
	niceprint(out,reference_);
	out << ", \"histogram_interval\":";
	niceprint(out,interval_);
	out << ", \"histogram_level_list\":";
	niceprint(out,list_);
	out << ", \"histogram_bar_width\":";
	niceprint(out,width_);
	out << ", \"histogram_selection_type\":";
	levels_->toxml(out);
	out << ", \"histogram_bar_colour\":";
	niceprint(out, *colour_);
	
}

static MagicsParameter<double> histogram_min_value("histogram_min_value", -1.e21);
static MagicsParameter<double> histogram_max_value("histogram_max_value", 1.e21);
static MagicsParameter<int> histogram_level_count("histogram_level_count", 10);
static MagicsParameter<int> histogram_level_tolerance("histogram_level_tolerance", 2);
static MagicsParameter<double> histogram_reference_level("histogram_reference_level", 0.0);
static MagicsParameter<double> histogram_interval("histogram_interval", 8.0);
static MagicsParameter<doublearray> histogram_level_list("histogram_level_list", floatarray());
static MagicsParameter<double> histogram_bar_width("histogram_bar_width", 1);
static MagicsParameter<string> histogram_selection_type("histogram_selection_type", "count");
static MagicsParameter<string> histogram_bar_colour("histogram_bar_colour", "evergreen");
#include "CountSelectionType.h"
#include "IntervalSelectionType.h"
#include "LevelListSelectionType.h"
static SimpleObjectMaker<CountSelectionType , LevelSelection> count_CountSelectionType("count");
static SimpleObjectMaker<IntervalSelectionType , LevelSelection> interval_IntervalSelectionType("interval");
static SimpleObjectMaker<LevelListSelectionType , LevelSelection> list_LevelListSelectionType("list");
