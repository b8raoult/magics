
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EpsBufrAttributes.h
    \\brief Definition of EpsBufr Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "EpsBufrWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


EpsBufrWrapper::EpsBufrWrapper(): epsbufr_(new EpsBufr())

{

	
	
	
} 
EpsBufrWrapper::EpsBufrWrapper(EpsBufr* epsbufr): epsbufr_(epsbufr)
{
	
	
} 

EpsBufrWrapper::~EpsBufrWrapper()
{
	
}

void EpsBufrWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("EPSBUFR_INPUT_FILENAME") ) {
		string path_value = request("EPSBUFR_INPUT_FILENAME");
		epsbufr_->path_ = path_value;
		}
	if  (request.countValues("EPSBUFR_TITLE") ) {
		string title_value = request("EPSBUFR_TITLE");
		epsbufr_->title_ = title_value;
		}
	if  (request.countValues("EPSBUFR_PARAMETER_TITLE") ) {
		string param_title_value = request("EPSBUFR_PARAMETER_TITLE");
		epsbufr_->param_title_ = param_title_value;
		}
	if  (request.countValues("EPSBUFR_INFORMATION") ) {
		string information_value = request("EPSBUFR_INFORMATION");
		epsbufr_->information_ = MagTranslator<string, bool>()(information_value);
		}
	if  (request.countValues("EPSBUFR_SHORT_TITLE") ) {
		string short_title_value = request("EPSBUFR_SHORT_TITLE");
		epsbufr_->short_title_ = MagTranslator<string, bool>()(short_title_value);
		}
	if  (request.countValues("EPSBUFR_PARAMETER_DESCRIPTOR") ) {
		int param_descriptor_value = request("EPSBUFR_PARAMETER_DESCRIPTOR");
		epsbufr_->param_descriptor_ = param_descriptor_value;
		}
	if  (request.countValues("EPSBUFR_PARAMETER_2_DESCRIPTOR") ) {
		int param_descriptor_2_value = request("EPSBUFR_PARAMETER_2_DESCRIPTOR");
		epsbufr_->param_descriptor_2_ = param_descriptor_2_value;
		}
	if  (request.countValues("EPSBUFR_ACCUMULATED_PARAMETER") ) {
		string accumulated_value = request("EPSBUFR_ACCUMULATED_PARAMETER");
		epsbufr_->accumulated_ = MagTranslator<string, bool>()(accumulated_value);
		}
	if  (request.countValues("EPSBUFR_STATION_NAME") ) {
		string station_name_value = request("EPSBUFR_STATION_NAME");
		epsbufr_->station_name_ = station_name_value;
		}
	if  (request.countValues("EPSBUFR_STATION_LATITUDE") ) {
		double latitude_value = request("EPSBUFR_STATION_LATITUDE");
		epsbufr_->latitude_ = latitude_value;
		}
	if  (request.countValues("EPSBUFR_STATION_LONGITUDE") ) {
		double longitude_value = request("EPSBUFR_STATION_LONGITUDE");
		epsbufr_->longitude_ = longitude_value;
		}
	if  (request.countValues("EPSBUFR_PARAMETER_SCALING_FACTOR") ) {
		double param_scaling_factor_value = request("EPSBUFR_PARAMETER_SCALING_FACTOR");
		epsbufr_->param_scaling_factor_ = param_scaling_factor_value;
		}
	if  (request.countValues("EPSBUFR_PARAMETER_OFFSET_FACTOR") ) {
		double param_offset_factor_value = request("EPSBUFR_PARAMETER_OFFSET_FACTOR");
		epsbufr_->param_offset_factor_ = param_offset_factor_value;
		}
	if  (request.countValues("EPSBUFR_Y_AXIS_PERCENTILE") ) {
		double percentile_value = request("EPSBUFR_Y_AXIS_PERCENTILE");
		epsbufr_->percentile_ = percentile_value;
		}
	if  (request.countValues("EPSBUFR_Y_AXIS_THRESHOLD") ) {
		double threshold_value = request("EPSBUFR_Y_AXIS_THRESHOLD");
		epsbufr_->threshold_ = threshold_value;
		}
	
	
}

void EpsBufrWrapper::print(ostream& out)  const
{
	out << "EpsBufrWrapper[]";
}


    



