
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SimplePolylineAttributes.h
    \\brief Definition of SimplePolyline Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "SimplePolylineWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


SimplePolylineWrapper::SimplePolylineWrapper(): simplepolyline_(new SimplePolyline())

{

	
	
	SimplePolylineInputWrapper::object(simplepolyline_);
	
	
} 
SimplePolylineWrapper::SimplePolylineWrapper(SimplePolyline* simplepolyline): simplepolyline_(simplepolyline)
{
	
	
	SimplePolylineInputWrapper::object(simplepolyline_);
	
} 

SimplePolylineWrapper::~SimplePolylineWrapper()
{
	
}

void SimplePolylineWrapper::set(const MagRequest& request)
{
	
	
	
	SimplePolylineInputWrapper::set(request);
	

	if  (request.countValues("LEGEND") ) {
		string legend_value = request("LEGEND");
		simplepolyline_->legend_ = MagTranslator<string, bool>()(legend_value);
		}
	if  (request.countValues("POLYLINE_LINE_THICKNESS") ) {
		int thickness_value = request("POLYLINE_LINE_THICKNESS");
		simplepolyline_->thickness_ = thickness_value;
		}
	if  (request.countValues("POLYLINE_EFFECT_METHOD") ) {
		string method_value = request("POLYLINE_EFFECT_METHOD");
		simplepolyline_->method_ = method_value;
		}
	if  (request.countValues("POLYLINE_TRAJECTORY_PIVOT_INDEX") ) {
		int pivot_value = request("POLYLINE_TRAJECTORY_PIVOT_INDEX");
		simplepolyline_->pivot_ = pivot_value;
		}
	if  (request.countValues("POLYLINE_TRAJECTORY_FACTOR") ) {
		int factor_value = request("POLYLINE_TRAJECTORY_FACTOR");
		simplepolyline_->factor_ = factor_value;
		}
	if  (request.countValues("POLYLINE_LEVEL_COUNT") ) {
		int count_value = request("POLYLINE_LEVEL_COUNT");
		simplepolyline_->count_ = count_value;
		}
	if  (request.countValues("POLYLINE_LEVEL_TOLERANCE") ) {
		int tolerance_value = request("POLYLINE_LEVEL_TOLERANCE");
		simplepolyline_->tolerance_ = tolerance_value;
		}
	if  (request.countValues("POLYLINE_REFERENCE_LEVEL") ) {
		double reference_value = request("POLYLINE_REFERENCE_LEVEL");
		simplepolyline_->reference_ = reference_value;
		}
	if  (request.countValues("POLYLINE_INTERVAL") ) {
		double interval_value = request("POLYLINE_INTERVAL");
		simplepolyline_->interval_ = interval_value;
		}
	doublearray  list_value;
	for (int i = 0; i < request.countValues("POLYLINE_LEVEL_LIST"); i++)
		list_value.push_back((double)request("POLYLINE_LEVEL_LIST", i));
	if ( !list_value.empty() ) 
		simplepolyline_->list_ = list_value;
	if  (request.countValues("POLYLINE_SHADE") ) {
		string shade_value = request("POLYLINE_SHADE");
		simplepolyline_->shade_ = MagTranslator<string, bool>()(shade_value);
		}
	if  (request.countValues("POLYLINE_SHADE_MAX_LEVEL") ) {
		double max_value = request("POLYLINE_SHADE_MAX_LEVEL");
		simplepolyline_->max_ = max_value;
		}
	if  (request.countValues("POLYLINE_SHADE_MIN_LEVEL") ) {
		double min_value = request("POLYLINE_SHADE_MIN_LEVEL");
		simplepolyline_->min_ = min_value;
		}
	if  (request.countValues("POLYLINE_SHADE_COLOUR_DIRECTION") ) {
		string direction_value = request("POLYLINE_SHADE_COLOUR_DIRECTION");
		simplepolyline_->direction_ = direction_value;
		}
	stringarray  colours_value;
	for (int i = 0; i < request.countValues("POLYLINE_SHADE_COLOUR_LIST"); i++)
		colours_value.push_back((string)request("POLYLINE_SHADE_COLOUR_LIST", i));
	if ( !colours_value.empty() ) 
		simplepolyline_->colours_ = colours_value;
	if  (request.countValues("POLYLINE_PRIORITY_VARIABLE_NAME") ) {
		string priority_key_value = request("POLYLINE_PRIORITY_VARIABLE_NAME");
		simplepolyline_->priority_key_ = priority_key_value;
		}
	if  (request.countValues("POLYLINE_COLOUR_VARIABLE_NAME") ) {
		string colour_key_value = request("POLYLINE_COLOUR_VARIABLE_NAME");
		simplepolyline_->colour_key_ = colour_key_value;
		}
	stringarray  colour_list_value;
	for (int i = 0; i < request.countValues("POLYLINE_COLOUR_LIST"); i++)
		colour_list_value.push_back((string)request("POLYLINE_COLOUR_LIST", i));
	if ( !colour_list_value.empty() ) 
		simplepolyline_->colour_list_ = colour_list_value;
	doublearray  colour_level_list_value;
	for (int i = 0; i < request.countValues("POLYLINE_COLOUR_LEVEL_LIST"); i++)
		colour_level_list_value.push_back((double)request("POLYLINE_COLOUR_LEVEL_LIST", i));
	if ( !colour_level_list_value.empty() ) 
		simplepolyline_->colour_level_list_ = colour_level_list_value;
	if  (request.countValues("POLYLINE_LINE_STYLE_VARIABLE_NAME") ) {
		string style_key_value = request("POLYLINE_LINE_STYLE_VARIABLE_NAME");
		simplepolyline_->style_key_ = style_key_value;
		}
	stringarray  style_list_value;
	for (int i = 0; i < request.countValues("POLYLINE_LINE_STYLE_LIST"); i++)
		style_list_value.push_back((string)request("POLYLINE_LINE_STYLE_LIST", i));
	if ( !style_list_value.empty() ) 
		simplepolyline_->style_list_ = style_list_value;
	doublearray  style_level_list_value;
	for (int i = 0; i < request.countValues("POLYLINE_LINE_STYLE_LEVEL_LIST"); i++)
		style_level_list_value.push_back((double)request("POLYLINE_LINE_STYLE_LEVEL_LIST", i));
	if ( !style_level_list_value.empty() ) 
		simplepolyline_->style_level_list_ = style_level_list_value;
	if  (request.countValues("POLYLINE_THICKNESS_VARIABLE_NAME") ) {
		string thickness_key_value = request("POLYLINE_THICKNESS_VARIABLE_NAME");
		simplepolyline_->thickness_key_ = thickness_key_value;
		}
	doublearray  thickness_list_value;
	for (int i = 0; i < request.countValues("POLYLINE_THICKNESS_LIST"); i++)
		thickness_list_value.push_back((double)request("POLYLINE_THICKNESS_LIST", i));
	if ( !thickness_list_value.empty() ) 
		simplepolyline_->thickness_list_ = thickness_list_value;
	doublearray  thickness_level_list_value;
	for (int i = 0; i < request.countValues("POLYLINE_THICKNESS_LEVEL_LIST"); i++)
		thickness_level_list_value.push_back((double)request("POLYLINE_THICKNESS_LEVEL_LIST", i));
	if ( !thickness_level_list_value.empty() ) 
		simplepolyline_->thickness_level_list_ = thickness_level_list_value;
	if  (request.countValues("POLYLINE_TRANSPARENCY_VARIABLE_NAME") ) {
		string transparency_key_value = request("POLYLINE_TRANSPARENCY_VARIABLE_NAME");
		simplepolyline_->transparency_key_ = transparency_key_value;
		}
	if  (request.countValues("POLYLINE_TRANSPARENCY_PIVOT_VARIABLE_NAME") ) {
		string pivot_key_value = request("POLYLINE_TRANSPARENCY_PIVOT_VARIABLE_NAME");
		simplepolyline_->pivot_key_ = pivot_key_value;
		}
	if  (request.countValues("POLYLINE_PIVOT_MARKER") ) {
		string pivot_marker_value = request("POLYLINE_PIVOT_MARKER");
		simplepolyline_->pivot_marker_ = pivot_marker_value;
		}
	if  (request.countValues("POLYLINE_PIVOT_MARKER_NAME") ) {
		string pivot_marker_name_value = request("POLYLINE_PIVOT_MARKER_NAME");
		simplepolyline_->pivot_marker_name_ = pivot_marker_name_value;
		}
	if  (request.countValues("POLYLINE_PIVOT_MARKER_HEIGHT") ) {
		double pivot_marker_height_value = request("POLYLINE_PIVOT_MARKER_HEIGHT");
		simplepolyline_->pivot_marker_height_ = pivot_marker_height_value;
		}
	doublearray  transparency_level_list_value;
	for (int i = 0; i < request.countValues("POLYLINE_TRANSPARENCY_LEVEL_LIST"); i++)
		transparency_level_list_value.push_back((double)request("POLYLINE_TRANSPARENCY_LEVEL_LIST", i));
	if ( !transparency_level_list_value.empty() ) 
		simplepolyline_->transparency_level_list_ = transparency_level_list_value;
	if  (request.countValues("POLYLINE_LEGEND_ONLY") ) {
		string legend_only_value = request("POLYLINE_LEGEND_ONLY");
		simplepolyline_->legend_only_ = MagTranslator<string, bool>()(legend_only_value);
		}
	
	if  (request.countValues("POLYLINE_LINE_COLOUR") ) {
		string colour_value = request("POLYLINE_LINE_COLOUR");
		simplepolyline_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
	if  (request.countValues("POLYLINE_LINE_STYLE") ) {
		string style_value = request("POLYLINE_LINE_STYLE");
		simplepolyline_->style_ = MagTranslator<string, LineStyle>()(style_value);
	}
		
	
		string levelSelection_value = request.countValues("POLYLINE_SHADE_LEVEL_SELECTION_TYPE") ?  (string) request("POLYLINE_SHADE_LEVEL_SELECTION_TYPE") : "count";
	MagLog::debug() << " POLYLINE_SHADE_LEVEL_SELECTION_TYPE set to " << levelSelection_value << endl;
	LevelSelectionWrapper* levelSelection_wrapper = 0;
	try
	{
		levelSelection_wrapper = SimpleFactory<LevelSelectionWrapper>::create(levelSelection_value);
	}
	 catch (NoFactoryException) {
		MagLog::warning() << "[" << levelSelection_value << "] is not a valid value for levelSelection: reset to default -> [count]" << endl;
		levelSelection_wrapper = SimpleFactory<LevelSelectionWrapper>::create("count");
	}
	levelSelection_wrapper->set(request);
	simplepolyline_->levelSelection_ =  unique_ptr<LevelSelection>(levelSelection_wrapper->object());
	delete levelSelection_wrapper;
	
		string colourMethod_value = request.countValues("POLYLINE_SHADE_COLOUR_METHOD") ?  (string) request("POLYLINE_SHADE_COLOUR_METHOD") : "calculate";
	MagLog::debug() << " POLYLINE_SHADE_COLOUR_METHOD set to " << colourMethod_value << endl;
	ColourTechniqueWrapper* colourMethod_wrapper = 0;
	try
	{
		colourMethod_wrapper = SimpleFactory<ColourTechniqueWrapper>::create(colourMethod_value);
	}
	 catch (NoFactoryException) {
		MagLog::warning() << "[" << colourMethod_value << "] is not a valid value for colourMethod: reset to default -> [calculate]" << endl;
		colourMethod_wrapper = SimpleFactory<ColourTechniqueWrapper>::create("calculate");
	}
	colourMethod_wrapper->set(request);
	simplepolyline_->colourMethod_ =  unique_ptr<ColourTechnique>(colourMethod_wrapper->object());
	delete colourMethod_wrapper;
	if  (request.countValues("POLYLINE_SHADE_MAX_LEVEL_COLOUR") ) {
		string maxColour_value = request("POLYLINE_SHADE_MAX_LEVEL_COLOUR");
		simplepolyline_->maxColour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(maxColour_value));
	}
		
	if  (request.countValues("POLYLINE_SHADE_MIN_LEVEL_COLOUR") ) {
		string minColour_value = request("POLYLINE_SHADE_MIN_LEVEL_COLOUR");
		simplepolyline_->minColour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(minColour_value));
	}
		
	
	if  (request.countValues("POLYLINE_COLOUR_LIST_POLICY") ) {
		string colour_policy_value = request("POLYLINE_COLOUR_LIST_POLICY");
		simplepolyline_->colour_policy_ = MagTranslator<string, ListPolicy>()(colour_policy_value);
	}
		
	
	if  (request.countValues("POLYLINE_LINE_STYLE_LIST_POLICY") ) {
		string style_policy_value = request("POLYLINE_LINE_STYLE_LIST_POLICY");
		simplepolyline_->style_policy_ = MagTranslator<string, ListPolicy>()(style_policy_value);
	}
		
	
	if  (request.countValues("POLYLINE_THICKNESS_LIST_POLICY") ) {
		string thickness_policy_value = request("POLYLINE_THICKNESS_LIST_POLICY");
		simplepolyline_->thickness_policy_ = MagTranslator<string, ListPolicy>()(thickness_policy_value);
	}
		
	if  (request.countValues("POLYLINE_PIVOT_MARKER_COLOUR") ) {
		string pivot_marker_colour_value = request("POLYLINE_PIVOT_MARKER_COLOUR");
		simplepolyline_->pivot_marker_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(pivot_marker_colour_value));
	}
		
	
}

void SimplePolylineWrapper::print(ostream& out)  const
{
	out << "SimplePolylineWrapper[]";
}


    





#include "CountSelectionTypeWrapper.h"
static SimpleObjectMaker<CountSelectionType, LevelSelection> SimplePolyline_polyline_shade_level_selection_type_count ("count");
static SimpleObjectMaker<CountSelectionTypeWrapper, LevelSelectionWrapper> SimplePolyline_polyline_shade_level_selection_type_count_wrapper ("count");


#include "IntervalSelectionTypeWrapper.h"
static SimpleObjectMaker<IntervalSelectionType, LevelSelection> SimplePolyline_polyline_shade_level_selection_type_interval ("interval");
static SimpleObjectMaker<IntervalSelectionTypeWrapper, LevelSelectionWrapper> SimplePolyline_polyline_shade_level_selection_type_interval_wrapper ("interval");


#include "LevelListSelectionTypeWrapper.h"
static SimpleObjectMaker<LevelListSelectionType, LevelSelection> SimplePolyline_polyline_shade_level_selection_type_list ("list");
static SimpleObjectMaker<LevelListSelectionTypeWrapper, LevelSelectionWrapper> SimplePolyline_polyline_shade_level_selection_type_list_wrapper ("list");



#include "CalculateColourTechniqueWrapper.h"
static SimpleObjectMaker<CalculateColourTechnique, ColourTechnique> SimplePolyline_polyline_shade_colour_method_calculate ("calculate");
static SimpleObjectMaker<CalculateColourTechniqueWrapper, ColourTechniqueWrapper> SimplePolyline_polyline_shade_colour_method_calculate_wrapper ("calculate");


#include "ListColourTechniqueWrapper.h"
static SimpleObjectMaker<ListColourTechnique, ColourTechnique> SimplePolyline_polyline_shade_colour_method_list ("list");
static SimpleObjectMaker<ListColourTechniqueWrapper, ColourTechniqueWrapper> SimplePolyline_polyline_shade_colour_method_list_wrapper ("list");









