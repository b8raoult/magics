
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4EPSG3857Attributes.h
    \\brief Definition of Proj4EPSG3857 Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "Proj4EPSG3857Wrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


Proj4EPSG3857Wrapper::Proj4EPSG3857Wrapper(): proj4epsg3857_(new Proj4EPSG3857())

{


	
	Proj4ProjectionWrapper::object(proj4epsg3857_);
	

}
Proj4EPSG3857Wrapper::Proj4EPSG3857Wrapper(Proj4EPSG3857* proj4epsg3857): proj4epsg3857_(proj4epsg3857)
{

	
	Proj4ProjectionWrapper::object(proj4epsg3857_);
	
}

Proj4EPSG3857Wrapper::~Proj4EPSG3857Wrapper()
{

}

void Proj4EPSG3857Wrapper::set(const MagRequest& request)
{

	

	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4EPSG3857Wrapper::print(ostream& out)  const
{
	out << "Proj4EPSG3857Wrapper[]";
}


∏