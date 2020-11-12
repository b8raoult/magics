
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ValuePlotBaseAttributes.h
    \\brief Definition of ValuePlotBase Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "ValuePlotBaseWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


ValuePlotBaseWrapper::ValuePlotBaseWrapper(): valueplotbase_(new ValuePlotBase())

{


	

}
ValuePlotBaseWrapper::ValuePlotBaseWrapper(ValuePlotBase* valueplotbase): valueplotbase_(valueplotbase)
{

	
}

ValuePlotBaseWrapper::~ValuePlotBaseWrapper()
{

}

void ValuePlotBaseWrapper::set(const MagRequest& request)
{

	

	
	
}

void ValuePlotBaseWrapper::print(ostream& out)  const
{
	out << "ValuePlotBaseWrapper[]";
}


