
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \filePositionListAxisMethodAttributes.h
    \brief Definition of PositionListAxisMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef PositionListAxisMethodWrapper_H
#define PositionListAxisMethodWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "AxisMethod.h"



#include "AxisMethodWrapper.h"








namespace magics {

class MagRequest;


class PositionListAxisMethodWrapper: public AxisMethodWrapper

{
public:
//  --  constructor
    PositionListAxisMethodWrapper();
    PositionListAxisMethodWrapper(PositionListAxisMethod*);
//  --  destructor
    virtual ~PositionListAxisMethodWrapper();
    virtual void set(const MagRequest&);

    PositionListAxisMethod* me()   { return positionlistaxismethod_; }

   	virtual PositionListAxisMethod* object() { return positionlistaxismethod_; }


	virtual void object(PositionListAxisMethod* o) {
		// Remember to delete the previous object
		positionlistaxismethod_ = o;
		AxisMethodWrapper::object(o);
		

	}



protected:
    PositionListAxisMethod* positionlistaxismethod_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const PositionListAxisMethodWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif