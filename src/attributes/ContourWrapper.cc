
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ContourAttributes.h
    \\brief Definition of Contour Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "ContourWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


ContourWrapper::ContourWrapper(): contour_(new Contour())

{


	

}
ContourWrapper::ContourWrapper(Contour* contour): contour_(contour)
{

	
}

ContourWrapper::~ContourWrapper()
{

}

void ContourWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("LEGEND") ) {
		string legend_value = request("LEGEND");
		contour_->legend_ = MagTranslator<string, bool>()(legend_value);
		}
	if  (request.countValues("CONTOUR_DESCRIPTION") ) {
		string description_value = request("CONTOUR_DESCRIPTION");
		contour_->description_ = description_value;
		}
	if  (request.countValues("CONTOUR_TITLE") ) {
		string title_value = request("CONTOUR_TITLE");
		contour_->title_ = title_value;
		}
	if  (request.countValues("CONTOUR_INTERPOLATION_FLOOR") ) {
		double floor_value = request("CONTOUR_INTERPOLATION_FLOOR");
		contour_->floor_ = floor_value;
		}
	if  (request.countValues("CONTOUR_INTERPOLATION_CEILING") ) {
		double ceiling_value = request("CONTOUR_INTERPOLATION_CEILING");
		contour_->ceiling_ = ceiling_value;
		}
	if  (request.countValues("CONTOUR_AUTOMATIC_SETTING") ) {
		string setting_value = request("CONTOUR_AUTOMATIC_SETTING");
		contour_->setting_ = setting_value;
		}
	if  (request.countValues("CONTOUR_STYLE_NAME") ) {
		string predefined_value = request("CONTOUR_STYLE_NAME");
		contour_->predefined_ = predefined_value;
		}
	if  (request.countValues("CONTOUR_METADATA_ONLY") ) {
		string metadata_only_value = request("CONTOUR_METADATA_ONLY");
		contour_->metadata_only_ = MagTranslator<string, bool>()(metadata_only_value);
		}
	if  (request.countValues("CONTOUR_AUTOMATIC_LIBRARY_PATH") ) {
		string library_path_value = request("CONTOUR_AUTOMATIC_LIBRARY_PATH");
		contour_->library_path_ = library_path_value;
		}
	if  (request.countValues("CONTOUR_UNITS") ) {
		string units_value = request("CONTOUR_UNITS");
		contour_->units_ = units_value;
		}
	
	
		string contour_value = request.countValues("CONTOUR") ?  (string) request("CONTOUR") : "on";
	MagLog::debug() << " CONTOUR set to " << contour_value << endl;
	IsoPlotWrapper* contour_wrapper = 0;
	try
	{
		contour_wrapper = SimpleFactory<IsoPlotWrapper>::create(contour_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsSettings::strict()) {
            throw;
        }
		MagLog::warning() << "[" << contour_value << "] is not a valid value for contour: reset to default -> [on]" << endl;
		contour_wrapper = SimpleFactory<IsoPlotWrapper>::create("on");
	}
	contour_wrapper->set(request);
	contour_->contour_ =  unique_ptr<IsoPlot>(contour_wrapper->object());
	delete contour_wrapper;
	
		string method_value = request.countValues("CONTOUR_METHOD") ?  (string) request("CONTOUR_METHOD") : "automatic";
	MagLog::debug() << " CONTOUR_METHOD set to " << method_value << endl;
	ContourMethodWrapper* method_wrapper = 0;
	try
	{
		method_wrapper = SimpleFactory<ContourMethodWrapper>::create(method_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsSettings::strict()) {
            throw;
        }
		MagLog::warning() << "[" << method_value << "] is not a valid value for method: reset to default -> [automatic]" << endl;
		method_wrapper = SimpleFactory<ContourMethodWrapper>::create("automatic");
	}
	method_wrapper->set(request);
	contour_->method_ =  unique_ptr<ContourMethod>(method_wrapper->object());
	delete method_wrapper;
	
		string hilo_value = request.countValues("CONTOUR_HILO") ?  (string) request("CONTOUR_HILO") : "off";
	MagLog::debug() << " CONTOUR_HILO set to " << hilo_value << endl;
	HiLoBaseWrapper* hilo_wrapper = 0;
	try
	{
		hilo_wrapper = SimpleFactory<HiLoBaseWrapper>::create(hilo_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsSettings::strict()) {
            throw;
        }
		MagLog::warning() << "[" << hilo_value << "] is not a valid value for hilo: reset to default -> [off]" << endl;
		hilo_wrapper = SimpleFactory<HiLoBaseWrapper>::create("off");
	}
	hilo_wrapper->set(request);
	contour_->hilo_ =  unique_ptr<HiLoBase>(hilo_wrapper->object());
	delete hilo_wrapper;
	
		string grid_value = request.countValues("CONTOUR_GRID_VALUE_PLOT") ?  (string) request("CONTOUR_GRID_VALUE_PLOT") : "off";
	MagLog::debug() << " CONTOUR_GRID_VALUE_PLOT set to " << grid_value << endl;
	ValuePlotBaseWrapper* grid_wrapper = 0;
	try
	{
		grid_wrapper = SimpleFactory<ValuePlotBaseWrapper>::create(grid_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsSettings::strict()) {
            throw;
        }
		MagLog::warning() << "[" << grid_value << "] is not a valid value for grid: reset to default -> [off]" << endl;
		grid_wrapper = SimpleFactory<ValuePlotBaseWrapper>::create("off");
	}
	grid_wrapper->set(request);
	contour_->grid_ =  unique_ptr<ValuePlotBase>(grid_wrapper->object());
	delete grid_wrapper;
	
}

void ContourWrapper::print(ostream& out)  const
{
	out << "ContourWrapper[]";
}


#include "IsoPlotWrapper.h"

static SimpleObjectMaker<IsoPlotWrapper> Contour_contour_isoline_Wrapper("isoline");


#include "IsoPlotWrapper.h"

static SimpleObjectMaker<IsoPlotWrapper> Contour_contour_on_Wrapper("on");


#include "NoIsoPlotWrapper.h"
static SimpleObjectMaker<NoIsoPlot, IsoPlot> Contour_contour_noisoline ("noisoline");
static SimpleObjectMaker<NoIsoPlotWrapper, IsoPlotWrapper> Contour_contour_noisoline_wrapper ("noisoline");


#include "NoIsoPlotWrapper.h"
static SimpleObjectMaker<NoIsoPlot, IsoPlot> Contour_contour_off ("off");
static SimpleObjectMaker<NoIsoPlotWrapper, IsoPlotWrapper> Contour_contour_off_wrapper ("off");



#include "AutomaticContourMethodWrapper.h"
static SimpleObjectMaker<AutomaticContourMethod, ContourMethod> Contour_contour_method_automatic ("automatic");
static SimpleObjectMaker<AutomaticContourMethodWrapper, ContourMethodWrapper> Contour_contour_method_automatic_wrapper ("automatic");


#include "ContourMethodWrapper.h"

static SimpleObjectMaker<ContourMethodWrapper> Contour_contour_method_linear_Wrapper("linear");


#include "Akima760MethodWrapper.h"
static SimpleObjectMaker<Akima760Method, ContourMethod> Contour_contour_method_akima760 ("akima760");
static SimpleObjectMaker<Akima760MethodWrapper, ContourMethodWrapper> Contour_contour_method_akima760_wrapper ("akima760");


#include "Akima474MethodWrapper.h"
static SimpleObjectMaker<Akima474Method, ContourMethod> Contour_contour_method_akima474 ("akima474");
static SimpleObjectMaker<Akima474MethodWrapper, ContourMethodWrapper> Contour_contour_method_akima474_wrapper ("akima474");



#include "HiLoWrapper.h"
static SimpleObjectMaker<HiLo, HiLoBase> Contour_contour_hilo_hilo ("hilo");
static SimpleObjectMaker<HiLoWrapper, HiLoBaseWrapper> Contour_contour_hilo_hilo_wrapper ("hilo");


#include "HiLoWrapper.h"
static SimpleObjectMaker<HiLo, HiLoBase> Contour_contour_hilo_on ("on");
static SimpleObjectMaker<HiLoWrapper, HiLoBaseWrapper> Contour_contour_hilo_on_wrapper ("on");


#include "NoHiLoWrapper.h"
static SimpleObjectMaker<NoHiLo, HiLoBase> Contour_contour_hilo_nohilo ("nohilo");
static SimpleObjectMaker<NoHiLoWrapper, HiLoBaseWrapper> Contour_contour_hilo_nohilo_wrapper ("nohilo");


#include "NoHiLoWrapper.h"
static SimpleObjectMaker<NoHiLo, HiLoBase> Contour_contour_hilo_off ("off");
static SimpleObjectMaker<NoHiLoWrapper, HiLoBaseWrapper> Contour_contour_hilo_off_wrapper ("off");


#include "HighHiLoWrapper.h"
static SimpleObjectMaker<HighHiLo, HiLoBase> Contour_contour_hilo_high ("high");
static SimpleObjectMaker<HighHiLoWrapper, HiLoBaseWrapper> Contour_contour_hilo_high_wrapper ("high");


#include "HighHiLoWrapper.h"
static SimpleObjectMaker<HighHiLo, HiLoBase> Contour_contour_hilo_hi ("hi");
static SimpleObjectMaker<HighHiLoWrapper, HiLoBaseWrapper> Contour_contour_hilo_hi_wrapper ("hi");


#include "LowHiLoWrapper.h"
static SimpleObjectMaker<LowHiLo, HiLoBase> Contour_contour_hilo_low ("low");
static SimpleObjectMaker<LowHiLoWrapper, HiLoBaseWrapper> Contour_contour_hilo_low_wrapper ("low");


#include "LowHiLoWrapper.h"
static SimpleObjectMaker<LowHiLo, HiLoBase> Contour_contour_hilo_lo ("lo");
static SimpleObjectMaker<LowHiLoWrapper, HiLoBaseWrapper> Contour_contour_hilo_lo_wrapper ("lo");



#include "ValuePlotWrapper.h"
static SimpleObjectMaker<ValuePlot, ValuePlotBase> Contour_contour_grid_value_plot_gridvalues ("gridvalues");
static SimpleObjectMaker<ValuePlotWrapper, ValuePlotBaseWrapper> Contour_contour_grid_value_plot_gridvalues_wrapper ("gridvalues");


#include "ValuePlotWrapper.h"
static SimpleObjectMaker<ValuePlot, ValuePlotBase> Contour_contour_grid_value_plot_on ("on");
static SimpleObjectMaker<ValuePlotWrapper, ValuePlotBaseWrapper> Contour_contour_grid_value_plot_on_wrapper ("on");


#include "NoValuePlotWrapper.h"
static SimpleObjectMaker<NoValuePlot, ValuePlotBase> Contour_contour_grid_value_plot_nogridvalues ("nogridvalues");
static SimpleObjectMaker<NoValuePlotWrapper, ValuePlotBaseWrapper> Contour_contour_grid_value_plot_nogridvalues_wrapper ("nogridvalues");


#include "NoValuePlotWrapper.h"
static SimpleObjectMaker<NoValuePlot, ValuePlotBase> Contour_contour_grid_value_plot_off ("off");
static SimpleObjectMaker<NoValuePlotWrapper, ValuePlotBaseWrapper> Contour_contour_grid_value_plot_off_wrapper ("off");



