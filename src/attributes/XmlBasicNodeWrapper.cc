
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file XmlBasicNodeAttributes.h
    \\brief Definition of XmlBasicNode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "MagRequest.h" 
#include "XmlBasicNodeWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


XmlBasicNodeWrapper::XmlBasicNodeWrapper(): xmlbasicnode_(new XmlBasicNode())

{

	
	
	
} 
XmlBasicNodeWrapper::XmlBasicNodeWrapper(XmlBasicNode* xmlbasicnode): xmlbasicnode_(xmlbasicnode)
{
	
	
} 

XmlBasicNodeWrapper::~XmlBasicNodeWrapper()
{
	
}

void XmlBasicNodeWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("VIEW_STANDALONE") ) {
		string standalone_value = request("VIEW_STANDALONE");
		xmlbasicnode_->standalone_ = MagTranslator<string, bool>()(standalone_value);
		}
	if  (request.countValues("VIEW_STANDALONE_FILE_NAME") ) {
		string standalone_path_value = request("VIEW_STANDALONE_FILE_NAME");
		xmlbasicnode_->standalone_path_ = standalone_path_value;
		}
	if  (request.countValues("VIEW_STANDALONE_FORMAT") ) {
		string standalone_format_value = request("VIEW_STANDALONE_FORMAT");
		xmlbasicnode_->standalone_format_ = standalone_format_value;
		}
	if  (request.countValues("VIEW_STANDALONE_WIDTH") ) {
		double standalone_width_value = request("VIEW_STANDALONE_WIDTH");
		xmlbasicnode_->standalone_width_ = standalone_width_value;
		}
	if  (request.countValues("VIEW_STANDALONE_HEIGHT") ) {
		double standalone_height_value = request("VIEW_STANDALONE_HEIGHT");
		xmlbasicnode_->standalone_height_ = standalone_height_value;
		}
	if  (request.countValues("VIEW_BOTTOM") ) {
		string bottom_value = request("VIEW_BOTTOM");
		xmlbasicnode_->bottom_ = bottom_value;
		}
	if  (request.countValues("VIEW_LEFT") ) {
		string left_value = request("VIEW_LEFT");
		xmlbasicnode_->left_ = left_value;
		}
	if  (request.countValues("VIEW_WIDTH") ) {
		string width_value = request("VIEW_WIDTH");
		xmlbasicnode_->width_ = width_value;
		}
	if  (request.countValues("VIEW_HEIGHT") ) {
		string height_value = request("VIEW_HEIGHT");
		xmlbasicnode_->height_ = height_value;
		}
	if  (request.countValues("VIEW_MARGIN_BOTTOM") ) {
		string margin_bottom_value = request("VIEW_MARGIN_BOTTOM");
		xmlbasicnode_->margin_bottom_ = margin_bottom_value;
		}
	if  (request.countValues("VIEW_MARGIN_LEFT") ) {
		string margin_left_value = request("VIEW_MARGIN_LEFT");
		xmlbasicnode_->margin_left_ = margin_left_value;
		}
	if  (request.countValues("VIEW_MARGIN_RIGHT") ) {
		string margin_right_value = request("VIEW_MARGIN_RIGHT");
		xmlbasicnode_->margin_right_ = margin_right_value;
		}
	if  (request.countValues("VIEW_MARGIN_TOP") ) {
		string margin_top_value = request("VIEW_MARGIN_TOP");
		xmlbasicnode_->margin_top_ = margin_top_value;
		}
	if  (request.countValues("VIEW_BORDER_BOTTOM") ) {
		string border_bottom_value = request("VIEW_BORDER_BOTTOM");
		xmlbasicnode_->border_bottom_ = border_bottom_value;
		}
	if  (request.countValues("VIEW_BORDER_LEFT") ) {
		string border_left_value = request("VIEW_BORDER_LEFT");
		xmlbasicnode_->border_left_ = border_left_value;
		}
	if  (request.countValues("VIEW_BORDER_RIGHT") ) {
		string border_right_value = request("VIEW_BORDER_RIGHT");
		xmlbasicnode_->border_right_ = border_right_value;
		}
	if  (request.countValues("VIEW_BORDER_TOP") ) {
		string border_top_value = request("VIEW_BORDER_TOP");
		xmlbasicnode_->border_top_ = border_top_value;
		}
	if  (request.countValues("VIEW_BORDER") ) {
		string border_value = request("VIEW_BORDER");
		xmlbasicnode_->border_ = MagTranslator<string, bool>()(border_value);
		}
	if  (request.countValues("VIEW_BLANKING") ) {
		string blanking_value = request("VIEW_BLANKING");
		xmlbasicnode_->blanking_ = MagTranslator<string, bool>()(blanking_value);
		}
	if  (request.countValues("VIEW_BORDER_THICKNESS") ) {
		int border_thickness_value = request("VIEW_BORDER_THICKNESS");
		xmlbasicnode_->border_thickness_ = border_thickness_value;
		}
	if  (request.countValues("VIEW_PADDING_BOTTOM") ) {
		string padding_bottom_value = request("VIEW_PADDING_BOTTOM");
		xmlbasicnode_->padding_bottom_ = padding_bottom_value;
		}
	if  (request.countValues("VIEW_PADDING_LEFT") ) {
		string padding_left_value = request("VIEW_PADDING_LEFT");
		xmlbasicnode_->padding_left_ = padding_left_value;
		}
	if  (request.countValues("VIEW_PADDING_RIGHT") ) {
		string padding_right_value = request("VIEW_PADDING_RIGHT");
		xmlbasicnode_->padding_right_ = padding_right_value;
		}
	if  (request.countValues("VIEW_PADDING_TOP") ) {
		string padding_top_value = request("VIEW_PADDING_TOP");
		xmlbasicnode_->padding_top_ = padding_top_value;
		}
	
	
	if  (request.countValues("VIEW_DISPLAY") ) {
		string display_value = request("VIEW_DISPLAY");
		xmlbasicnode_->display_ = MagTranslator<string, DisplayType>()(display_value);
	}
		
	if  (request.countValues("VIEW_BACKGROUND_COLOUR") ) {
		string background_value = request("VIEW_BACKGROUND_COLOUR");
		xmlbasicnode_->background_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(background_value));
	}
		
	if  (request.countValues("VIEW_BORDER_COLOUR") ) {
		string border_colour_value = request("VIEW_BORDER_COLOUR");
		xmlbasicnode_->border_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(border_colour_value));
	}
		
	
	if  (request.countValues("VIEW_BORDER_STYLE") ) {
		string border_style_value = request("VIEW_BORDER_STYLE");
		xmlbasicnode_->border_style_ = MagTranslator<string, LineStyle>()(border_style_value);
	}
		
	if  (request.countValues("VIEW_PADDING_COLOUR") ) {
		string padding_colour_value = request("VIEW_PADDING_COLOUR");
		xmlbasicnode_->padding_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(padding_colour_value));
	}
		
	
}

void XmlBasicNodeWrapper::print(ostream& out)  const
{
	out << "XmlBasicNodeWrapper[]";
}


    








