
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

*/

#include "MagRequest.h"
#include "HistogramWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


HistogramWrapper::HistogramWrapper(): histogram_(new Histogram())

{


	

}
HistogramWrapper::HistogramWrapper(Histogram* histogram): histogram_(histogram)
{

	
}

HistogramWrapper::~HistogramWrapper()
{

}

void HistogramWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("HISTOGRAM_MIN_VALUE") ) {
		double min_value = request("HISTOGRAM_MIN_VALUE");
		histogram_->min_ = min_value;
		}
	if  (request.countValues("HISTOGRAM_MAX_VALUE") ) {
		double max_value = request("HISTOGRAM_MAX_VALUE");
		histogram_->max_ = max_value;
		}
	if  (request.countValues("HISTOGRAM_LEVEL_COUNT") ) {
		int count_value = request("HISTOGRAM_LEVEL_COUNT");
		histogram_->count_ = count_value;
		}
	if  (request.countValues("HISTOGRAM_LEVEL_TOLERANCE") ) {
		int tolerance_value = request("HISTOGRAM_LEVEL_TOLERANCE");
		histogram_->tolerance_ = tolerance_value;
		}
	if  (request.countValues("HISTOGRAM_REFERENCE_LEVEL") ) {
		double reference_value = request("HISTOGRAM_REFERENCE_LEVEL");
		histogram_->reference_ = reference_value;
		}
	if  (request.countValues("HISTOGRAM_INTERVAL") ) {
		double interval_value = request("HISTOGRAM_INTERVAL");
		histogram_->interval_ = interval_value;
		}
	doublearray  list_value;
	for (int i = 0; i < request.countValues("HISTOGRAM_LEVEL_LIST"); i++)
		list_value.push_back((double)request("HISTOGRAM_LEVEL_LIST", i));
	if ( !list_value.empty() )
		histogram_->list_ = list_value;
	if  (request.countValues("HISTOGRAM_BAR_WIDTH") ) {
		double width_value = request("HISTOGRAM_BAR_WIDTH");
		histogram_->width_ = width_value;
		}
	
	
		string levels_value = request.countValues("HISTOGRAM_SELECTION_TYPE") ?  (string) request("HISTOGRAM_SELECTION_TYPE") : "count";
	MagLog::debug() << " HISTOGRAM_SELECTION_TYPE set to " << levels_value << endl;
	LevelSelectionWrapper* levels_wrapper = 0;

	levels_wrapper = SimpleFactory<LevelSelectionWrapper>::create(levels_value);

	 if (!levels_wrapper) {
		MagLog::warning() << "[" << levels_value << "] is not a valid value for levels: reset to default -> [count]" << endl;
		levels_wrapper = SimpleFactory<LevelSelectionWrapper>::create("count");
	}
	levels_wrapper->set(request);
	histogram_->levels_ =  unique_ptr<LevelSelection>(levels_wrapper->object());
	delete levels_wrapper;
	if  (request.countValues("HISTOGRAM_BAR_COLOUR") ) {
		string colour_value = request("HISTOGRAM_BAR_COLOUR");
		histogram_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
}

void HistogramWrapper::print(ostream& out)  const
{
	out << "HistogramWrapper[]";
}


#include "CountSelectionTypeWrapper.h"
static SimpleObjectMaker<CountSelectionType, LevelSelection> Histogram_histogram_selection_type_count ("count");
static SimpleObjectMaker<CountSelectionTypeWrapper, LevelSelectionWrapper> Histogram_histogram_selection_type_count_wrapper ("count");


#include "IntervalSelectionTypeWrapper.h"
static SimpleObjectMaker<IntervalSelectionType, LevelSelection> Histogram_histogram_selection_type_interval ("interval");
static SimpleObjectMaker<IntervalSelectionTypeWrapper, LevelSelectionWrapper> Histogram_histogram_selection_type_interval_wrapper ("interval");


#include "LevelListSelectionTypeWrapper.h"
static SimpleObjectMaker<LevelListSelectionType, LevelSelection> Histogram_histogram_selection_type_list ("list");
static SimpleObjectMaker<LevelListSelectionTypeWrapper, LevelSelectionWrapper> Histogram_histogram_selection_type_list_wrapper ("list");




∏