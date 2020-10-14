
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file BothValuePlotMethodAttributes.h
    \\brief Definition of BothValuePlotMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "BothValuePlotMethodWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


BothValuePlotMethodWrapper::BothValuePlotMethodWrapper(): bothvalueplotmethod_(new BothValuePlotMethod())

{


	
	ValuePlotMethodWrapper::object(bothvalueplotmethod_);
	

}
BothValuePlotMethodWrapper::BothValuePlotMethodWrapper(BothValuePlotMethod* bothvalueplotmethod): bothvalueplotmethod_(bothvalueplotmethod)
{

	
	ValuePlotMethodWrapper::object(bothvalueplotmethod_);
	
}

BothValuePlotMethodWrapper::~BothValuePlotMethodWrapper()
{

}

void BothValuePlotMethodWrapper::set(const MagRequest& request)
{

	

	ValuePlotMethodWrapper::set(request);
	

	if  (request.countValues("CONTOUR_GRID_VALUE_MARKER_HEIGHT") ) {
		double marker_height_value = request("CONTOUR_GRID_VALUE_MARKER_HEIGHT");
		bothvalueplotmethod_->marker_height_ = marker_height_value;
		}
	if  (request.countValues("CONTOUR_GRID_VALUE_MARKER_QUAL") ) {
		string marker_quality_value = request("CONTOUR_GRID_VALUE_MARKER_QUAL");
		bothvalueplotmethod_->marker_quality_ = marker_quality_value;
		}
	if  (request.countValues("CONTOUR_GRID_VALUE_MARKER_INDEX") ) {
		int marker_index_value = request("CONTOUR_GRID_VALUE_MARKER_INDEX");
		bothvalueplotmethod_->marker_index_ = marker_index_value;
		}
	if  (request.countValues("CONTOUR_GRID_VALUE_POSITION") ) {
		string position_value = request("CONTOUR_GRID_VALUE_POSITION");
		bothvalueplotmethod_->position_ = position_value;
		}
	
	if  (request.countValues("CONTOUR_GRID_VALUE_MARKER_COLOUR") ) {
		string marker_colour_value = request("CONTOUR_GRID_VALUE_MARKER_COLOUR");
		bothvalueplotmethod_->marker_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(marker_colour_value));
	}
		
	
}

void BothValuePlotMethodWrapper::print(ostream& out)  const
{
	out << "BothValuePlotMethodWrapper[]";
}



∏