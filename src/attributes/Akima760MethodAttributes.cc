
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Akima760MethodAttributes.h
    \\brief Definition of Akima760Method Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "Akima760MethodAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

Akima760MethodAttributes::Akima760MethodAttributes():
	resolutionX_(ParameterManager::getDouble("contour_akima_x_resolution")),
	resolutionY_(ParameterManager::getDouble("contour_akima_y_resolution"))
	
	
{
}


Akima760MethodAttributes::~Akima760MethodAttributes()
{

}


void Akima760MethodAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	setAttribute(prefix, "contour_akima_x_resolution", resolutionX_, params);
	setAttribute(prefix, "contour_akima_y_resolution", resolutionY_, params);
	
	
}

void Akima760MethodAttributes::copy(const Akima760MethodAttributes& other)
{
	resolutionX_ = other.resolutionX_;
	resolutionY_ = other.resolutionY_;
	
}


bool Akima760MethodAttributes::accept(const string& node)
{

	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void Akima760MethodAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void Akima760MethodAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " resolutionX = " <<  resolutionX_;
	out << " resolutionY = " <<  resolutionY_;
	
	out << "]" << "\n";
}

void Akima760MethodAttributes::toxml(ostream& out)  const
{
	out <<  "\"\"";
	out << ", \"contour_akima_x_resolution\":";
	niceprint(out,resolutionX_);
	out << ", \"contour_akima_y_resolution\":";
	niceprint(out,resolutionY_);
	
}

static MagicsParameter<double> contour_akima_x_resolution("contour_akima_x_resolution", 1.5);
static MagicsParameter<double> contour_akima_y_resolution("contour_akima_y_resolution", 1.5);
