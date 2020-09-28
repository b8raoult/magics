
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file CurveAreaAttributes.h
    \\brief Definition of CurveArea Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "CurveAreaWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


CurveAreaWrapper::CurveAreaWrapper(): curvearea_(new CurveArea())

{

	
	
	CurveWrapper::object(curvearea_);
	
	
} 
CurveAreaWrapper::CurveAreaWrapper(CurveArea* curvearea): curvearea_(curvearea)
{
	
	
	CurveWrapper::object(curvearea_);
	
} 

CurveAreaWrapper::~CurveAreaWrapper()
{
	
}

void CurveAreaWrapper::set(const MagRequest& request)
{
	
	
	
	CurveWrapper::set(request);
	

	
	
		string shade_value = request.countValues("GRAPH_SHADE") ?  (string) request("GRAPH_SHADE") : "on";
	MagLog::debug() << " GRAPH_SHADE set to " << shade_value << endl;
	GraphShadeWrapper* shade_wrapper = 0;
#ifdef MAGICS_EXCEPTION
	try
#endif
	{
		shade_wrapper = SimpleFactory<GraphShadeWrapper>::create(shade_value);
	}
#ifdef MAGICS_EXCEPTION
	 catch (NoFactoryException) {
#else
	 if (!shade_wrapper) {
#endif
		MagLog::warning() << "[" << shade_value << "] is not a valid value for shade: reset to default -> [on]" << endl;
		shade_wrapper = SimpleFactory<GraphShadeWrapper>::create("on");
	}
	shade_wrapper->set(request);
	curvearea_->shade_ =  unique_ptr<GraphShade>(shade_wrapper->object());
	delete shade_wrapper;
	
}

void CurveAreaWrapper::print(ostream& out)  const
{
	out << "CurveAreaWrapper[]";
}


    



#include "GraphShadeWrapper.h"

static SimpleObjectMaker<GraphShadeWrapper> CurveArea_graph_shade_shading_Wrapper("shading");


#include "GraphShadeWrapper.h"

static SimpleObjectMaker<GraphShadeWrapper> CurveArea_graph_shade_on_Wrapper("on");


#include "NoGraphShadeWrapper.h"
static SimpleObjectMaker<NoGraphShade, GraphShade> CurveArea_graph_shade_noshading ("noshading");
static SimpleObjectMaker<NoGraphShadeWrapper, GraphShadeWrapper> CurveArea_graph_shade_noshading_wrapper ("noshading");


#include "NoGraphShadeWrapper.h"
static SimpleObjectMaker<NoGraphShade, GraphShade> CurveArea_graph_shade_off ("off");
static SimpleObjectMaker<NoGraphShadeWrapper, GraphShadeWrapper> CurveArea_graph_shade_off_wrapper ("off");



