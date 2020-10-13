
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file TephigramAttributes.h
    \\brief Definition of Tephigram Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "MagRequest.h" 
#include "TephigramWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


TephigramWrapper::TephigramWrapper(): tephigram_(new Tephigram())

{

	
	
	TransformationWrapper::object(tephigram_);
	
	
} 
TephigramWrapper::TephigramWrapper(Tephigram* tephigram): tephigram_(tephigram)
{
	
	
	TransformationWrapper::object(tephigram_);
	
} 

TephigramWrapper::~TephigramWrapper()
{
	
}

void TephigramWrapper::set(const MagRequest& request)
{
	
	
	
	TransformationWrapper::set(request);
	

	if  (request.countValues("X_MIN") ) {
		double x_min_value = request("X_MIN");
		tephigram_->x_min_ = x_min_value;
		}
	if  (request.countValues("SUBPAGE_X_AUTOMATIC") ) {
		string x_automatic_value = request("SUBPAGE_X_AUTOMATIC");
		tephigram_->x_automatic_ = MagTranslator<string, bool>()(x_automatic_value);
		}
	if  (request.countValues("SUBPAGE_Y_AUTOMATIC") ) {
		string y_automatic_value = request("SUBPAGE_Y_AUTOMATIC");
		tephigram_->y_automatic_ = MagTranslator<string, bool>()(y_automatic_value);
		}
	if  (request.countValues("X_MAX") ) {
		double x_max_value = request("X_MAX");
		tephigram_->x_max_ = x_max_value;
		}
	if  (request.countValues("Y_MIN") ) {
		double y_min_value = request("Y_MIN");
		tephigram_->y_min_ = y_min_value;
		}
	if  (request.countValues("Y_MAX") ) {
		double y_max_value = request("Y_MAX");
		tephigram_->y_max_ = y_max_value;
		}
	if  (request.countValues("THERMO_ANNOTATION_WIDTH") ) {
		double annotation_width_value = request("THERMO_ANNOTATION_WIDTH");
		tephigram_->annotation_width_ = annotation_width_value;
		}
	
	
}

void TephigramWrapper::print(ostream& out)  const
{
	out << "TephigramWrapper[]";
}


    



