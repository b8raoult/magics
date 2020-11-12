
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file KMLDriverAttributes.h
    \\brief Definition of KMLDriver Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "KMLDriverWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


KMLDriverWrapper::KMLDriverWrapper(): kmldriver_(new KMLDriver())

{


	
	BaseDriverWrapper::object(kmldriver_);
	

}
KMLDriverWrapper::KMLDriverWrapper(KMLDriver* kmldriver): kmldriver_(kmldriver)
{

	
	BaseDriverWrapper::object(kmldriver_);
	
}

KMLDriverWrapper::~KMLDriverWrapper()
{

}

void KMLDriverWrapper::set(const MagRequest& request)
{

	

	BaseDriverWrapper::set(request);
	

	if  (request.countValues("KML_KMZ") ) {
		string kmz_value = request("KML_KMZ");
		kmldriver_->kmz_ = MagTranslator<string, bool>()(kmz_value);
		}
	if  (request.countValues("KML_DESCRIPTION") ) {
		string description_value = request("KML_DESCRIPTION");
		kmldriver_->description_ = description_value;
		}
	if  (request.countValues("KML_AUTHOR") ) {
		string author_value = request("KML_AUTHOR");
		kmldriver_->author_ = author_value;
		}
	if  (request.countValues("KML_LINK") ) {
		string link_value = request("KML_LINK");
		kmldriver_->link_ = link_value;
		}
	if  (request.countValues("KML_HEIGHT") ) {
		double height_value = request("KML_HEIGHT");
		kmldriver_->height_ = height_value;
		}
	if  (request.countValues("KML_LATITUDE") ) {
		double latitude_value = request("KML_LATITUDE");
		kmldriver_->latitude_ = latitude_value;
		}
	if  (request.countValues("KML_LONGITUDE") ) {
		double longitude_value = request("KML_LONGITUDE");
		kmldriver_->longitude_ = longitude_value;
		}
	if  (request.countValues("KML_TRANSPARENCY") ) {
		int transparency_value = request("KML_TRANSPARENCY");
		kmldriver_->transparency_ = transparency_value;
		}
	if  (request.countValues("KML_TILT") ) {
		int tilt_value = request("KML_TILT");
		kmldriver_->tilt_ = tilt_value;
		}
	if  (request.countValues("KML_RANGE") ) {
		int range_value = request("KML_RANGE");
		kmldriver_->range_ = range_value;
		}
	if  (request.countValues("KML_COASTLINES") ) {
		string coastlines_value = request("KML_COASTLINES");
		kmldriver_->coastlines_ = MagTranslator<string, bool>()(coastlines_value);
		}
	
	
}

void KMLDriverWrapper::print(ostream& out)  const
{
	out << "KMLDriverWrapper[]";
}


