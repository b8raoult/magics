
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LookupTableModeAttributes.h
    \\brief Definition of LookupTableMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "LookupTableModeWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


LookupTableModeWrapper::LookupTableModeWrapper(): lookuptablemode_(new LookupTableMode())

{

	
	
	
} 
LookupTableModeWrapper::LookupTableModeWrapper(LookupTableMode* lookuptablemode): lookuptablemode_(lookuptablemode)
{
	
	
} 

LookupTableModeWrapper::~LookupTableModeWrapper()
{
	
}

void LookupTableModeWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("IMAGE_MIN_LEVEL") ) {
		int minLevel_value = request("IMAGE_MIN_LEVEL");
		lookuptablemode_->minLevel_ = minLevel_value;
		}
	if  (request.countValues("IMAGE_MAX_LEVEL") ) {
		int maxLevel_value = request("IMAGE_MAX_LEVEL");
		lookuptablemode_->maxLevel_ = maxLevel_value;
		}
	if  (request.countValues("IMAGE_OUTLAYER_REJECTION") ) {
		double outlayer_value = request("IMAGE_OUTLAYER_REJECTION");
		lookuptablemode_->outlayer_ = outlayer_value;
		}
	
	
}

void LookupTableModeWrapper::print(ostream& out)  const
{
	out << "LookupTableModeWrapper[]";
}


    



