
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file YRegularCoordinateAttributes.h
    \\brief Definition of YRegularCoordinate Attributes class.

    This file is automatically generated.
    Do Not Edit!
<<<<<<< HEAD

=======
>>>>>>> 9e3199c76cb0f6a2cf9594c406cb16d942692a7a
*/

#include "MagRequest.h"
#include "YRegularCoordinateWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


YRegularCoordinateWrapper::YRegularCoordinateWrapper(): yregularcoordinate_(new YRegularCoordinate())

{


	
	YCoordinateWrapper::object(yregularcoordinate_);
	

}
YRegularCoordinateWrapper::YRegularCoordinateWrapper(YRegularCoordinate* yregularcoordinate): yregularcoordinate_(yregularcoordinate)
{

	
	YCoordinateWrapper::object(yregularcoordinate_);
	
}

YRegularCoordinateWrapper::~YRegularCoordinateWrapper()
{

}

void YRegularCoordinateWrapper::set(const MagRequest& request)
{

	

	YCoordinateWrapper::set(request);
	

	if  (request.countValues("Y_MIN") ) {
		double min_value = request("Y_MIN");
		yregularcoordinate_->min_ = min_value;
		}
	if  (request.countValues("Y_MAX") ) {
		double max_value = request("Y_MAX");
		yregularcoordinate_->max_ = max_value;
		}
	if  (request.countValues("Y_AUTOMATIC_REVERSE") ) {
		string reverse_value = request("Y_AUTOMATIC_REVERSE");
		yregularcoordinate_->reverse_ = MagTranslator<string, bool>()(reverse_value);
		}
	
	
	if  (request.countValues("Y_AUTOMATIC") ) {
		string automatic_value = request("Y_AUTOMATIC");
		yregularcoordinate_->automatic_ = MagTranslator<string, AxisAutomaticSetting>()(automatic_value);
	}
		
	
}

void YRegularCoordinateWrapper::print(ostream& out)  const
{
	out << "YRegularCoordinateWrapper[]";
}



∏