
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file BoundariesAttributes.h
    \\brief Definition of Boundaries Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "BoundariesWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


BoundariesWrapper::BoundariesWrapper(): boundaries_(new Boundaries())

{

	
	
	NoBoundariesWrapper::object(boundaries_);
	
	
} 
BoundariesWrapper::BoundariesWrapper(Boundaries* boundaries): boundaries_(boundaries)
{
	
	
	NoBoundariesWrapper::object(boundaries_);
	
} 

BoundariesWrapper::~BoundariesWrapper()
{
	
}

void BoundariesWrapper::set(const MagRequest& request)
{
	
	
	
	NoBoundariesWrapper::set(request);
	

	if  (request.countValues("MAP_BOUNDARIES_THICKNESS") ) {
		int thickness_value = request("MAP_BOUNDARIES_THICKNESS");
		boundaries_->thickness_ = thickness_value;
		}
	if  (request.countValues("MAP_DISPUTED_BOUNDARIES") ) {
		string disputed_value = request("MAP_DISPUTED_BOUNDARIES");
		boundaries_->disputed_ = MagTranslator<string, bool>()(disputed_value);
		}
	if  (request.countValues("MAP_DISPUTED_BOUNDARIES_THICKNESS") ) {
		int disputed_thickness_value = request("MAP_DISPUTED_BOUNDARIES_THICKNESS");
		boundaries_->disputed_thickness_ = disputed_thickness_value;
		}
	if  (request.countValues("MAP_ADMINISTRATIVE_BOUNDARIES") ) {
		string admistrative_value = request("MAP_ADMINISTRATIVE_BOUNDARIES");
		boundaries_->admistrative_ = MagTranslator<string, bool>()(admistrative_value);
		}
	stringarray  administrative_list_value;
	for (int i = 0; i < request.countValues("MAP_ADMINISTRATIVE_BOUNDARIES_COUNTRIES_LIST"); i++)
		administrative_list_value.push_back((string)request("MAP_ADMINISTRATIVE_BOUNDARIES_COUNTRIES_LIST", i));
	if ( !administrative_list_value.empty() ) 
		boundaries_->administrative_list_ = administrative_list_value;
	if  (request.countValues("MAP_ADMINISTRATIVE_BOUNDARIES_THICKNESS") ) {
		int administrative_thickness_value = request("MAP_ADMINISTRATIVE_BOUNDARIES_THICKNESS");
		boundaries_->administrative_thickness_ = administrative_thickness_value;
		}
	
	
	if  (request.countValues("MAP_BOUNDARIES_STYLE") ) {
		string style_value = request("MAP_BOUNDARIES_STYLE");
		boundaries_->style_ = MagTranslator<string, LineStyle>()(style_value);
	}
		
	if  (request.countValues("MAP_BOUNDARIES_COLOUR") ) {
		string colour_value = request("MAP_BOUNDARIES_COLOUR");
		boundaries_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
	if  (request.countValues("MAP_DISPUTED_BOUNDARIES_STYLE") ) {
		string disputed_style_value = request("MAP_DISPUTED_BOUNDARIES_STYLE");
		boundaries_->disputed_style_ = MagTranslator<string, LineStyle>()(disputed_style_value);
	}
		
	if  (request.countValues("MAP_DISPUTED_BOUNDARIES_COLOUR") ) {
		string disputed_colour_value = request("MAP_DISPUTED_BOUNDARIES_COLOUR");
		boundaries_->disputed_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(disputed_colour_value));
	}
		
	
	if  (request.countValues("MAP_ADMINISTRATIVE_BOUNDARIES_STYLE") ) {
		string administrative_style_value = request("MAP_ADMINISTRATIVE_BOUNDARIES_STYLE");
		boundaries_->administrative_style_ = MagTranslator<string, LineStyle>()(administrative_style_value);
	}
		
	if  (request.countValues("MAP_ADMINISTRATIVE_BOUNDARIES_COLOUR") ) {
		string administrative_colour_value = request("MAP_ADMINISTRATIVE_BOUNDARIES_COLOUR");
		boundaries_->administrative_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(administrative_colour_value));
	}
		
	
}

void BoundariesWrapper::print(ostream& out)  const
{
	out << "BoundariesWrapper[]";
}


    









