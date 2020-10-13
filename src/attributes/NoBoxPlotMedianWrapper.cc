
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file NoBoxPlotMedianAttributes.h
    \\brief Definition of NoBoxPlotMedian Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "MagRequest.h" 
#include "NoBoxPlotMedianWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


NoBoxPlotMedianWrapper::NoBoxPlotMedianWrapper(): noboxplotmedian_(new NoBoxPlotMedian())

{

	
	
	
} 
NoBoxPlotMedianWrapper::NoBoxPlotMedianWrapper(NoBoxPlotMedian* noboxplotmedian): noboxplotmedian_(noboxplotmedian)
{
	
	
} 

NoBoxPlotMedianWrapper::~NoBoxPlotMedianWrapper()
{
	
}

void NoBoxPlotMedianWrapper::set(const MagRequest& request)
{
	
	

	
	
}

void NoBoxPlotMedianWrapper::print(ostream& out)  const
{
	out << "NoBoxPlotMedianWrapper[]";
}


    



