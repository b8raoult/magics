
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file MetgramCurveAttributes.h
    \\brief Definition of MetgramCurve Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "MetgramCurveWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


MetgramCurveWrapper::MetgramCurveWrapper(): metgramcurve_(new MetgramCurve())

{

	
	
	
} 
MetgramCurveWrapper::MetgramCurveWrapper(MetgramCurve* metgramcurve): metgramcurve_(metgramcurve)
{
	
	
} 

MetgramCurveWrapper::~MetgramCurveWrapper()
{
	
}

void MetgramCurveWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("METGRAM_CURVE_KEYWORD") ) {
		string keyword1_value = request("METGRAM_CURVE_KEYWORD");
		metgramcurve_->keyword1_ = keyword1_value;
		}
	if  (request.countValues("METGRAM_CURVE_KEYWORD2") ) {
		string keyword2_value = request("METGRAM_CURVE_KEYWORD2");
		metgramcurve_->keyword2_ = keyword2_value;
		}
	if  (request.countValues("METGRAM_CURVE_THICKNESS") ) {
		int thickness_value = request("METGRAM_CURVE_THICKNESS");
		metgramcurve_->thickness_ = thickness_value;
		}
	if  (request.countValues("METGRAM_CURVE2_THICKNESS") ) {
		int thickness2_value = request("METGRAM_CURVE2_THICKNESS");
		metgramcurve_->thickness2_ = thickness2_value;
		}
	
	
	if  (request.countValues("METGRAM_CURVE_LINE_STYLE") ) {
		string style_value = request("METGRAM_CURVE_LINE_STYLE");
		metgramcurve_->style_ = MagTranslator<string, LineStyle>()(style_value);
	}
		
	
	if  (request.countValues("METGRAM_CURVE2_LINE_STYLE") ) {
		string style2_value = request("METGRAM_CURVE2_LINE_STYLE");
		metgramcurve_->style2_ = MagTranslator<string, LineStyle>()(style2_value);
	}
		
	if  (request.countValues("METGRAM_CURVE_COLOUR") ) {
		string colour_value = request("METGRAM_CURVE_COLOUR");
		metgramcurve_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	if  (request.countValues("METGRAM_CURVE2_COLOUR") ) {
		string colour2_value = request("METGRAM_CURVE2_COLOUR");
		metgramcurve_->colour2_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour2_value));
	}
		
	
}

void MetgramCurveWrapper::print(ostream& out)  const
{
	out << "MetgramCurveWrapper[]";
}


    







