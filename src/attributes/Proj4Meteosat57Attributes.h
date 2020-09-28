
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileProj4Meteosat57Attributes.h
    \brief Definition of Proj4Meteosat57 Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef Proj4Meteosat57Attributes_H
#define Proj4Meteosat57Attributes_H

#include "magics.h"
namespace magics {

class XmlNode;
class Proj4Meteosat57Attributes 
{
public:
//  --  constructor
    Proj4Meteosat57Attributes();
    
//  --  destructor
    virtual ~Proj4Meteosat57Attributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const Proj4Meteosat57Attributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
	 

private:
	friend ostream& operator<<(ostream& s,const Proj4Meteosat57Attributes& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif

