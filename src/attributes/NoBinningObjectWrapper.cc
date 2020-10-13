
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file NoBinningObjectAttributes.h
    \\brief Definition of NoBinningObject Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "MagRequest.h" 
#include "NoBinningObjectWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


NoBinningObjectWrapper::NoBinningObjectWrapper(): nobinningobject_(new NoBinningObject())

{

	
	
	BinningObjectWrapper::object(nobinningobject_);
	
	
} 
NoBinningObjectWrapper::NoBinningObjectWrapper(NoBinningObject* nobinningobject): nobinningobject_(nobinningobject)
{
	
	
	BinningObjectWrapper::object(nobinningobject_);
	
} 

NoBinningObjectWrapper::~NoBinningObjectWrapper()
{
	
}

void NoBinningObjectWrapper::set(const MagRequest& request)
{
	
	
	
	BinningObjectWrapper::set(request);
	

	
	
}

void NoBinningObjectWrapper::print(ostream& out)  const
{
	out << "NoBinningObjectWrapper[]";
}


    



