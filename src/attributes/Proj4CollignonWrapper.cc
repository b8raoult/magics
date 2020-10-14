
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4CollignonAttributes.h
    \\brief Definition of Proj4Collignon Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "Proj4CollignonWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


Proj4CollignonWrapper::Proj4CollignonWrapper(): proj4collignon_(new Proj4Collignon())

{


	
	Proj4ProjectionWrapper::object(proj4collignon_);
	

}
Proj4CollignonWrapper::Proj4CollignonWrapper(Proj4Collignon* proj4collignon): proj4collignon_(proj4collignon)
{

	
	Proj4ProjectionWrapper::object(proj4collignon_);
	
}

Proj4CollignonWrapper::~Proj4CollignonWrapper()
{

}

void Proj4CollignonWrapper::set(const MagRequest& request)
{

	

	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4CollignonWrapper::print(ostream& out)  const
{
	out << "Proj4CollignonWrapper[]";
}


∏