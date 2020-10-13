
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file IsoHighlightAttributes.h
    \\brief Definition of IsoHighlight Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "MagRequest.h" 
#include "IsoHighlightWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


IsoHighlightWrapper::IsoHighlightWrapper(): isohighlight_(new IsoHighlight())

{

	
	
	NoIsoHighlightWrapper::object(isohighlight_);
	
	
} 
IsoHighlightWrapper::IsoHighlightWrapper(IsoHighlight* isohighlight): isohighlight_(isohighlight)
{
	
	
	NoIsoHighlightWrapper::object(isohighlight_);
	
} 

IsoHighlightWrapper::~IsoHighlightWrapper()
{
	
}

void IsoHighlightWrapper::set(const MagRequest& request)
{
	
	
	
	NoIsoHighlightWrapper::set(request);
	

	if  (request.countValues("CONTOUR_REFERENCE_LEVEL") ) {
		double reference_value = request("CONTOUR_REFERENCE_LEVEL");
		isohighlight_->reference_ = reference_value;
		}
	if  (request.countValues("CONTOUR_HIGHLIGHT_THICKNESS") ) {
		int thickness_value = request("CONTOUR_HIGHLIGHT_THICKNESS");
		isohighlight_->thickness_ = thickness_value;
		}
	if  (request.countValues("CONTOUR_HIGHLIGHT_FREQUENCY") ) {
		int frequency_value = request("CONTOUR_HIGHLIGHT_FREQUENCY");
		isohighlight_->frequency_ = frequency_value;
		}
	
	
	if  (request.countValues("CONTOUR_HIGHLIGHT_STYLE") ) {
		string style_value = request("CONTOUR_HIGHLIGHT_STYLE");
		isohighlight_->style_ = MagTranslator<string, LineStyle>()(style_value);
	}
		
	if  (request.countValues("CONTOUR_HIGHLIGHT_COLOUR") ) {
		string colour_value = request("CONTOUR_HIGHLIGHT_COLOUR");
		isohighlight_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
}

void IsoHighlightWrapper::print(ostream& out)  const
{
	out << "IsoHighlightWrapper[]";
}


    





