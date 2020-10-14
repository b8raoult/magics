
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file IsoLabelAttributes.h
    \\brief Definition of IsoLabel Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "IsoLabelWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


IsoLabelWrapper::IsoLabelWrapper(): isolabel_(new IsoLabel())

{


	
	NoIsoLabelWrapper::object(isolabel_);
	

}
IsoLabelWrapper::IsoLabelWrapper(IsoLabel* isolabel): isolabel_(isolabel)
{

	
	NoIsoLabelWrapper::object(isolabel_);
	
}

IsoLabelWrapper::~IsoLabelWrapper()
{

}

void IsoLabelWrapper::set(const MagRequest& request)
{

	

	NoIsoLabelWrapper::set(request);
	

	if  (request.countValues("CONTOUR_LABEL_TYPE") ) {
		string type_value = request("CONTOUR_LABEL_TYPE");
		isolabel_->type_ = type_value;
		}
	if  (request.countValues("CONTOUR_LABEL_TEXT") ) {
		string text_value = request("CONTOUR_LABEL_TEXT");
		isolabel_->text_ = text_value;
		}
	if  (request.countValues("CONTOUR_LABEL_HEIGHT") ) {
		double height_value = request("CONTOUR_LABEL_HEIGHT");
		isolabel_->height_ = height_value;
		}
	if  (request.countValues("CONTOUR_LABEL_FORMAT") ) {
		string format_value = request("CONTOUR_LABEL_FORMAT");
		isolabel_->format_ = format_value;
		}
	if  (request.countValues("CONTOUR_LABEL_BLANKING") ) {
		string blanking_value = request("CONTOUR_LABEL_BLANKING");
		isolabel_->blanking_ = MagTranslator<string, bool>()(blanking_value);
		}
	if  (request.countValues("CONTOUR_LABEL_FONT") ) {
		string font_value = request("CONTOUR_LABEL_FONT");
		isolabel_->font_ = font_value;
		}
	if  (request.countValues("CONTOUR_LABEL_FONT_STYLE") ) {
		string style_value = request("CONTOUR_LABEL_FONT_STYLE");
		isolabel_->style_ = style_value;
		}
	if  (request.countValues("CONTOUR_LABEL_COLOUR") ) {
		string colour_value = request("CONTOUR_LABEL_COLOUR");
		isolabel_->colour_ = colour_value;
		}
	if  (request.countValues("CONTOUR_LABEL_FREQUENCY") ) {
		int frequency_value = request("CONTOUR_LABEL_FREQUENCY");
		isolabel_->frequency_ = frequency_value;
		}
	
	
}

void IsoLabelWrapper::print(ostream& out)  const
{
	out << "IsoLabelWrapper[]";
}


∏