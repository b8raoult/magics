
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file BoxPlotVisualiserAttributes.h
    \\brief Definition of BoxPlotVisualiser Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "BoxPlotVisualiserAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

BoxPlotVisualiserAttributes::BoxPlotVisualiserAttributes():
	
	box_(MagTranslator<string, NoBoxPlotBox>().magics("boxplot_box")),
	whisker_(MagTranslator<string, NoBoxPlotWhisker>().magics("boxplot_whisker"))
	
{
}


BoxPlotVisualiserAttributes::~BoxPlotVisualiserAttributes()
{

}


void BoxPlotVisualiserAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	
	setMember(prefix, "boxplot_box", box_, params);
	setMember(prefix, "boxplot_whisker", whisker_, params);
	
}

void BoxPlotVisualiserAttributes::copy(const BoxPlotVisualiserAttributes& other)
{
	box_ = unique_ptr<NoBoxPlotBox>(other.box_->clone());
	whisker_ = unique_ptr<NoBoxPlotWhisker>(other.whisker_->clone());
	
}


bool BoxPlotVisualiserAttributes::accept(const string& node)
{

	if ( magCompare(node, "boxplot")  )
		return true;
	if ( acceptNode(node, box_) )
		return true;
	if ( acceptNode(node, whisker_) )
		return true;
	
	return false;
}

void BoxPlotVisualiserAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "boxplot")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), box_, node);
		setMember(node.name(), whisker_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), box_, *elt);
		setMember(elt->name(), whisker_, *elt);
		
	}
}

void BoxPlotVisualiserAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " box = " <<  *box_;
	out << " whisker = " <<  *whisker_;
	
	out << "]" << "\n";
}

void BoxPlotVisualiserAttributes::toxml(ostream& out)  const
{
	out <<  "\"boxplot\"";
	out << ", \"boxplot_box\":";
	box_->toxml(out);
	out << ", \"boxplot_whisker\":";
	whisker_->toxml(out);
	
}

static MagicsParameter<string> boxplot_box("boxplot_box", "on");
static MagicsParameter<string> boxplot_whisker("boxplot_whisker", "line");
#include "BoxPlotItem.h"
#include "BoxPlotBasicItem.h"
static SimpleObjectMaker<BoxPlotBox , NoBoxPlotBox> box_BoxPlotBox("box");
static SimpleObjectMaker<BoxPlotBox , NoBoxPlotBox> on_BoxPlotBox("on");
static SimpleObjectMaker<NoBoxPlotBox , NoBoxPlotBox> noBox_NoBoxPlotBox("noBox");
static SimpleObjectMaker<NoBoxPlotBox , NoBoxPlotBox> off_NoBoxPlotBox("off");
static SimpleObjectMaker<BoxPlotWhiskerBox , NoBoxPlotWhisker> whiskerbox_BoxPlotWhiskerBox("whiskerbox");
static SimpleObjectMaker<BoxPlotWhiskerBox , NoBoxPlotWhisker> box_BoxPlotWhiskerBox("box");
static SimpleObjectMaker<NoBoxPlotWhisker , NoBoxPlotWhisker> nowhisker_NoBoxPlotWhisker("nowhisker");
static SimpleObjectMaker<NoBoxPlotWhisker , NoBoxPlotWhisker> off_NoBoxPlotWhisker("off");
static SimpleObjectMaker<BoxPlotWhiskerLine , NoBoxPlotWhisker> whiskerline_BoxPlotWhiskerLine("whiskerline");
static SimpleObjectMaker<BoxPlotWhiskerLine , NoBoxPlotWhisker> line_BoxPlotWhiskerLine("line");
