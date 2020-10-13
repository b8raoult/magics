
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file TransformationAttributes.h
    \\brief Definition of Transformation Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "MagRequest.h" 
#include "TransformationWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


TransformationWrapper::TransformationWrapper(): transformation_(new Transformation())

{

	
	
	
} 
TransformationWrapper::TransformationWrapper(Transformation* transformation): transformation_(transformation)
{
	
	
} 

TransformationWrapper::~TransformationWrapper()
{
	
}

void TransformationWrapper::set(const MagRequest& request)
{
	
	

	
	
}

void TransformationWrapper::print(ostream& out)  const
{
	out << "TransformationWrapper[]";
}


    



