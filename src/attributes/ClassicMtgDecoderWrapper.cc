
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ClassicMtgDecoderAttributes.h
    \\brief Definition of ClassicMtgDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "ClassicMtgDecoderWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


ClassicMtgDecoderWrapper::ClassicMtgDecoderWrapper(): classicmtgdecoder_(new ClassicMtgDecoder())

{

	
	
	
} 
ClassicMtgDecoderWrapper::ClassicMtgDecoderWrapper(ClassicMtgDecoder* classicmtgdecoder): classicmtgdecoder_(classicmtgdecoder)
{
	
	
} 

ClassicMtgDecoderWrapper::~ClassicMtgDecoderWrapper()
{
	
}

void ClassicMtgDecoderWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("METGRAM_DATABASE") ) {
		string database_value = request("METGRAM_DATABASE");
		classicmtgdecoder_->database_ = database_value;
		}
	if  (request.countValues("METGRAM_PARAMETER") ) {
		string param_value = request("METGRAM_PARAMETER");
		classicmtgdecoder_->param_ = param_value;
		}
	if  (request.countValues("METGRAM_LATITUDE") ) {
		double latitude_value = request("METGRAM_LATITUDE");
		classicmtgdecoder_->latitude_ = latitude_value;
		}
	if  (request.countValues("METGRAM_PARAMETER_SCALING_FACTOR") ) {
		double param_scaling_value = request("METGRAM_PARAMETER_SCALING_FACTOR");
		classicmtgdecoder_->param_scaling_ = param_scaling_value;
		}
	if  (request.countValues("METGRAM_PARAMETER_OFFSET") ) {
		double param_offset_value = request("METGRAM_PARAMETER_OFFSET");
		classicmtgdecoder_->param_offset_ = param_offset_value;
		}
	if  (request.countValues("METGRAM_PARAMETER_TITLE") ) {
		string param_title_value = request("METGRAM_PARAMETER_TITLE");
		classicmtgdecoder_->param_title_ = param_title_value;
		}
	if  (request.countValues("METGRAM_LONGITUDE") ) {
		double longitude_value = request("METGRAM_LONGITUDE");
		classicmtgdecoder_->longitude_ = longitude_value;
		}
	if  (request.countValues("METGRAM_DATE") ) {
		string date_value = request("METGRAM_DATE");
		classicmtgdecoder_->date_ = date_value;
		}
	if  (request.countValues("METGRAM_TIME") ) {
		string time_value = request("METGRAM_TIME");
		classicmtgdecoder_->time_ = time_value;
		}
	if  (request.countValues("METGRAM_LONG_TITLE") ) {
		string long_title_value = request("METGRAM_LONG_TITLE");
		classicmtgdecoder_->long_title_ = MagTranslator<string, bool>()(long_title_value);
		}
	if  (request.countValues("METGRAM_STATION_NAME") ) {
		string station_value = request("METGRAM_STATION_NAME");
		classicmtgdecoder_->station_ = station_value;
		}
	if  (request.countValues("METGRAM_STATION_HEIGHT") ) {
		double height_value = request("METGRAM_STATION_HEIGHT");
		classicmtgdecoder_->height_ = height_value;
		}
	if  (request.countValues("METGRAM_TEMPERATURE_CORRECTION") ) {
		string correction_value = request("METGRAM_TEMPERATURE_CORRECTION");
		classicmtgdecoder_->correction_ = MagTranslator<string, bool>()(correction_value);
		}
	
	
}

void ClassicMtgDecoderWrapper::print(ostream& out)  const
{
	out << "ClassicMtgDecoderWrapper[]";
}


    



