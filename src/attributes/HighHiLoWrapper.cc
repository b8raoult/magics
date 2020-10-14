
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file HighHiLoAttributes.h
    \\brief Definition of HighHiLo Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "HighHiLoWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


HighHiLoWrapper::HighHiLoWrapper(): highhilo_(new HighHiLo())

{


	
	HiLoWrapper::object(highhilo_);
	

}
HighHiLoWrapper::HighHiLoWrapper(HighHiLo* highhilo): highhilo_(highhilo)
{

	
	HiLoWrapper::object(highhilo_);
	
}

HighHiLoWrapper::~HighHiLoWrapper()
{

}

void HighHiLoWrapper::set(const MagRequest& request)
{

	

	HiLoWrapper::set(request);
	

	
	
}

void HighHiLoWrapper::print(ostream& out)  const
{
	out << "HighHiLoWrapper[]";
}


∏