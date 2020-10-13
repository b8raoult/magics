
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LabelPlottingAttributes.h
    \\brief Definition of LabelPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "MagRequest.h" 
#include "LabelPlottingWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


LabelPlottingWrapper::LabelPlottingWrapper(): labelplotting_(new LabelPlotting())

{

	
	
	NoLabelPlottingWrapper::object(labelplotting_);
	
	
} 
LabelPlottingWrapper::LabelPlottingWrapper(LabelPlotting* labelplotting): labelplotting_(labelplotting)
{
	
	
	NoLabelPlottingWrapper::object(labelplotting_);
	
} 

LabelPlottingWrapper::~LabelPlottingWrapper()
{
	
}

void LabelPlottingWrapper::set(const MagRequest& request)
{
	
	
	
	NoLabelPlottingWrapper::set(request);
	

	if  (request.countValues("MAP_LABEL_FONT") ) {
		string font_value = request("MAP_LABEL_FONT");
		labelplotting_->font_ = font_value;
		}
	if  (request.countValues("MAP_LABEL_FONT_STYLE") ) {
		string font_style_value = request("MAP_LABEL_FONT_STYLE");
		labelplotting_->font_style_ = font_style_value;
		}
	if  (request.countValues("MAP_LABEL_HEIGHT") ) {
		double height_value = request("MAP_LABEL_HEIGHT");
		labelplotting_->height_ = height_value;
		}
	if  (request.countValues("MAP_LABEL_BLANKING") ) {
		string blanking_value = request("MAP_LABEL_BLANKING");
		labelplotting_->blanking_ = MagTranslator<string, bool>()(blanking_value);
		}
	if  (request.countValues("MAP_LABEL_LATITUDE_FREQUENCY") ) {
		int latFrequency_value = request("MAP_LABEL_LATITUDE_FREQUENCY");
		labelplotting_->latFrequency_ = latFrequency_value;
		}
	if  (request.countValues("MAP_LABEL_LONGITUDE_FREQUENCY") ) {
		int lonFrequency_value = request("MAP_LABEL_LONGITUDE_FREQUENCY");
		labelplotting_->lonFrequency_ = lonFrequency_value;
		}
	if  (request.countValues("MAP_LABEL_LEFT") ) {
		string left_value = request("MAP_LABEL_LEFT");
		labelplotting_->left_ = MagTranslator<string, bool>()(left_value);
		}
	if  (request.countValues("MAP_LABEL_RIGHT") ) {
		string right_value = request("MAP_LABEL_RIGHT");
		labelplotting_->right_ = MagTranslator<string, bool>()(right_value);
		}
	if  (request.countValues("MAP_LABEL_TOP") ) {
		string top_value = request("MAP_LABEL_TOP");
		labelplotting_->top_ = MagTranslator<string, bool>()(top_value);
		}
	if  (request.countValues("MAP_LABEL_BOTTOM") ) {
		string bottom_value = request("MAP_LABEL_BOTTOM");
		labelplotting_->bottom_ = MagTranslator<string, bool>()(bottom_value);
		}
	
	if  (request.countValues("MAP_LABEL_COLOUR") ) {
		string colour_value = request("MAP_LABEL_COLOUR");
		labelplotting_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
}

void LabelPlottingWrapper::print(ostream& out)  const
{
	out << "LabelPlottingWrapper[]";
}


    




