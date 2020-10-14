
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LogoPlottingAttributes.h
    \\brief Definition of LogoPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "LogoPlottingWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


LogoPlottingWrapper::LogoPlottingWrapper(): logoplotting_(new LogoPlotting())

{


	
	NoLogoPlottingWrapper::object(logoplotting_);
	

}
LogoPlottingWrapper::LogoPlottingWrapper(LogoPlotting* logoplotting): logoplotting_(logoplotting)
{

	
	NoLogoPlottingWrapper::object(logoplotting_);
	
}

LogoPlottingWrapper::~LogoPlottingWrapper()
{

}

void LogoPlottingWrapper::set(const MagRequest& request)
{

	

	NoLogoPlottingWrapper::set(request);
	

	if  (request.countValues("PAGE_ID_LINE_LOGO_NAME") ) {
		string name_value = request("PAGE_ID_LINE_LOGO_NAME");
		logoplotting_->name_ = name_value;
		}
	
	
}

void LogoPlottingWrapper::print(ostream& out)  const
{
	out << "LogoPlottingWrapper[]";
}


∏