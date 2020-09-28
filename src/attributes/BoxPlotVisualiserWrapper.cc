
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

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "BoxPlotVisualiserWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


BoxPlotVisualiserWrapper::BoxPlotVisualiserWrapper(): boxplotvisualiser_(new BoxPlotVisualiser())

{

	
	
	BoxPlotDecoderWrapper::object(boxplotvisualiser_);
	
	
} 
BoxPlotVisualiserWrapper::BoxPlotVisualiserWrapper(BoxPlotVisualiser* boxplotvisualiser): boxplotvisualiser_(boxplotvisualiser)
{
	
	
	BoxPlotDecoderWrapper::object(boxplotvisualiser_);
	
} 

BoxPlotVisualiserWrapper::~BoxPlotVisualiserWrapper()
{
	
}

void BoxPlotVisualiserWrapper::set(const MagRequest& request)
{
	
	
	
	BoxPlotDecoderWrapper::set(request);
	

	
	
		string box_value = request.countValues("BOXPLOT_BOX") ?  (string) request("BOXPLOT_BOX") : "on";
	MagLog::debug() << " BOXPLOT_BOX set to " << box_value << endl;
	NoBoxPlotBoxWrapper* box_wrapper = 0;
#ifdef MAGICS_EXCEPTION
	try
#endif
	{
		box_wrapper = SimpleFactory<NoBoxPlotBoxWrapper>::create(box_value);
	}
#ifdef MAGICS_EXCEPTION
	 catch (NoFactoryException) {
#else
	 if (!box_wrapper) {
#endif
		MagLog::warning() << "[" << box_value << "] is not a valid value for box: reset to default -> [on]" << endl;
		box_wrapper = SimpleFactory<NoBoxPlotBoxWrapper>::create("on");
	}
	box_wrapper->set(request);
	boxplotvisualiser_->box_ =  unique_ptr<NoBoxPlotBox>(box_wrapper->object());
	delete box_wrapper;
	
		string whisker_value = request.countValues("BOXPLOT_WHISKER") ?  (string) request("BOXPLOT_WHISKER") : "line";
	MagLog::debug() << " BOXPLOT_WHISKER set to " << whisker_value << endl;
	NoBoxPlotWhiskerWrapper* whisker_wrapper = 0;
#ifdef MAGICS_EXCEPTION
	try
#endif
	{
		whisker_wrapper = SimpleFactory<NoBoxPlotWhiskerWrapper>::create(whisker_value);
	}
#ifdef MAGICS_EXCEPTION
	 catch (NoFactoryException) {
#else
	 if (!whisker_wrapper) {
#endif
		MagLog::warning() << "[" << whisker_value << "] is not a valid value for whisker: reset to default -> [line]" << endl;
		whisker_wrapper = SimpleFactory<NoBoxPlotWhiskerWrapper>::create("line");
	}
	whisker_wrapper->set(request);
	boxplotvisualiser_->whisker_ =  unique_ptr<NoBoxPlotWhisker>(whisker_wrapper->object());
	delete whisker_wrapper;
	
}

void BoxPlotVisualiserWrapper::print(ostream& out)  const
{
	out << "BoxPlotVisualiserWrapper[]";
}


    



#include "BoxPlotBoxWrapper.h"
static SimpleObjectMaker<BoxPlotBox, NoBoxPlotBox> BoxPlotVisualiser_boxplot_box_box ("box");
static SimpleObjectMaker<BoxPlotBoxWrapper, NoBoxPlotBoxWrapper> BoxPlotVisualiser_boxplot_box_box_wrapper ("box");


#include "BoxPlotBoxWrapper.h"
static SimpleObjectMaker<BoxPlotBox, NoBoxPlotBox> BoxPlotVisualiser_boxplot_box_on ("on");
static SimpleObjectMaker<BoxPlotBoxWrapper, NoBoxPlotBoxWrapper> BoxPlotVisualiser_boxplot_box_on_wrapper ("on");


#include "NoBoxPlotBoxWrapper.h"

static SimpleObjectMaker<NoBoxPlotBoxWrapper> BoxPlotVisualiser_boxplot_box_noBox_Wrapper("noBox");


#include "NoBoxPlotBoxWrapper.h"

static SimpleObjectMaker<NoBoxPlotBoxWrapper> BoxPlotVisualiser_boxplot_box_off_Wrapper("off");



#include "BoxPlotWhiskerBoxWrapper.h"
static SimpleObjectMaker<BoxPlotWhiskerBox, NoBoxPlotWhisker> BoxPlotVisualiser_boxplot_whisker_whiskerbox ("whiskerbox");
static SimpleObjectMaker<BoxPlotWhiskerBoxWrapper, NoBoxPlotWhiskerWrapper> BoxPlotVisualiser_boxplot_whisker_whiskerbox_wrapper ("whiskerbox");


#include "BoxPlotWhiskerBoxWrapper.h"
static SimpleObjectMaker<BoxPlotWhiskerBox, NoBoxPlotWhisker> BoxPlotVisualiser_boxplot_whisker_box ("box");
static SimpleObjectMaker<BoxPlotWhiskerBoxWrapper, NoBoxPlotWhiskerWrapper> BoxPlotVisualiser_boxplot_whisker_box_wrapper ("box");


#include "NoBoxPlotWhiskerWrapper.h"

static SimpleObjectMaker<NoBoxPlotWhiskerWrapper> BoxPlotVisualiser_boxplot_whisker_nowhisker_Wrapper("nowhisker");


#include "NoBoxPlotWhiskerWrapper.h"

static SimpleObjectMaker<NoBoxPlotWhiskerWrapper> BoxPlotVisualiser_boxplot_whisker_off_Wrapper("off");


#include "BoxPlotWhiskerLineWrapper.h"
static SimpleObjectMaker<BoxPlotWhiskerLine, NoBoxPlotWhisker> BoxPlotVisualiser_boxplot_whisker_whiskerline ("whiskerline");
static SimpleObjectMaker<BoxPlotWhiskerLineWrapper, NoBoxPlotWhiskerWrapper> BoxPlotVisualiser_boxplot_whisker_whiskerline_wrapper ("whiskerline");


#include "BoxPlotWhiskerLineWrapper.h"
static SimpleObjectMaker<BoxPlotWhiskerLine, NoBoxPlotWhisker> BoxPlotVisualiser_boxplot_whisker_line ("line");
static SimpleObjectMaker<BoxPlotWhiskerLineWrapper, NoBoxPlotWhiskerWrapper> BoxPlotVisualiser_boxplot_whisker_line_wrapper ("line");



