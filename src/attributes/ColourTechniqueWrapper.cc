
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ColourTechniqueAttributes.h
    \\brief Definition of ColourTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "ColourTechniqueWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


ColourTechniqueWrapper::ColourTechniqueWrapper(): colourtechnique_(new ColourTechnique())

{

	
	
	
} 
ColourTechniqueWrapper::ColourTechniqueWrapper(ColourTechnique* colourtechnique): colourtechnique_(colourtechnique)
{
	
	
} 

ColourTechniqueWrapper::~ColourTechniqueWrapper()
{
	
}

void ColourTechniqueWrapper::set(const MagRequest& request)
{
	
	

	
	
}

void ColourTechniqueWrapper::print(ostream& out)  const
{
	out << "ColourTechniqueWrapper[]";
}


    



