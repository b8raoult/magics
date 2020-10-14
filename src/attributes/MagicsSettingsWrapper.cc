
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file MagicsSettingsAttributes.h
    \\brief Definition of MagicsSettings Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "MagicsSettingsWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


MagicsSettingsWrapper::MagicsSettingsWrapper(): magicssettings_(new MagicsSettings())

{


	

}
MagicsSettingsWrapper::MagicsSettingsWrapper(MagicsSettings* magicssettings): magicssettings_(magicssettings)
{

	
}

MagicsSettingsWrapper::~MagicsSettingsWrapper()
{

}

void MagicsSettingsWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("MAGICS_SILENT") ) {
		string silent_value = request("MAGICS_SILENT");
		magicssettings_->silent_ = MagTranslator<string, bool>()(silent_value);
		}
	if  (request.countValues("MAGICS_BACKWARD_COMPATIBILITY") ) {
		string compatibility_value = request("MAGICS_BACKWARD_COMPATIBILITY");
		magicssettings_->compatibility_ = MagTranslator<string, bool>()(compatibility_value);
		}
	if  (request.countValues("MAGICS_STRICT_MODE") ) {
		string strict_value = request("MAGICS_STRICT_MODE");
		magicssettings_->strict_ = MagTranslator<string, bool>()(strict_value);
		}
	
	
}

void MagicsSettingsWrapper::print(ostream& out)  const
{
	out << "MagicsSettingsWrapper[]";
}


∏