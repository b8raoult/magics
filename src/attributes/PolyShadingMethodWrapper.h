
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \filePolyShadingMethodAttributes.h
    \brief Definition of PolyShadingMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef PolyShadingMethodWrapper_H
#define PolyShadingMethodWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "PolyShadingMethod.h"










namespace magics {

class MagRequest;



class PolyShadingMethodWrapper

{
public:
//  --  constructor
    PolyShadingMethodWrapper();
    PolyShadingMethodWrapper(PolyShadingMethod*);
//  --  destructor
    virtual ~PolyShadingMethodWrapper();
    virtual void set(const MagRequest&);

    PolyShadingMethod* me()   { return polyshadingmethod_; }

   	virtual PolyShadingMethod* object() { return polyshadingmethod_; }


	virtual void object(PolyShadingMethod* o) {
		// Remember to delete the previous object
		polyshadingmethod_ = o;
		

	}



protected:
    PolyShadingMethod* polyshadingmethod_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const PolyShadingMethodWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif