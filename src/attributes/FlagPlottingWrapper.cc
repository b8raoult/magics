
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file FlagPlottingAttributes.h
    \\brief Definition of FlagPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "MagRequest.h" 
#include "FlagPlottingWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


FlagPlottingWrapper::FlagPlottingWrapper(): flagplotting_(new FlagPlotting())

{

	
	
	WindPlottingWrapper::object(flagplotting_);
	
	
} 
FlagPlottingWrapper::FlagPlottingWrapper(FlagPlotting* flagplotting): flagplotting_(flagplotting)
{
	
	
	WindPlottingWrapper::object(flagplotting_);
	
} 

FlagPlottingWrapper::~FlagPlottingWrapper()
{
	
}

void FlagPlottingWrapper::set(const MagRequest& request)
{
	
	
	
	WindPlottingWrapper::set(request);
	

	if  (request.countValues("WIND_FLAG_CALM_INDICATOR_SIZE") ) {
		double calm_indicator_size_value = request("WIND_FLAG_CALM_INDICATOR_SIZE");
		flagplotting_->calm_indicator_size_ = calm_indicator_size_value;
		}
	if  (request.countValues("WIND_FLAG_CALM_BELOW") ) {
		double calm_below_value = request("WIND_FLAG_CALM_BELOW");
		flagplotting_->calm_below_ = calm_below_value;
		}
	if  (request.countValues("WIND_FLAG_CROSS_BOUNDARY") ) {
		string cross_boundary_value = request("WIND_FLAG_CROSS_BOUNDARY");
		flagplotting_->cross_boundary_ = MagTranslator<string, bool>()(cross_boundary_value);
		}
	if  (request.countValues("WIND_FLAG_LENGTH") ) {
		double length_value = request("WIND_FLAG_LENGTH");
		flagplotting_->length_ = length_value;
		}
	if  (request.countValues("WIND_FLAG_MAX_SPEED") ) {
		double max_speed_value = request("WIND_FLAG_MAX_SPEED");
		flagplotting_->max_speed_ = max_speed_value;
		}
	if  (request.countValues("WIND_FLAG_MIN_SPEED") ) {
		double min_speed_value = request("WIND_FLAG_MIN_SPEED");
		flagplotting_->min_speed_ = min_speed_value;
		}
	if  (request.countValues("WIND_FLAG_ORIGIN_MARKER_SIZE") ) {
		double origin_marker_size_value = request("WIND_FLAG_ORIGIN_MARKER_SIZE");
		flagplotting_->origin_marker_size_ = origin_marker_size_value;
		}
	if  (request.countValues("WIND_FLAG_THICKNESS") ) {
		int thickness_value = request("WIND_FLAG_THICKNESS");
		flagplotting_->thickness_ = thickness_value;
		}
	
	
		string calm_value = request.countValues("WIND_FLAG_CALM_INDICATOR") ?  (string) request("WIND_FLAG_CALM_INDICATOR") : "on";
	MagLog::debug() << " WIND_FLAG_CALM_INDICATOR set to " << calm_value << endl;
	CalmIndicatorWrapper* calm_wrapper = 0;
#ifdef MAGICS_EXCEPTION
	try
#endif
	{
		calm_wrapper = SimpleFactory<CalmIndicatorWrapper>::create(calm_value);
	}
#ifdef MAGICS_EXCEPTION
	 catch (NoFactoryException) {
#else
	 if (!calm_wrapper) {
#endif
		MagLog::warning() << "[" << calm_value << "] is not a valid value for calm: reset to default -> [on]" << endl;
		calm_wrapper = SimpleFactory<CalmIndicatorWrapper>::create("on");
	}
	calm_wrapper->set(request);
	flagplotting_->calm_ =  unique_ptr<CalmIndicator>(calm_wrapper->object());
	delete calm_wrapper;
	if  (request.countValues("WIND_FLAG_COLOUR") ) {
		string colour_value = request("WIND_FLAG_COLOUR");
		flagplotting_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
	if  (request.countValues("WIND_FLAG_STYLE") ) {
		string style_value = request("WIND_FLAG_STYLE");
		flagplotting_->style_ = MagTranslator<string, LineStyle>()(style_value);
	}
		
	
		string origin_value = request.countValues("WIND_FLAG_ORIGIN_MARKER") ?  (string) request("WIND_FLAG_ORIGIN_MARKER") : "circle";
	MagLog::debug() << " WIND_FLAG_ORIGIN_MARKER set to " << origin_value << endl;
	OriginMarkerWrapper* origin_wrapper = 0;
#ifdef MAGICS_EXCEPTION
	try
#endif
	{
		origin_wrapper = SimpleFactory<OriginMarkerWrapper>::create(origin_value);
	}
#ifdef MAGICS_EXCEPTION
	 catch (NoFactoryException) {
#else
	 if (!origin_wrapper) {
#endif
		MagLog::warning() << "[" << origin_value << "] is not a valid value for origin: reset to default -> [circle]" << endl;
		origin_wrapper = SimpleFactory<OriginMarkerWrapper>::create("circle");
	}
	origin_wrapper->set(request);
	flagplotting_->origin_ =  unique_ptr<OriginMarker>(origin_wrapper->object());
	delete origin_wrapper;
	
}

void FlagPlottingWrapper::print(ostream& out)  const
{
	out << "FlagPlottingWrapper[]";
}


    



#include "CalmIndicatorWrapper.h"

static SimpleObjectMaker<CalmIndicatorWrapper> FlagPlotting_wind_flag_calm_indicator_calm_Wrapper("calm");


#include "CalmIndicatorWrapper.h"

static SimpleObjectMaker<CalmIndicatorWrapper> FlagPlotting_wind_flag_calm_indicator_on_Wrapper("on");


#include "NoCalmIndicatorWrapper.h"
static SimpleObjectMaker<NoCalmIndicator, CalmIndicator> FlagPlotting_wind_flag_calm_indicator_nocalm ("nocalm");
static SimpleObjectMaker<NoCalmIndicatorWrapper, CalmIndicatorWrapper> FlagPlotting_wind_flag_calm_indicator_nocalm_wrapper ("nocalm");


#include "NoCalmIndicatorWrapper.h"
static SimpleObjectMaker<NoCalmIndicator, CalmIndicator> FlagPlotting_wind_flag_calm_indicator_off ("off");
static SimpleObjectMaker<NoCalmIndicatorWrapper, CalmIndicatorWrapper> FlagPlotting_wind_flag_calm_indicator_off_wrapper ("off");





#include "DotOriginMarkerWrapper.h"
static SimpleObjectMaker<DotOriginMarker, OriginMarker> FlagPlotting_wind_flag_origin_marker_dotmarker ("dotmarker");
static SimpleObjectMaker<DotOriginMarkerWrapper, OriginMarkerWrapper> FlagPlotting_wind_flag_origin_marker_dotmarker_wrapper ("dotmarker");


#include "DotOriginMarkerWrapper.h"
static SimpleObjectMaker<DotOriginMarker, OriginMarker> FlagPlotting_wind_flag_origin_marker_dot ("dot");
static SimpleObjectMaker<DotOriginMarkerWrapper, OriginMarkerWrapper> FlagPlotting_wind_flag_origin_marker_dot_wrapper ("dot");


#include "CircleOriginMarkerWrapper.h"
static SimpleObjectMaker<CircleOriginMarker, OriginMarker> FlagPlotting_wind_flag_origin_marker_circlemarker ("circlemarker");
static SimpleObjectMaker<CircleOriginMarkerWrapper, OriginMarkerWrapper> FlagPlotting_wind_flag_origin_marker_circlemarker_wrapper ("circlemarker");


#include "CircleOriginMarkerWrapper.h"
static SimpleObjectMaker<CircleOriginMarker, OriginMarker> FlagPlotting_wind_flag_origin_marker_circle ("circle");
static SimpleObjectMaker<CircleOriginMarkerWrapper, OriginMarkerWrapper> FlagPlotting_wind_flag_origin_marker_circle_wrapper ("circle");


#include "NoOriginMarkerWrapper.h"
static SimpleObjectMaker<NoOriginMarker, OriginMarker> FlagPlotting_wind_flag_origin_marker_nomarker ("nomarker");
static SimpleObjectMaker<NoOriginMarkerWrapper, OriginMarkerWrapper> FlagPlotting_wind_flag_origin_marker_nomarker_wrapper ("nomarker");


#include "NoOriginMarkerWrapper.h"
static SimpleObjectMaker<NoOriginMarker, OriginMarker> FlagPlotting_wind_flag_origin_marker_off ("off");
static SimpleObjectMaker<NoOriginMarkerWrapper, OriginMarkerWrapper> FlagPlotting_wind_flag_origin_marker_off_wrapper ("off");



