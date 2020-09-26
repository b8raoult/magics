
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GribAddressByteModeAttributes.h
    \\brief Definition of GribAddressByteMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "GribAddressByteModeWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


GribAddressByteModeWrapper::GribAddressByteModeWrapper(): gribaddressbytemode_(new GribAddressByteMode())

{

	
	
	GribAddressModeWrapper::object(gribaddressbytemode_);
	
	
} 
GribAddressByteModeWrapper::GribAddressByteModeWrapper(GribAddressByteMode* gribaddressbytemode): gribaddressbytemode_(gribaddressbytemode)
{
	
	
	GribAddressModeWrapper::object(gribaddressbytemode_);
	
} 

GribAddressByteModeWrapper::~GribAddressByteModeWrapper()
{
	
}

void GribAddressByteModeWrapper::set(const MagRequest& request)
{
	
	
	
	GribAddressModeWrapper::set(request);
	

	
	
}

void GribAddressByteModeWrapper::print(ostream& out)  const
{
	out << "GribAddressByteModeWrapper[]";
}


    



