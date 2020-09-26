
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4RobinsonAttributes.h
    \\brief Definition of Proj4Robinson Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "Proj4RobinsonWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


Proj4RobinsonWrapper::Proj4RobinsonWrapper(): proj4robinson_(new Proj4Robinson())

{

	
	
	Proj4ProjectionWrapper::object(proj4robinson_);
	
	
} 
Proj4RobinsonWrapper::Proj4RobinsonWrapper(Proj4Robinson* proj4robinson): proj4robinson_(proj4robinson)
{
	
	
	Proj4ProjectionWrapper::object(proj4robinson_);
	
} 

Proj4RobinsonWrapper::~Proj4RobinsonWrapper()
{
	
}

void Proj4RobinsonWrapper::set(const MagRequest& request)
{
	
	
	
	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4RobinsonWrapper::print(ostream& out)  const
{
	out << "Proj4RobinsonWrapper[]";
}


    



