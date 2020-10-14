
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file HiLoAttributes.h
    \\brief Definition of HiLo Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "HiLoAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

HiLoAttributes::HiLoAttributes():
	window_size_(ParameterManager::getInt("contour_hilo_window_size")),
	hilo_max_value_(ParameterManager::getDouble("contour_hilo_max_value")),
	hilo_min_value_(ParameterManager::getDouble("contour_hilo_min_value")),
	hi_max_value_(ParameterManager::getDouble("contour_hi_max_value")),
	hi_min_value_(ParameterManager::getDouble("contour_hi_min_value")),
	lo_max_value_(ParameterManager::getDouble("contour_lo_max_value")),
	lo_min_value_(ParameterManager::getDouble("contour_lo_min_value"))
	,
	type_(MagTranslator<string, HiLoTechnique>().magics("contour_hilo_type")),
	marker_(MagTranslator<string, HiLoMarkerBase>().magics("contour_hilo_marker"))
	 
{
} 


HiLoAttributes::~HiLoAttributes()
{
	
}

    
void HiLoAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "contour";
	prefix[i++] = "contour_hilo";
	
	setAttribute(prefix, "contour_hilo_window_size", window_size_, params);
	setAttribute(prefix, "contour_hilo_max_value", hilo_max_value_, params);
	setAttribute(prefix, "contour_hilo_min_value", hilo_min_value_, params);
	setAttribute(prefix, "contour_hi_max_value", hi_max_value_, params);
	setAttribute(prefix, "contour_hi_min_value", hi_min_value_, params);
	setAttribute(prefix, "contour_lo_max_value", lo_max_value_, params);
	setAttribute(prefix, "contour_lo_min_value", lo_min_value_, params);
	
	setMember(prefix, "contour_hilo_type", type_, params);
	setMember(prefix, "contour_hilo_marker", marker_, params);
	
}

void HiLoAttributes::copy(const HiLoAttributes& other)
{
	window_size_ = other.window_size_;
	hilo_max_value_ = other.hilo_max_value_;
	hilo_min_value_ = other.hilo_min_value_;
	hi_max_value_ = other.hi_max_value_;
	hi_min_value_ = other.hi_min_value_;
	lo_max_value_ = other.lo_max_value_;
	lo_min_value_ = other.lo_min_value_;
	type_ = unique_ptr<HiLoTechnique>(other.type_->clone());
	marker_ = unique_ptr<HiLoMarkerBase>(other.marker_->clone());
	
} 


bool HiLoAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "hilo")  )
		return true;
	if ( acceptNode(node, type_) )
		return true;
	if ( acceptNode(node, marker_) )
		return true;
	
	return false;
}

void HiLoAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "hilo")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), type_, node);
		setMember(node.name(), marker_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), type_, *elt); 
		setMember(elt->name(), marker_, *elt); 
		
	}
}

void HiLoAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " window_size = " <<  window_size_;
	out << " hilo_max_value = " <<  hilo_max_value_;
	out << " hilo_min_value = " <<  hilo_min_value_;
	out << " hi_max_value = " <<  hi_max_value_;
	out << " hi_min_value = " <<  hi_min_value_;
	out << " lo_max_value = " <<  lo_max_value_;
	out << " lo_min_value = " <<  lo_min_value_;
	out << " type = " <<  *type_;
	out << " marker = " <<  *marker_;
	
	out << "]" << "\n";
}

void HiLoAttributes::toxml(ostream& out)  const
{
	out <<  "\"hilo\""; 
	out << ", \"contour_hilo_window_size\":";
	niceprint(out,window_size_);
	out << ", \"contour_hilo_max_value\":";
	niceprint(out,hilo_max_value_);
	out << ", \"contour_hilo_min_value\":";
	niceprint(out,hilo_min_value_);
	out << ", \"contour_hi_max_value\":";
	niceprint(out,hi_max_value_);
	out << ", \"contour_hi_min_value\":";
	niceprint(out,hi_min_value_);
	out << ", \"contour_lo_max_value\":";
	niceprint(out,lo_max_value_);
	out << ", \"contour_lo_min_value\":";
	niceprint(out,lo_min_value_);
	out << ", \"contour_hilo_type\":";
	type_->toxml(out);
	out << ", \"contour_hilo_marker\":";
	marker_->toxml(out);
	
}

static MagicsParameter<int> contour_hilo_window_size("contour_hilo_window_size", 3, "");
static MagicsParameter<double> contour_hilo_max_value("contour_hilo_max_value", 1.0e+21, "");
static MagicsParameter<double> contour_hilo_min_value("contour_hilo_min_value", -1.0e+21, "");
static MagicsParameter<double> contour_hi_max_value("contour_hi_max_value", 1.0e+21, "");
static MagicsParameter<double> contour_hi_min_value("contour_hi_min_value", -1.0e+21, "");
static MagicsParameter<double> contour_lo_max_value("contour_lo_max_value", 1.0e+21, "");
static MagicsParameter<double> contour_lo_min_value("contour_lo_min_value", -1.0e+21, "");
static MagicsParameter<string> contour_hilo_type("contour_hilo_type", "text", ""); 
static MagicsParameter<string> contour_hilo_marker("contour_hilo_marker", "off", ""); 
#include "HiLoNumber.h"
#include "HiLoMarker.h"
#include "HiLoText.h"
#include "HiLoBoth.h"
static SimpleObjectMaker<HiLoText , HiLoTechnique> text_HiLoText("text");
static SimpleObjectMaker<HiLoNumber , HiLoTechnique> number_HiLoNumber("number");
static SimpleObjectMaker<HiLoBoth , HiLoTechnique> both_HiLoBoth("both");
static SimpleObjectMaker<HiLoMarker , HiLoMarkerBase> marker_HiLoMarker("marker");
static SimpleObjectMaker<HiLoMarker , HiLoMarkerBase> on_HiLoMarker("on");
static SimpleObjectMaker<NoHiLoMarker , HiLoMarkerBase> nomarker_NoHiLoMarker("nomarker");
static SimpleObjectMaker<NoHiLoMarker , HiLoMarkerBase> off_NoHiLoMarker("off");
