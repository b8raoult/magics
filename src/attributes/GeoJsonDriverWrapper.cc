
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GeoJsonDriverAttributes.h
    \\brief Definition of GeoJsonDriver Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "MagRequest.h" 
#include "GeoJsonDriverWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


GeoJsonDriverWrapper::GeoJsonDriverWrapper(): geojsondriver_(new GeoJsonDriver())

{

	
	
	BaseDriverWrapper::object(geojsondriver_);
	
	
} 
GeoJsonDriverWrapper::GeoJsonDriverWrapper(GeoJsonDriver* geojsondriver): geojsondriver_(geojsondriver)
{
	
	
	BaseDriverWrapper::object(geojsondriver_);
	
} 

GeoJsonDriverWrapper::~GeoJsonDriverWrapper()
{
	
}

void GeoJsonDriverWrapper::set(const MagRequest& request)
{
	
	
	
	BaseDriverWrapper::set(request);
	

	if  (request.countValues("GEOJSON_ZIP") ) {
		string zip_value = request("GEOJSON_ZIP");
		geojsondriver_->zip_ = MagTranslator<string, bool>()(zip_value);
		}
	if  (request.countValues("GEOJSON_DESCRIPTION") ) {
		string description_value = request("GEOJSON_DESCRIPTION");
		geojsondriver_->description_ = description_value;
		}
	if  (request.countValues("GEOJSON_AUTHOR") ) {
		string author_value = request("GEOJSON_AUTHOR");
		geojsondriver_->author_ = author_value;
		}
	if  (request.countValues("GEOJSON_LINK") ) {
		string link_value = request("GEOJSON_LINK");
		geojsondriver_->link_ = link_value;
		}
	if  (request.countValues("GEOJSON_COASTLINES") ) {
		string coastlines_value = request("GEOJSON_COASTLINES");
		geojsondriver_->coastlines_ = MagTranslator<string, bool>()(coastlines_value);
		}
	
	
}

void GeoJsonDriverWrapper::print(ostream& out)  const
{
	out << "GeoJsonDriverWrapper[]";
}


    



