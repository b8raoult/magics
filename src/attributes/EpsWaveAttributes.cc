
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EpsWaveAttributes.h
    \\brief Definition of EpsWave Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-13
*/

#include "EpsWaveAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

EpsWaveAttributes::EpsWaveAttributes():
	colour_(ParameterManager::getStringArray("eps_rose_wave_colour"))
	
	
{
}


EpsWaveAttributes::~EpsWaveAttributes()
{

}


void EpsWaveAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "eps";
	prefix[i++] = "eps_rose_wave";
	
	setAttribute(prefix, "eps_rose_wave_colour", colour_, params);
	
	
}

void EpsWaveAttributes::copy(const EpsWaveAttributes& other)
{
	colour_ = other.colour_;
	
}


bool EpsWaveAttributes::accept(const string& node)
{

	if ( magCompare(node, "epswave")  )
		return true;
	
	return false;
}

void EpsWaveAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "epswave")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void EpsWaveAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " colour = " <<  colour_;
	
	out << "]" << "\n";
}

void EpsWaveAttributes::toxml(ostream& out)  const
{
	out <<  "\"epswave\"";
	out << ", \"eps_rose_wave_colour\":";
	niceprint(out,colour_);
	
}

static MagicsParameter<stringarray> eps_rose_wave_colour("eps_rose_wave_colour", stringarray());
