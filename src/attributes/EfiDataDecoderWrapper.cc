
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EfiDataDecoderAttributes.h
    \\brief Definition of EfiDataDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "EfiDataDecoderWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


EfiDataDecoderWrapper::EfiDataDecoderWrapper(): efidatadecoder_(new EfiDataDecoder())

{

	
	
	
} 
EfiDataDecoderWrapper::EfiDataDecoderWrapper(EfiDataDecoder* efidatadecoder): efidatadecoder_(efidatadecoder)
{
	
	
} 

EfiDataDecoderWrapper::~EfiDataDecoderWrapper()
{
	
}

void EfiDataDecoderWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("EFI_FILENAME") ) {
		string path_value = request("EFI_FILENAME");
		efidatadecoder_->path_ = path_value;
		}
	if  (request.countValues("EFI_RECORD") ) {
		int record_value = request("EFI_RECORD");
		efidatadecoder_->record_ = record_value;
		}
	
	
}

void EfiDataDecoderWrapper::print(ostream& out)  const
{
	out << "EfiDataDecoderWrapper[]";
}


    



