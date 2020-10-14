
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ImportObjectHandlerAttributes.h
    \\brief Definition of ImportObjectHandler Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "ImportObjectHandlerAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

ImportObjectHandlerAttributes::ImportObjectHandlerAttributes():
	path_(ParameterManager::getString("import_file_name")),
	format_(ParameterManager::getString("import_format")),
	overlay_(ParameterManager::getBool("import_overlay")),
	import_x_(ParameterManager::getDouble("import_x_position")),
	import_y_(ParameterManager::getDouble("import_y_position")),
	import_width_(ParameterManager::getDouble("import_width")),
	import_height_(ParameterManager::getDouble("import_height"))
	
	
{
}


ImportObjectHandlerAttributes::~ImportObjectHandlerAttributes()
{

}


void ImportObjectHandlerAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	setAttribute(prefix, "import_file_name", path_, params);
	setAttribute(prefix, "import_format", format_, params);
	setAttribute(prefix, "import_overlay", overlay_, params);
	setAttribute(prefix, "import_x_position", import_x_, params);
	setAttribute(prefix, "import_y_position", import_y_, params);
	setAttribute(prefix, "import_width", import_width_, params);
	setAttribute(prefix, "import_height", import_height_, params);
	
	
}

void ImportObjectHandlerAttributes::copy(const ImportObjectHandlerAttributes& other)
{
	path_ = other.path_;
	format_ = other.format_;
	overlay_ = other.overlay_;
	import_x_ = other.import_x_;
	import_y_ = other.import_y_;
	import_width_ = other.import_width_;
	import_height_ = other.import_height_;
	
}


bool ImportObjectHandlerAttributes::accept(const string& node)
{

	if ( magCompare(node, "import")  )
		return true;
	
	return false;
}

void ImportObjectHandlerAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "import")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void ImportObjectHandlerAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	out << " format = " <<  format_;
	out << " overlay = " <<  overlay_;
	out << " import_x = " <<  import_x_;
	out << " import_y = " <<  import_y_;
	out << " import_width = " <<  import_width_;
	out << " import_height = " <<  import_height_;
	
	out << "]" << "\n";
}

void ImportObjectHandlerAttributes::toxml(ostream& out)  const
{
	out <<  "\"import\"";
	out << ", \"import_file_name\":";
	niceprint(out,path_);
	out << ", \"import_format\":";
	niceprint(out,format_);
	out << ", \"import_overlay\":";
	niceprint(out,overlay_);
	out << ", \"import_x_position\":";
	niceprint(out,import_x_);
	out << ", \"import_y_position\":";
	niceprint(out,import_y_);
	out << ", \"import_width\":";
	niceprint(out,import_width_);
	out << ", \"import_height\":";
	niceprint(out,import_height_);
	
}

static MagicsParameter<string> import_file_name("import_file_name", "");
static MagicsParameter<string> import_format("import_format", "png");
static MagicsParameter<string> import_overlay("import_overlay", "on");
static MagicsParameter<double> import_x_position("import_x_position", 0);
static MagicsParameter<double> import_y_position("import_y_position", 0);
static MagicsParameter<double> import_width("import_width", -1);
static MagicsParameter<double> import_height("import_height", -1);
