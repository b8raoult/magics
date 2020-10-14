
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file OutputHandlerAttributes.h
    \\brief Definition of OutputHandler Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "OutputHandlerWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


OutputHandlerWrapper::OutputHandlerWrapper(): outputhandler_(new OutputHandler())

{


	

}
OutputHandlerWrapper::OutputHandlerWrapper(OutputHandler* outputhandler): outputhandler_(outputhandler)
{

	
}

OutputHandlerWrapper::~OutputHandlerWrapper()
{

}

void OutputHandlerWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("OUTPUT_FORMAT") ) {
		string format_value = request("OUTPUT_FORMAT");
		outputhandler_->format_ = format_value;
		}
	stringarray  formats_value;
	for (int i = 0; i < request.countValues("OUTPUT_FORMATS"); i++)
		formats_value.push_back((string)request("OUTPUT_FORMATS", i));
	if ( !formats_value.empty() )
		outputhandler_->formats_ = formats_value;
	
	
}

void OutputHandlerWrapper::print(ostream& out)  const
{
	out << "OutputHandlerWrapper[]";
}


∏