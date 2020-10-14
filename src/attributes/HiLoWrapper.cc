
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file HiLoAttributes.h
    \\brief Definition of HiLo Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "HiLoWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


HiLoWrapper::HiLoWrapper(): hilo_(new HiLo())

{


	
	HiLoBaseWrapper::object(hilo_);
	

}
HiLoWrapper::HiLoWrapper(HiLo* hilo): hilo_(hilo)
{

	
	HiLoBaseWrapper::object(hilo_);
	
}

HiLoWrapper::~HiLoWrapper()
{

}

void HiLoWrapper::set(const MagRequest& request)
{

	

	HiLoBaseWrapper::set(request);
	

	if  (request.countValues("CONTOUR_HILO_WINDOW_SIZE") ) {
		int window_size_value = request("CONTOUR_HILO_WINDOW_SIZE");
		hilo_->window_size_ = window_size_value;
		}
	if  (request.countValues("CONTOUR_HILO_MAX_VALUE") ) {
		double hilo_max_value_value = request("CONTOUR_HILO_MAX_VALUE");
		hilo_->hilo_max_value_ = hilo_max_value_value;
		}
	if  (request.countValues("CONTOUR_HILO_MIN_VALUE") ) {
		double hilo_min_value_value = request("CONTOUR_HILO_MIN_VALUE");
		hilo_->hilo_min_value_ = hilo_min_value_value;
		}
	if  (request.countValues("CONTOUR_HI_MAX_VALUE") ) {
		double hi_max_value_value = request("CONTOUR_HI_MAX_VALUE");
		hilo_->hi_max_value_ = hi_max_value_value;
		}
	if  (request.countValues("CONTOUR_HI_MIN_VALUE") ) {
		double hi_min_value_value = request("CONTOUR_HI_MIN_VALUE");
		hilo_->hi_min_value_ = hi_min_value_value;
		}
	if  (request.countValues("CONTOUR_LO_MAX_VALUE") ) {
		double lo_max_value_value = request("CONTOUR_LO_MAX_VALUE");
		hilo_->lo_max_value_ = lo_max_value_value;
		}
	if  (request.countValues("CONTOUR_LO_MIN_VALUE") ) {
		double lo_min_value_value = request("CONTOUR_LO_MIN_VALUE");
		hilo_->lo_min_value_ = lo_min_value_value;
		}
	
	
		string type_value = request.countValues("CONTOUR_HILO_TYPE") ?  (string) request("CONTOUR_HILO_TYPE") : "text";
	MagLog::debug() << " CONTOUR_HILO_TYPE set to " << type_value << endl;
	HiLoTechniqueWrapper* type_wrapper = 0;

	type_wrapper = SimpleFactory<HiLoTechniqueWrapper>::create(type_value);

	 if (!type_wrapper) {
		MagLog::warning() << "[" << type_value << "] is not a valid value for type: reset to default -> [text]" << endl;
		type_wrapper = SimpleFactory<HiLoTechniqueWrapper>::create("text");
	}
	type_wrapper->set(request);
	hilo_->type_ =  unique_ptr<HiLoTechnique>(type_wrapper->object());
	delete type_wrapper;
	
		string marker_value = request.countValues("CONTOUR_HILO_MARKER") ?  (string) request("CONTOUR_HILO_MARKER") : "off";
	MagLog::debug() << " CONTOUR_HILO_MARKER set to " << marker_value << endl;
	HiLoMarkerBaseWrapper* marker_wrapper = 0;

	marker_wrapper = SimpleFactory<HiLoMarkerBaseWrapper>::create(marker_value);

	 if (!marker_wrapper) {
		MagLog::warning() << "[" << marker_value << "] is not a valid value for marker: reset to default -> [off]" << endl;
		marker_wrapper = SimpleFactory<HiLoMarkerBaseWrapper>::create("off");
	}
	marker_wrapper->set(request);
	hilo_->marker_ =  unique_ptr<HiLoMarkerBase>(marker_wrapper->object());
	delete marker_wrapper;
	
}

void HiLoWrapper::print(ostream& out)  const
{
	out << "HiLoWrapper[]";
}


#include "HiLoTextWrapper.h"
static SimpleObjectMaker<HiLoText, HiLoTechnique> HiLo_contour_hilo_type_text ("text");
static SimpleObjectMaker<HiLoTextWrapper, HiLoTechniqueWrapper> HiLo_contour_hilo_type_text_wrapper ("text");


#include "HiLoNumberWrapper.h"
static SimpleObjectMaker<HiLoNumber, HiLoTechnique> HiLo_contour_hilo_type_number ("number");
static SimpleObjectMaker<HiLoNumberWrapper, HiLoTechniqueWrapper> HiLo_contour_hilo_type_number_wrapper ("number");


#include "HiLoBothWrapper.h"
static SimpleObjectMaker<HiLoBoth, HiLoTechnique> HiLo_contour_hilo_type_both ("both");
static SimpleObjectMaker<HiLoBothWrapper, HiLoTechniqueWrapper> HiLo_contour_hilo_type_both_wrapper ("both");



#include "HiLoMarkerWrapper.h"
static SimpleObjectMaker<HiLoMarker, HiLoMarkerBase> HiLo_contour_hilo_marker_marker ("marker");
static SimpleObjectMaker<HiLoMarkerWrapper, HiLoMarkerBaseWrapper> HiLo_contour_hilo_marker_marker_wrapper ("marker");


#include "HiLoMarkerWrapper.h"
static SimpleObjectMaker<HiLoMarker, HiLoMarkerBase> HiLo_contour_hilo_marker_on ("on");
static SimpleObjectMaker<HiLoMarkerWrapper, HiLoMarkerBaseWrapper> HiLo_contour_hilo_marker_on_wrapper ("on");


#include "NoHiLoMarkerWrapper.h"
static SimpleObjectMaker<NoHiLoMarker, HiLoMarkerBase> HiLo_contour_hilo_marker_nomarker ("nomarker");
static SimpleObjectMaker<NoHiLoMarkerWrapper, HiLoMarkerBaseWrapper> HiLo_contour_hilo_marker_nomarker_wrapper ("nomarker");


#include "NoHiLoMarkerWrapper.h"
static SimpleObjectMaker<NoHiLoMarker, HiLoMarkerBase> HiLo_contour_hilo_marker_off ("off");
static SimpleObjectMaker<NoHiLoMarkerWrapper, HiLoMarkerBaseWrapper> HiLo_contour_hilo_marker_off_wrapper ("off");



∏