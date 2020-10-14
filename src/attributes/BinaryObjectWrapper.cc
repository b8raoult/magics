
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file BinaryObjectAttributes.h
    \\brief Definition of BinaryObject Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "BinaryObjectWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


BinaryObjectWrapper::BinaryObjectWrapper(): binaryobject_(new BinaryObject())

{


	

}
BinaryObjectWrapper::BinaryObjectWrapper(BinaryObject* binaryobject): binaryobject_(binaryobject)
{

	
}

BinaryObjectWrapper::~BinaryObjectWrapper()
{

}

void BinaryObjectWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("MGB_FILENAME") ) {
		string path_value = request("MGB_FILENAME");
		binaryobject_->path_ = path_value;
		}
	if  (request.countValues("MGB_TRANSPARENCY") ) {
		double transparency_value = request("MGB_TRANSPARENCY");
		binaryobject_->transparency_ = transparency_value;
		}
	if  (request.countValues("MGB_X") ) {
		double mgb_x_value = request("MGB_X");
		binaryobject_->mgb_x_ = mgb_x_value;
		}
	if  (request.countValues("MGB_Y") ) {
		double mgb_y_value = request("MGB_Y");
		binaryobject_->mgb_y_ = mgb_y_value;
		}
	if  (request.countValues("MGB_WIDTH") ) {
		double mgb_width_value = request("MGB_WIDTH");
		binaryobject_->mgb_width_ = mgb_width_value;
		}
	if  (request.countValues("MGB_HEIGHT") ) {
		double mgb_height_value = request("MGB_HEIGHT");
		binaryobject_->mgb_height_ = mgb_height_value;
		}
	if  (request.countValues("MGB_BLUR_RADIUS") ) {
		int mgb_blur_radius_value = request("MGB_BLUR_RADIUS");
		binaryobject_->mgb_blur_radius_ = mgb_blur_radius_value;
		}
	
	
}

void BinaryObjectWrapper::print(ostream& out)  const
{
	out << "BinaryObjectWrapper[]";
}


∏