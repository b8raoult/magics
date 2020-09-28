
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileProj4ProjectionAttributes.h
    \brief Definition of Proj4Projection Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef Proj4ProjectionAttributes_H
#define Proj4ProjectionAttributes_H

#include "magics.h"
namespace magics {

class XmlNode;
class Proj4ProjectionAttributes 
{
public:
//  --  constructor
    Proj4ProjectionAttributes();
    
//  --  destructor
    virtual ~Proj4ProjectionAttributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const Proj4ProjectionAttributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
	string setting_;
	double min_latitude_;
	double min_longitude_;
	double max_latitude_;
	double max_longitude_;
	double vertical_longitude_;
	double true_scale_north_;
	double true_scale_south_;
	double projection_height_;
	double projection_tilt_;
	double projection_azimuth_;
	double projection_view_latitude_;
	double projection_view_longitude_;
	double sweep_;
	string proj4_definition_;
	string coordinates_system_;
	 

private:
	friend ostream& operator<<(ostream& s,const Proj4ProjectionAttributes& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif

