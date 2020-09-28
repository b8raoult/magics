
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4MollweideAttributes.h
    \\brief Definition of Proj4Mollweide Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "Proj4MollweideWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


Proj4MollweideWrapper::Proj4MollweideWrapper(): proj4mollweide_(new Proj4Mollweide())

{

	
	
	Proj4ProjectionWrapper::object(proj4mollweide_);
	
	
} 
Proj4MollweideWrapper::Proj4MollweideWrapper(Proj4Mollweide* proj4mollweide): proj4mollweide_(proj4mollweide)
{
	
	
	Proj4ProjectionWrapper::object(proj4mollweide_);
	
} 

Proj4MollweideWrapper::~Proj4MollweideWrapper()
{
	
}

void Proj4MollweideWrapper::set(const MagRequest& request)
{
	
	
	
	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4MollweideWrapper::print(ostream& out)  const
{
	out << "Proj4MollweideWrapper[]";
}


    



