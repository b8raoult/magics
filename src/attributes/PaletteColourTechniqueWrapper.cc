
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file PaletteColourTechniqueAttributes.h
    \\brief Definition of PaletteColourTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "PaletteColourTechniqueWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


PaletteColourTechniqueWrapper::PaletteColourTechniqueWrapper(): palettecolourtechnique_(new PaletteColourTechnique())

{

	
	
	ColourTechniqueWrapper::object(palettecolourtechnique_);
	
	
} 
PaletteColourTechniqueWrapper::PaletteColourTechniqueWrapper(PaletteColourTechnique* palettecolourtechnique): palettecolourtechnique_(palettecolourtechnique)
{
	
	
	ColourTechniqueWrapper::object(palettecolourtechnique_);
	
} 

PaletteColourTechniqueWrapper::~PaletteColourTechniqueWrapper()
{
	
}

void PaletteColourTechniqueWrapper::set(const MagRequest& request)
{
	
	
	
	ColourTechniqueWrapper::set(request);
	

	if  (request.countValues("CONTOUR_SHADE_PALETTE_NAME") ) {
		string palette_value = request("CONTOUR_SHADE_PALETTE_NAME");
		palettecolourtechnique_->palette_ = palette_value;
		}
	
	
	if  (request.countValues("CONTOUR_SHADE_PALETTE_POLICY") ) {
		string palette_policy_value = request("CONTOUR_SHADE_PALETTE_POLICY");
		palettecolourtechnique_->palette_policy_ = MagTranslator<string, ListPolicy>()(palette_policy_value);
	}
		
	
}

void PaletteColourTechniqueWrapper::print(ostream& out)  const
{
	out << "PaletteColourTechniqueWrapper[]";
}


    




