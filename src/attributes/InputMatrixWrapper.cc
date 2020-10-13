
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file InputMatrixAttributes.h
    \\brief Definition of InputMatrix Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "MagRequest.h" 
#include "InputMatrixWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


InputMatrixWrapper::InputMatrixWrapper(): inputmatrix_(new InputMatrix())

{

	
	
	
} 
InputMatrixWrapper::InputMatrixWrapper(InputMatrix* inputmatrix): inputmatrix_(inputmatrix)
{
	
	
} 

InputMatrixWrapper::~InputMatrixWrapper()
{
	
}

void InputMatrixWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("INPUT_SIMPLE_FIELD") ) {
		string simple_field_value = request("INPUT_SIMPLE_FIELD");
		inputmatrix_->simple_field_ = MagTranslator<string, bool>()(simple_field_value);
		}
	if  (request.countValues("INPUT_METADATA") ) {
		string metadata_value = request("INPUT_METADATA");
		inputmatrix_->metadata_ = metadata_value;
		}
	if  (request.countValues("INPUT_FIELD_SUBPAGE_MAPPING") ) {
		string mapping_value = request("INPUT_FIELD_SUBPAGE_MAPPING");
		inputmatrix_->mapping_ = mapping_value;
		}
	if  (request.countValues("INPUT_FIELD_SUPPRESS_BELOW") ) {
		double suppress_below_value = request("INPUT_FIELD_SUPPRESS_BELOW");
		inputmatrix_->suppress_below_ = suppress_below_value;
		}
	if  (request.countValues("INPUT_FIELD_SUPPRESS_ABOVE") ) {
		double suppress_above_value = request("INPUT_FIELD_SUPPRESS_ABOVE");
		inputmatrix_->suppress_above_ = suppress_above_value;
		}
	
	
	if  (request.countValues("INPUT_FIELD") ) {
		string field_value = request("INPUT_FIELD");
		inputmatrix_->field_ = MagTranslator<string, Matrix>()(field_value);
	}
		
	
	if  (request.countValues("INPUT_WIND_U_COMPONENT") ) {
		string u_component_value = request("INPUT_WIND_U_COMPONENT");
		inputmatrix_->u_component_ = MagTranslator<string, Matrix>()(u_component_value);
	}
		
	
	if  (request.countValues("INPUT_WIND_V_COMPONENT") ) {
		string v_component_value = request("INPUT_WIND_V_COMPONENT");
		inputmatrix_->v_component_ = MagTranslator<string, Matrix>()(v_component_value);
	}
		
	
		string organization_value = request.countValues("INPUT_FIELD_ORGANIZATION") ?  (string) request("INPUT_FIELD_ORGANIZATION") : "regular";
	MagLog::debug() << " INPUT_FIELD_ORGANIZATION set to " << organization_value << endl;
	InputMatrixInterpretorWrapper* organization_wrapper = 0;
#ifdef MAGICS_EXCEPTION
	try
#endif
	{
		organization_wrapper = SimpleFactory<InputMatrixInterpretorWrapper>::create(organization_value);
	}
#ifdef MAGICS_EXCEPTION
	 catch (NoFactoryException) {
#else
	 if (!organization_wrapper) {
#endif
		MagLog::warning() << "[" << organization_value << "] is not a valid value for organization: reset to default -> [regular]" << endl;
		organization_wrapper = SimpleFactory<InputMatrixInterpretorWrapper>::create("regular");
	}
	organization_wrapper->set(request);
	inputmatrix_->organization_ =  unique_ptr<InputMatrixInterpretor>(organization_wrapper->object());
	delete organization_wrapper;
	
	if  (request.countValues("INPUT_WIND_SPEED") ) {
		string wind_speed_value = request("INPUT_WIND_SPEED");
		inputmatrix_->wind_speed_ = MagTranslator<string, Matrix>()(wind_speed_value);
	}
		
	
	if  (request.countValues("INPUT_WIND_DIRECTION") ) {
		string wind_direction_value = request("INPUT_WIND_DIRECTION");
		inputmatrix_->wind_direction_ = MagTranslator<string, Matrix>()(wind_direction_value);
	}
		
	
}

void InputMatrixWrapper::print(ostream& out)  const
{
	out << "InputMatrixWrapper[]";
}


    






#include "InputMatrixRegularInterpretorWrapper.h"
static SimpleObjectMaker<InputMatrixRegularInterpretor, InputMatrixInterpretor> InputMatrix_input_field_organization_gaussian ("gaussian");
static SimpleObjectMaker<InputMatrixRegularInterpretorWrapper, InputMatrixInterpretorWrapper> InputMatrix_input_field_organization_gaussian_wrapper ("gaussian");


#include "InputMatrixRegularInterpretorWrapper.h"
static SimpleObjectMaker<InputMatrixRegularInterpretor, InputMatrixInterpretor> InputMatrix_input_field_organization_regular ("regular");
static SimpleObjectMaker<InputMatrixRegularInterpretorWrapper, InputMatrixInterpretorWrapper> InputMatrix_input_field_organization_regular_wrapper ("regular");


#include "InputMatrixIrregularInterpretorWrapper.h"
static SimpleObjectMaker<InputMatrixIrregularInterpretor, InputMatrixInterpretor> InputMatrix_input_field_organization_irregular ("irregular");
static SimpleObjectMaker<InputMatrixIrregularInterpretorWrapper, InputMatrixInterpretorWrapper> InputMatrix_input_field_organization_irregular_wrapper ("irregular");


#include "InputMatrixIrregularInterpretorWrapper.h"
static SimpleObjectMaker<InputMatrixIrregularInterpretor, InputMatrixInterpretor> InputMatrix_input_field_organization_nonregular ("nonregular");
static SimpleObjectMaker<InputMatrixIrregularInterpretorWrapper, InputMatrixInterpretorWrapper> InputMatrix_input_field_organization_nonregular_wrapper ("nonregular");





