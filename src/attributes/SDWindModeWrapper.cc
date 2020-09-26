
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SDWindModeAttributes.h
    \\brief Definition of SDWindMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "SDWindModeWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


SDWindModeWrapper::SDWindModeWrapper(): sdwindmode_(new SDWindMode())

{

	
	
	WindModeWrapper::object(sdwindmode_);
	
	
} 
SDWindModeWrapper::SDWindModeWrapper(SDWindMode* sdwindmode): sdwindmode_(sdwindmode)
{
	
	
	WindModeWrapper::object(sdwindmode_);
	
} 

SDWindModeWrapper::~SDWindModeWrapper()
{
	
}

void SDWindModeWrapper::set(const MagRequest& request)
{
	
	
	
	WindModeWrapper::set(request);
	

	
	
}

void SDWindModeWrapper::print(ostream& out)  const
{
	out << "SDWindModeWrapper[]";
}


    



