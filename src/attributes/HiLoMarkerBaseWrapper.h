
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileHiLoMarkerBaseAttributes.h
    \brief Definition of HiLoMarkerBase Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef HiLoMarkerBaseWrapper_H
#define HiLoMarkerBaseWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "HiLoMarkerBase.h"










namespace magics {

class MagRequest;



class HiLoMarkerBaseWrapper

{
public:
//  --  constructor
    HiLoMarkerBaseWrapper();
    HiLoMarkerBaseWrapper(HiLoMarkerBase*);
//  --  destructor
    virtual ~HiLoMarkerBaseWrapper();
    virtual void set(const MagRequest&);

    HiLoMarkerBase* me()   { return hilomarkerbase_; }

   	virtual HiLoMarkerBase* object() { return hilomarkerbase_; }


	virtual void object(HiLoMarkerBase* o) {
		// Remember to delete the previous object
		hilomarkerbase_ = o;
		

	}



protected:
    HiLoMarkerBase* hilomarkerbase_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const HiLoMarkerBaseWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif