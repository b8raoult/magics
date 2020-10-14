
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4GoodeAttributes.h
    \\brief Definition of Proj4Goode Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "Proj4GoodeWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


Proj4GoodeWrapper::Proj4GoodeWrapper(): proj4goode_(new Proj4Goode())

{


	
	Proj4ProjectionWrapper::object(proj4goode_);
	

}
Proj4GoodeWrapper::Proj4GoodeWrapper(Proj4Goode* proj4goode): proj4goode_(proj4goode)
{

	
	Proj4ProjectionWrapper::object(proj4goode_);
	
}

Proj4GoodeWrapper::~Proj4GoodeWrapper()
{

}

void Proj4GoodeWrapper::set(const MagRequest& request)
{

	

	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4GoodeWrapper::print(ostream& out)  const
{
	out << "Proj4GoodeWrapper[]";
}


∏