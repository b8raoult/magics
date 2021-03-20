
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileProj4AutomaticAttributes.h
    \brief Definition of Proj4Automatic Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef Proj4AutomaticWrapper_H
#define Proj4AutomaticWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Proj4Projection.h"



#include "Proj4ProjectionWrapper.h"








namespace magics {

class MagRequest;


class Proj4AutomaticWrapper: public Proj4ProjectionWrapper

{
public:
//  --  constructor
    Proj4AutomaticWrapper();
    Proj4AutomaticWrapper(Proj4Automatic*);
//  --  destructor
    virtual ~Proj4AutomaticWrapper();
    virtual void set(const MagRequest&);

    Proj4Automatic* me()   { return proj4automatic_; }

   	virtual Proj4Automatic* object() { return proj4automatic_; }


	virtual void object(Proj4Automatic* o) {
		// Remember to delete the previous object
		proj4automatic_ = o;
		Proj4ProjectionWrapper::object(o);
		

	}



protected:
    Proj4Automatic* proj4automatic_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const Proj4AutomaticWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif