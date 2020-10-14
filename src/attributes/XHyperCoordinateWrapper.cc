
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file XHyperCoordinateAttributes.h
    \\brief Definition of XHyperCoordinate Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "XHyperCoordinateWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


XHyperCoordinateWrapper::XHyperCoordinateWrapper(): xhypercoordinate_(new XHyperCoordinate())

{


	
	XCoordinateWrapper::object(xhypercoordinate_);
	

}
XHyperCoordinateWrapper::XHyperCoordinateWrapper(XHyperCoordinate* xhypercoordinate): xhypercoordinate_(xhypercoordinate)
{

	
	XCoordinateWrapper::object(xhypercoordinate_);
	
}

XHyperCoordinateWrapper::~XHyperCoordinateWrapper()
{

}

void XHyperCoordinateWrapper::set(const MagRequest& request)
{

	

	XCoordinateWrapper::set(request);
	

	if  (request.countValues("X_MIN_LATITUDE") ) {
		double min_lat_value = request("X_MIN_LATITUDE");
		xhypercoordinate_->min_lat_ = min_lat_value;
		}
	if  (request.countValues("X_MAX_LATITUDE") ) {
		double max_lat_value = request("X_MAX_LATITUDE");
		xhypercoordinate_->max_lat_ = max_lat_value;
		}
	if  (request.countValues("X_MIN_LONGITUDE") ) {
		double min_lon_value = request("X_MIN_LONGITUDE");
		xhypercoordinate_->min_lon_ = min_lon_value;
		}
	if  (request.countValues("X_MAX_LONGITUDE") ) {
		double max_lon_value = request("X_MAX_LONGITUDE");
		xhypercoordinate_->max_lon_ = max_lon_value;
		}
	if  (request.countValues("X_AUTOMATIC_REVERSE") ) {
		string reverse_value = request("X_AUTOMATIC_REVERSE");
		xhypercoordinate_->reverse_ = MagTranslator<string, bool>()(reverse_value);
		}
	
	
	if  (request.countValues("X_AUTOMATIC") ) {
		string automatic_value = request("X_AUTOMATIC");
		xhypercoordinate_->automatic_ = MagTranslator<string, AxisAutomaticSetting>()(automatic_value);
	}
		
	
}

void XHyperCoordinateWrapper::print(ostream& out)  const
{
	out << "XHyperCoordinateWrapper[]";
}



∏