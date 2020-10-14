
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file TableDecoderAttributes.h
    \\brief Definition of TableDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "TableDecoderAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

TableDecoderAttributes::TableDecoderAttributes():
	path_(ParameterManager::getString("table_filename")),
	delimiter_(ParameterManager::getString("table_delimiter")),
	combine_delimiters_(ParameterManager::getBool("table_combine_delimiters")),
	header_row_(ParameterManager::getInt("table_header_row")),
	data_row_offset_(ParameterManager::getInt("table_data_row_offset")),
	meta_data_rows_(ParameterManager::getIntArray("table_meta_data_rows")),
	x_type_(ParameterManager::getString("table_x_type")),
	y_type_(ParameterManager::getString("table_y_type")),
	name_mode_(ParameterManager::getString("table_variable_identifier_type")),
	x_(ParameterManager::getString("table_x_variable")),
	y_(ParameterManager::getString("table_y_variable")),
	values_(ParameterManager::getString("table_value_variable")),
	lat_(ParameterManager::getString("table_latitude_variable")),
	lon_(ParameterManager::getString("table_longitude_variable")),
	x_component_(ParameterManager::getString("table_x_component_variable")),
	y_component_(ParameterManager::getString("table_y_component_variable")),
	x_missing_(ParameterManager::getDouble("table_x_missing_value")),
	y_missing_(ParameterManager::getDouble("table_y_missing_value"))
	,
	table_binning_(MagTranslator<string, BinningObject>().magics("table_binning"))
	
{
}


TableDecoderAttributes::~TableDecoderAttributes()
{

}


void TableDecoderAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	setAttribute(prefix, "table_filename", path_, params);
	setAttribute(prefix, "table_delimiter", delimiter_, params);
	setAttribute(prefix, "table_combine_delimiters", combine_delimiters_, params);
	setAttribute(prefix, "table_header_row", header_row_, params);
	setAttribute(prefix, "table_data_row_offset", data_row_offset_, params);
	setAttribute(prefix, "table_meta_data_rows", meta_data_rows_, params);
	setAttribute(prefix, "table_x_type", x_type_, params);
	setAttribute(prefix, "table_y_type", y_type_, params);
	setAttribute(prefix, "table_variable_identifier_type", name_mode_, params);
	setAttribute(prefix, "table_x_variable", x_, params);
	setAttribute(prefix, "table_y_variable", y_, params);
	setAttribute(prefix, "table_value_variable", values_, params);
	setAttribute(prefix, "table_latitude_variable", lat_, params);
	setAttribute(prefix, "table_longitude_variable", lon_, params);
	setAttribute(prefix, "table_x_component_variable", x_component_, params);
	setAttribute(prefix, "table_y_component_variable", y_component_, params);
	setAttribute(prefix, "table_x_missing_value", x_missing_, params);
	setAttribute(prefix, "table_y_missing_value", y_missing_, params);
	
	setMember(prefix, "table_binning", table_binning_, params);
	
}

void TableDecoderAttributes::copy(const TableDecoderAttributes& other)
{
	path_ = other.path_;
	delimiter_ = other.delimiter_;
	combine_delimiters_ = other.combine_delimiters_;
	header_row_ = other.header_row_;
	data_row_offset_ = other.data_row_offset_;
	meta_data_rows_ = other.meta_data_rows_;
	x_type_ = other.x_type_;
	y_type_ = other.y_type_;
	name_mode_ = other.name_mode_;
	x_ = other.x_;
	y_ = other.y_;
	values_ = other.values_;
	lat_ = other.lat_;
	lon_ = other.lon_;
	x_component_ = other.x_component_;
	y_component_ = other.y_component_;
	x_missing_ = other.x_missing_;
	y_missing_ = other.y_missing_;
	table_binning_ = unique_ptr<BinningObject>(other.table_binning_->clone());
	
}


bool TableDecoderAttributes::accept(const string& node)
{

	if ( magCompare(node, "table")  )
		return true;
	if ( acceptNode(node, table_binning_) )
		return true;
	
	return false;
}

void TableDecoderAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "table")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), table_binning_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), table_binning_, *elt);
		
	}
}

void TableDecoderAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	out << " delimiter = " <<  delimiter_;
	out << " combine_delimiters = " <<  combine_delimiters_;
	out << " header_row = " <<  header_row_;
	out << " data_row_offset = " <<  data_row_offset_;
	out << " meta_data_rows = " <<  meta_data_rows_;
	out << " x_type = " <<  x_type_;
	out << " y_type = " <<  y_type_;
	out << " name_mode = " <<  name_mode_;
	out << " x = " <<  x_;
	out << " y = " <<  y_;
	out << " values = " <<  values_;
	out << " lat = " <<  lat_;
	out << " lon = " <<  lon_;
	out << " x_component = " <<  x_component_;
	out << " y_component = " <<  y_component_;
	out << " x_missing = " <<  x_missing_;
	out << " y_missing = " <<  y_missing_;
	out << " table_binning = " <<  *table_binning_;
	
	out << "]" << "\n";
}

void TableDecoderAttributes::toxml(ostream& out)  const
{
	out <<  "\"table\"";
	out << ", \"table_filename\":";
	niceprint(out,path_);
	out << ", \"table_delimiter\":";
	niceprint(out,delimiter_);
	out << ", \"table_combine_delimiters\":";
	niceprint(out,combine_delimiters_);
	out << ", \"table_header_row\":";
	niceprint(out,header_row_);
	out << ", \"table_data_row_offset\":";
	niceprint(out,data_row_offset_);
	out << ", \"table_meta_data_rows\":";
	niceprint(out,meta_data_rows_);
	out << ", \"table_x_type\":";
	niceprint(out,x_type_);
	out << ", \"table_y_type\":";
	niceprint(out,y_type_);
	out << ", \"table_variable_identifier_type\":";
	niceprint(out,name_mode_);
	out << ", \"table_x_variable\":";
	niceprint(out,x_);
	out << ", \"table_y_variable\":";
	niceprint(out,y_);
	out << ", \"table_value_variable\":";
	niceprint(out,values_);
	out << ", \"table_latitude_variable\":";
	niceprint(out,lat_);
	out << ", \"table_longitude_variable\":";
	niceprint(out,lon_);
	out << ", \"table_x_component_variable\":";
	niceprint(out,x_component_);
	out << ", \"table_y_component_variable\":";
	niceprint(out,y_component_);
	out << ", \"table_x_missing_value\":";
	niceprint(out,x_missing_);
	out << ", \"table_y_missing_value\":";
	niceprint(out,y_missing_);
	out << ", \"table_binning\":";
	table_binning_->toxml(out);
	
}

static MagicsParameter<string> table_filename("table_filename", "");
static MagicsParameter<string> table_delimiter("table_delimiter", ",");
static MagicsParameter<string> table_combine_delimiters("table_combine_delimiters", "off");
static MagicsParameter<int> table_header_row("table_header_row", 1);
static MagicsParameter<int> table_data_row_offset("table_data_row_offset", 1);
static MagicsParameter<intarray> table_meta_data_rows("table_meta_data_rows", intarray());
static MagicsParameter<string> table_x_type("table_x_type", "number");
static MagicsParameter<string> table_y_type("table_y_type", "number");
static MagicsParameter<string> table_variable_identifier_type("table_variable_identifier_type", "index");
static MagicsParameter<string> table_x_variable("table_x_variable", "1");
static MagicsParameter<string> table_y_variable("table_y_variable", "2");
static MagicsParameter<string> table_value_variable("table_value_variable", "-1");
static MagicsParameter<string> table_latitude_variable("table_latitude_variable", "2");
static MagicsParameter<string> table_longitude_variable("table_longitude_variable", "1");
static MagicsParameter<string> table_x_component_variable("table_x_component_variable", "-1");
static MagicsParameter<string> table_y_component_variable("table_y_component_variable", "-1");
static MagicsParameter<double> table_x_missing_value("table_x_missing_value", -21.e6);
static MagicsParameter<double> table_y_missing_value("table_y_missing_value", -21.e6);
static MagicsParameter<string> table_binning("table_binning", "on");
#include "BinningObject.h"
static SimpleObjectMaker<NoBinningObject , BinningObject> nobinning_NoBinningObject("nobinning");
static SimpleObjectMaker<NoBinningObject , BinningObject> off_NoBinningObject("off");
static SimpleObjectMaker<BinningObject , BinningObject> binning_BinningObject("binning");
static SimpleObjectMaker<BinningObject , BinningObject> on_BinningObject("on");
