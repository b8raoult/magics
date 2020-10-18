
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileUVWindModeAttributes.h
    \brief Definition of UVWindMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef UVWindModeWrapper_H
#define UVWindModeWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "WindMode.h"



#include "WindModeWrapper.h"








namespace magics {

class MagRequest;


class UVWindModeWrapper: public WindModeWrapper

{
public:
//  --  constructor
    UVWindModeWrapper();
    UVWindModeWrapper(UVWindMode*);
//  --  destructor
    virtual ~UVWindModeWrapper();
    virtual void set(const MagRequest&);

    UVWindMode* me()   { return uvwindmode_; }

   	virtual UVWindMode* object() { return uvwindmode_; }


	virtual void object(UVWindMode* o) {
		// Remember to delete the previous object
		uvwindmode_ = o;
		WindModeWrapper::object(o);
		

	}



protected:
    UVWindMode* uvwindmode_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const UVWindModeWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif