
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file NoIsoPlotAttributes.h
    \\brief Definition of NoIsoPlot Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "NoIsoPlotWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


NoIsoPlotWrapper::NoIsoPlotWrapper(): noisoplot_(new NoIsoPlot())

{

	
	
	IsoPlotWrapper::object(noisoplot_);
	
	
} 
NoIsoPlotWrapper::NoIsoPlotWrapper(NoIsoPlot* noisoplot): noisoplot_(noisoplot)
{
	
	
	IsoPlotWrapper::object(noisoplot_);
	
} 

NoIsoPlotWrapper::~NoIsoPlotWrapper()
{
	
}

void NoIsoPlotWrapper::set(const MagRequest& request)
{
	
	
	
	IsoPlotWrapper::set(request);
	

	
	
}

void NoIsoPlotWrapper::print(ostream& out)  const
{
	out << "NoIsoPlotWrapper[]";
}


    



