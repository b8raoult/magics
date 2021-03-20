
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileLookupTableModeAttributes.h
    \brief Definition of LookupTableMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef LookupTableModeWrapper_H
#define LookupTableModeWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "LookupTableMode.h"










namespace magics {

class MagRequest;



class LookupTableModeWrapper

{
public:
//  --  constructor
    LookupTableModeWrapper();
    LookupTableModeWrapper(LookupTableMode*);
//  --  destructor
    virtual ~LookupTableModeWrapper();
    virtual void set(const MagRequest&);

    LookupTableMode* me()   { return lookuptablemode_; }

   	virtual LookupTableMode* object() { return lookuptablemode_; }


	virtual void object(LookupTableMode* o) {
		// Remember to delete the previous object
		lookuptablemode_ = o;
		

	}



protected:
    LookupTableMode* lookuptablemode_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const LookupTableModeWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif