
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file BoxPlotDecoderAttributes.h
    \\brief Definition of BoxPlotDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "BoxPlotDecoderAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

BoxPlotDecoderAttributes::BoxPlotDecoderAttributes():
	x_(ParameterManager::getDoubleArray("boxplot_positions")),
	date_x_(ParameterManager::getStringArray("boxplot_date_positions")),
	min_(ParameterManager::getDoubleArray("boxplot_minimum_values")),
	max_(ParameterManager::getDoubleArray("boxplot_maximum_values")),
	upper_(ParameterManager::getDoubleArray("boxplot_box_upper_values")),
	lower_(ParameterManager::getDoubleArray("boxplot_box_lower_values")),
	median_(ParameterManager::getDoubleArray("boxplot_median_values"))
	
	
{
}


BoxPlotDecoderAttributes::~BoxPlotDecoderAttributes()
{

}


void BoxPlotDecoderAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "boxplot";
	
	setAttribute(prefix, "boxplot_positions", x_, params);
	setAttribute(prefix, "boxplot_date_positions", date_x_, params);
	setAttribute(prefix, "boxplot_minimum_values", min_, params);
	setAttribute(prefix, "boxplot_maximum_values", max_, params);
	setAttribute(prefix, "boxplot_box_upper_values", upper_, params);
	setAttribute(prefix, "boxplot_box_lower_values", lower_, params);
	setAttribute(prefix, "boxplot_median_values", median_, params);
	
	
}

void BoxPlotDecoderAttributes::copy(const BoxPlotDecoderAttributes& other)
{
	x_ = other.x_;
	date_x_ = other.date_x_;
	min_ = other.min_;
	max_ = other.max_;
	upper_ = other.upper_;
	lower_ = other.lower_;
	median_ = other.median_;
	
}


bool BoxPlotDecoderAttributes::accept(const string& node)
{

	if ( magCompare(node, "boxplot_input")  )
		return true;
	
	return false;
}

void BoxPlotDecoderAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "boxplot_input")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void BoxPlotDecoderAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " x = " <<  x_;
	out << " date_x = " <<  date_x_;
	out << " min = " <<  min_;
	out << " max = " <<  max_;
	out << " upper = " <<  upper_;
	out << " lower = " <<  lower_;
	out << " median = " <<  median_;
	
	out << "]" << "\n";
}

void BoxPlotDecoderAttributes::toxml(ostream& out)  const
{
	out <<  "\"boxplot_input\"";
	out << ", \"boxplot_positions\":";
	niceprint(out,x_);
	out << ", \"boxplot_date_positions\":";
	niceprint(out,date_x_);
	out << ", \"boxplot_minimum_values\":";
	niceprint(out,min_);
	out << ", \"boxplot_maximum_values\":";
	niceprint(out,max_);
	out << ", \"boxplot_box_upper_values\":";
	niceprint(out,upper_);
	out << ", \"boxplot_box_lower_values\":";
	niceprint(out,lower_);
	out << ", \"boxplot_median_values\":";
	niceprint(out,median_);
	
}

static MagicsParameter<doublearray> boxplot_positions("boxplot_positions", floatarray());
static MagicsParameter<stringarray> boxplot_date_positions("boxplot_date_positions", stringarray());
static MagicsParameter<doublearray> boxplot_minimum_values("boxplot_minimum_values", floatarray());
static MagicsParameter<doublearray> boxplot_maximum_values("boxplot_maximum_values", floatarray());
static MagicsParameter<doublearray> boxplot_box_upper_values("boxplot_box_upper_values", floatarray());
static MagicsParameter<doublearray> boxplot_box_lower_values("boxplot_box_lower_values", floatarray());
static MagicsParameter<doublearray> boxplot_median_values("boxplot_median_values", floatarray());
