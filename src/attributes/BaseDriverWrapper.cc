
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file BaseDriverAttributes.h
    \\brief Definition of BaseDriver Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "BaseDriverWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


BaseDriverWrapper::BaseDriverWrapper(): basedriver_(0)

{


	

}
BaseDriverWrapper::BaseDriverWrapper(BaseDriver* basedriver): basedriver_(basedriver)
{

	
}

BaseDriverWrapper::~BaseDriverWrapper()
{

}

void BaseDriverWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("OUTPUT_TITLE") ) {
		string title_value = request("OUTPUT_TITLE");
		basedriver_->title_ = title_value;
		}
	if  (request.countValues("OUTPUT_FILE") ) {
		string file_value = request("OUTPUT_FILE");
		basedriver_->file_ = file_value;
		}
	if  (request.countValues("OUTPUT_NAME") ) {
		string name_value = request("OUTPUT_NAME");
		basedriver_->name_ = name_value;
		}
	if  (request.countValues("OUTPUT_NAME_FIRST_PAGE_NUMBER") ) {
		string firstnumber_value = request("OUTPUT_NAME_FIRST_PAGE_NUMBER");
		basedriver_->firstnumber_ = MagTranslator<string, bool>()(firstnumber_value);
		}
	if  (request.countValues("OUTPUT_NAME_FIRST_PAGE_NUMBER_VALUE") ) {
		int firstvalue_value = request("OUTPUT_NAME_FIRST_PAGE_NUMBER_VALUE");
		basedriver_->firstvalue_ = firstvalue_value;
		}
	if  (request.countValues("OUTPUT_FULLNAME") ) {
		string fullname_value = request("OUTPUT_FULLNAME");
		basedriver_->fullname_ = fullname_value;
		}
	if  (request.countValues("OUTPUT_LEGACY_NAME") ) {
		string legacyname_value = request("OUTPUT_LEGACY_NAME");
		basedriver_->legacyname_ = legacyname_value;
		}
	if  (request.countValues("OUTPUT_FILE_MINIMAL_WIDTH") ) {
		int numberingwidth_value = request("OUTPUT_FILE_MINIMAL_WIDTH");
		basedriver_->numberingwidth_ = numberingwidth_value;
		}
	if  (request.countValues("OUTPUT_FILE_SEPARATOR") ) {
		string separator_value = request("OUTPUT_FILE_SEPARATOR");
		basedriver_->separator_ = separator_value;
		}
	if  (request.countValues("OUTPUT_CREATOR") ) {
		string output_creator_value = request("OUTPUT_CREATOR");
		basedriver_->output_creator_ = output_creator_value;
		}
	if  (request.countValues("OUTPUT_MGB_TEMPLATE") ) {
		string mgb_template_value = request("OUTPUT_MGB_TEMPLATE");
		basedriver_->mgb_template_ = mgb_template_value;
		}
	if  (request.countValues("OUTPUT_DEBUG") ) {
		string debug_value = request("OUTPUT_DEBUG");
		basedriver_->debug_ = MagTranslator<string, bool>()(debug_value);
		}
	if  (request.countValues("OUTPUT_WIDTH") ) {
		int width_value = request("OUTPUT_WIDTH");
		basedriver_->width_ = width_value;
		}
	if  (request.countValues("OUTPUT_FILELIST") ) {
		string filelist_value = request("OUTPUT_FILELIST");
		basedriver_->filelist_ = MagTranslator<string, bool>()(filelist_value);
		}
	if  (request.countValues("OUTPUT_FILELIST_NAME") ) {
		string filelist_name_value = request("OUTPUT_FILELIST_NAME");
		basedriver_->filelist_name_ = filelist_name_value;
		}
	if  (request.countValues("OUTPUT_FILELIST_RESET") ) {
		string filelist_reset_value = request("OUTPUT_FILELIST_RESET");
		basedriver_->filelist_reset_ = MagTranslator<string, bool>()(filelist_reset_value);
		}
	intarray frame_list_value;
	for (int i = 0; i < request.countValues("OUTPUT_FRAME_LIST"); i++)
		frame_list_value.push_back((int)request("OUTPUT_FRAME_LIST", i));
	if ( !frame_list_value.empty() )
		basedriver_->frame_list_ = frame_list_value;
	
	
}

void BaseDriverWrapper::print(ostream& out)  const
{
	out << "BaseDriverWrapper[]";
}


