
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4Meteosat145Attributes.h
    \\brief Definition of Proj4Meteosat145 Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "Proj4Meteosat145Wrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


Proj4Meteosat145Wrapper::Proj4Meteosat145Wrapper(): proj4meteosat145_(new Proj4Meteosat145())

{


	
	Proj4ProjectionWrapper::object(proj4meteosat145_);
	

}
Proj4Meteosat145Wrapper::Proj4Meteosat145Wrapper(Proj4Meteosat145* proj4meteosat145): proj4meteosat145_(proj4meteosat145)
{

	
	Proj4ProjectionWrapper::object(proj4meteosat145_);
	
}

Proj4Meteosat145Wrapper::~Proj4Meteosat145Wrapper()
{

}

void Proj4Meteosat145Wrapper::set(const MagRequest& request)
{

	

	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4Meteosat145Wrapper::print(ostream& out)  const
{
	out << "Proj4Meteosat145Wrapper[]";
}


