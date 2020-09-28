
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file XYListAttributes.h
    \\brief Definition of XYList Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "XYListWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


XYListWrapper::XYListWrapper(): xylist_(new XYList())

{

	
	
	
} 
XYListWrapper::XYListWrapper(XYList* xylist): xylist_(xylist)
{
	
	
} 

XYListWrapper::~XYListWrapper()
{
	
}

void XYListWrapper::set(const MagRequest& request)
{
	
	

	doublearray  x_value;
	for (int i = 0; i < request.countValues("X_VALUES"); i++)
		x_value.push_back((double)request("X_VALUES", i));
	if ( !x_value.empty() ) 
		xylist_->x_ = x_value;
	doublearray  y_value;
	for (int i = 0; i < request.countValues("Y_VALUES"); i++)
		y_value.push_back((double)request("Y_VALUES", i));
	if ( !y_value.empty() ) 
		xylist_->y_ = y_value;
	stringarray  x_date_value;
	for (int i = 0; i < request.countValues("X_DATE_VALUES"); i++)
		x_date_value.push_back((string)request("X_DATE_VALUES", i));
	if ( !x_date_value.empty() ) 
		xylist_->x_date_ = x_date_value;
	if  (request.countValues("X_BASE_DATE") ) {
		string x_base_value = request("X_BASE_DATE");
		xylist_->x_base_ = x_base_value;
		}
	if  (request.countValues("X_DATE_OFFSET") ) {
		string x_offset_value = request("X_DATE_OFFSET");
		xylist_->x_offset_ = x_offset_value;
		}
	if  (request.countValues("Y_BASE_DATE") ) {
		string y_base_value = request("Y_BASE_DATE");
		xylist_->y_base_ = y_base_value;
		}
	if  (request.countValues("Y_DATE_OFFSET") ) {
		string y_offset_value = request("Y_DATE_OFFSET");
		xylist_->y_offset_ = y_offset_value;
		}
	stringarray  y_date_value;
	for (int i = 0; i < request.countValues("Y_DATE_VALUES"); i++)
		y_date_value.push_back((string)request("Y_DATE_VALUES", i));
	if ( !y_date_value.empty() ) 
		xylist_->y_date_ = y_date_value;
	if  (request.countValues("X_MISSING_VALUE") ) {
		double x_missing_value = request("X_MISSING_VALUE");
		xylist_->x_missing_ = x_missing_value;
		}
	if  (request.countValues("Y_MISSING_VALUE") ) {
		double y_missing_value = request("Y_MISSING_VALUE");
		xylist_->y_missing_ = y_missing_value;
		}
	doublearray  x2_value;
	for (int i = 0; i < request.countValues("X2_VALUES"); i++)
		x2_value.push_back((double)request("X2_VALUES", i));
	if ( !x2_value.empty() ) 
		xylist_->x2_ = x2_value;
	doublearray  y2_value;
	for (int i = 0; i < request.countValues("Y2_VALUES"); i++)
		y2_value.push_back((double)request("Y2_VALUES", i));
	if ( !y2_value.empty() ) 
		xylist_->y2_ = y2_value;
	if  (request.countValues("X2_BASE_DATE") ) {
		string x2_base_value = request("X2_BASE_DATE");
		xylist_->x2_base_ = x2_base_value;
		}
	if  (request.countValues("X2_DATE_OFFSET") ) {
		string x2_offset_value = request("X2_DATE_OFFSET");
		xylist_->x2_offset_ = x2_offset_value;
		}
	stringarray  x2_date_value;
	for (int i = 0; i < request.countValues("X2_DATE_VALUES"); i++)
		x2_date_value.push_back((string)request("X2_DATE_VALUES", i));
	if ( !x2_date_value.empty() ) 
		xylist_->x2_date_ = x2_date_value;
	if  (request.countValues("Y2_BASE_DATE") ) {
		string y2_base_value = request("Y2_BASE_DATE");
		xylist_->y2_base_ = y2_base_value;
		}
	if  (request.countValues("Y2_DATE_OFFSET") ) {
		string y2_offset_value = request("Y2_DATE_OFFSET");
		xylist_->y2_offset_ = y2_offset_value;
		}
	stringarray  y2_date_value;
	for (int i = 0; i < request.countValues("Y2_DATE_VALUES"); i++)
		y2_date_value.push_back((string)request("Y2_DATE_VALUES", i));
	if ( !y2_date_value.empty() ) 
		xylist_->y2_date_ = y2_date_value;
	doublearray  x_lower_value;
	for (int i = 0; i < request.countValues("X_LOWER_VALUES"); i++)
		x_lower_value.push_back((double)request("X_LOWER_VALUES", i));
	if ( !x_lower_value.empty() ) 
		xylist_->x_lower_ = x_lower_value;
	doublearray  y_lower_value;
	for (int i = 0; i < request.countValues("Y_LOWER_VALUES"); i++)
		y_lower_value.push_back((double)request("Y_LOWER_VALUES", i));
	if ( !y_lower_value.empty() ) 
		xylist_->y_lower_ = y_lower_value;
	stringarray  x_lower_date_value;
	for (int i = 0; i < request.countValues("X_LOWER_DATE_VALUES"); i++)
		x_lower_date_value.push_back((string)request("X_LOWER_DATE_VALUES", i));
	if ( !x_lower_date_value.empty() ) 
		xylist_->x_lower_date_ = x_lower_date_value;
	stringarray  y_lower_date_value;
	for (int i = 0; i < request.countValues("Y_LOWER_DATE_VALUES"); i++)
		y_lower_date_value.push_back((string)request("Y_LOWER_DATE_VALUES", i));
	if ( !y_lower_date_value.empty() ) 
		xylist_->y_lower_date_ = y_lower_date_value;
	doublearray  x_upper_value;
	for (int i = 0; i < request.countValues("X_UPPER_VALUES"); i++)
		x_upper_value.push_back((double)request("X_UPPER_VALUES", i));
	if ( !x_upper_value.empty() ) 
		xylist_->x_upper_ = x_upper_value;
	doublearray  y_upper_value;
	for (int i = 0; i < request.countValues("Y_UPPER_VALUES"); i++)
		y_upper_value.push_back((double)request("Y_UPPER_VALUES", i));
	if ( !y_upper_value.empty() ) 
		xylist_->y_upper_ = y_upper_value;
	stringarray  x_upper_date_value;
	for (int i = 0; i < request.countValues("X_UPPER_DATE_VALUES"); i++)
		x_upper_date_value.push_back((string)request("X_UPPER_DATE_VALUES", i));
	if ( !x_upper_date_value.empty() ) 
		xylist_->x_upper_date_ = x_upper_date_value;
	stringarray  y_upper_date_value;
	for (int i = 0; i < request.countValues("Y_UPPER_DATE_VALUES"); i++)
		y_upper_date_value.push_back((string)request("Y_UPPER_DATE_VALUES", i));
	if ( !y_upper_date_value.empty() ) 
		xylist_->y_upper_date_ = y_upper_date_value;
	
	
}

void XYListWrapper::print(ostream& out)  const
{
	out << "XYListWrapper[]";
}


    



