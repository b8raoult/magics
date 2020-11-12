
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileHiLoAttributes.h
    \brief Definition of HiLo Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef HiLoWrapper_H
#define HiLoWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "HiLo.h"



#include "HiLoBaseWrapper.h"






#include "HiLoTechniqueWrapper.h"
#include "HiLoMarkerBaseWrapper.h"


namespace magics {

class MagRequest;


class HiLoWrapper: public HiLoBaseWrapper

{
public:
//  --  constructor
    HiLoWrapper();
    HiLoWrapper(HiLo*);
//  --  destructor
    virtual ~HiLoWrapper();
    virtual void set(const MagRequest&);

    HiLo* me()   { return hilo_; }

   	virtual HiLo* object() { return hilo_; }


	virtual void object(HiLo* o) {
		// Remember to delete the previous object
		hilo_ = o;
		HiLoBaseWrapper::object(o);
		

	}



protected:
    HiLo* hilo_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const HiLoWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif