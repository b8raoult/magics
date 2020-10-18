
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileLowHiLoAttributes.h
    \brief Definition of LowHiLo Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef LowHiLoWrapper_H
#define LowHiLoWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "HiLo.h"



#include "HiLoWrapper.h"








namespace magics {

class MagRequest;


class LowHiLoWrapper: public HiLoWrapper

{
public:
//  --  constructor
    LowHiLoWrapper();
    LowHiLoWrapper(LowHiLo*);
//  --  destructor
    virtual ~LowHiLoWrapper();
    virtual void set(const MagRequest&);

    LowHiLo* me()   { return lowhilo_; }

   	virtual LowHiLo* object() { return lowhilo_; }


	virtual void object(LowHiLo* o) {
		// Remember to delete the previous object
		lowhilo_ = o;
		HiLoWrapper::object(o);
		

	}



protected:
    LowHiLo* lowhilo_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const LowHiLoWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif