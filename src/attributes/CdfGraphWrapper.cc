
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file CdfGraphAttributes.h
    \\brief Definition of CdfGraph Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "CdfGraphWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


CdfGraphWrapper::CdfGraphWrapper(): cdfgraph_(new CdfGraph())

{


	

}
CdfGraphWrapper::CdfGraphWrapper(CdfGraph* cdfgraph): cdfgraph_(cdfgraph)
{

	
}

CdfGraphWrapper::~CdfGraphWrapper()
{

}

void CdfGraphWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("CDF_GRAPH_TYPE") ) {
		string type_value = request("CDF_GRAPH_TYPE");
		cdfgraph_->type_ = type_value;
		}
	stringarray  colour_value;
	for (int i = 0; i < request.countValues("CDF_LINES_COLOUR_ARRAY"); i++)
		colour_value.push_back((string)request("CDF_LINES_COLOUR_ARRAY", i));
	if ( !colour_value.empty() )
		cdfgraph_->colour_ = colour_value;
	stringarray  style_value;
	for (int i = 0; i < request.countValues("CDF_LINES_STYLE_ARRAY"); i++)
		style_value.push_back((string)request("CDF_LINES_STYLE_ARRAY", i));
	if ( !style_value.empty() )
		cdfgraph_->style_ = style_value;
	intarray thickness_value;
	for (int i = 0; i < request.countValues("CDF_LINES_THICKNESS_ARRAY"); i++)
		thickness_value.push_back((int)request("CDF_LINES_THICKNESS_ARRAY", i));
	if ( !thickness_value.empty() )
		cdfgraph_->thickness_ = thickness_value;
	if  (request.countValues("CDF_CLIM_LINE_THICKNESS") ) {
		int clim_thickness_value = request("CDF_CLIM_LINE_THICKNESS");
		cdfgraph_->clim_thickness_ = clim_thickness_value;
		}
	if  (request.countValues("LEGEND") ) {
		string legend_value = request("LEGEND");
		cdfgraph_->legend_ = MagTranslator<string, bool>()(legend_value);
		}
	
	if  (request.countValues("CDF_CLIM_LINE_COLOUR") ) {
		string clim_colour_value = request("CDF_CLIM_LINE_COLOUR");
		cdfgraph_->clim_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(clim_colour_value));
	}
		
	
	if  (request.countValues("CDF_CLIM_LINE_STYLE") ) {
		string clim_style_value = request("CDF_CLIM_LINE_STYLE");
		cdfgraph_->clim_style_ = MagTranslator<string, LineStyle>()(clim_style_value);
	}
		
	
}

void CdfGraphWrapper::print(ostream& out)  const
{
	out << "CdfGraphWrapper[]";
}




∏