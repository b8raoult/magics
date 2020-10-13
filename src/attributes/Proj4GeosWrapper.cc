
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4GeosAttributes.h
    \\brief Definition of Proj4Geos Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "MagRequest.h" 
#include "Proj4GeosWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


Proj4GeosWrapper::Proj4GeosWrapper(): proj4geos_(new Proj4Geos())

{

	
	
	Proj4ProjectionWrapper::object(proj4geos_);
	
	
} 
Proj4GeosWrapper::Proj4GeosWrapper(Proj4Geos* proj4geos): proj4geos_(proj4geos)
{
	
	
	Proj4ProjectionWrapper::object(proj4geos_);
	
} 

Proj4GeosWrapper::~Proj4GeosWrapper()
{
	
}

void Proj4GeosWrapper::set(const MagRequest& request)
{
	
	
	
	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4GeosWrapper::print(ostream& out)  const
{
	out << "Proj4GeosWrapper[]";
}


    



