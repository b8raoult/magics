
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileFortranRootSceneNodeAttributes.h
    \brief Definition of FortranRootSceneNode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef FortranRootSceneNodeAttributes_H
#define FortranRootSceneNodeAttributes_H

#include "magics.h"
#include "Colour.h"
namespace magics {

class XmlNode;
class FortranRootSceneNodeAttributes 
{
public:
//  --  constructor
    FortranRootSceneNodeAttributes();
    
//  --  destructor
    virtual ~FortranRootSceneNodeAttributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const FortranRootSceneNodeAttributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
	double width_;
	double height_;
	bool frame_;
	string theme_;
	int thickness_;
	string plot_layout_;
	string plot_start_;
	string plot_direction_;
	bool legend_;
	bool silent_;
	unique_ptr<Colour> colour_;
	LineStyle style_;
	 

private:
	friend ostream& operator<<(ostream& s,const FortranRootSceneNodeAttributes& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif

