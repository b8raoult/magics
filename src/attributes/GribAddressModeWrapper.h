
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileGribAddressModeAttributes.h
    \brief Definition of GribAddressMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef GribAddressModeWrapper_H
#define GribAddressModeWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "GribAddressMode.h"








 

namespace magics {

class MagRequest;


 	
class GribAddressModeWrapper 

{
public:
//  --  constructor
    GribAddressModeWrapper();
    GribAddressModeWrapper(GribAddressMode*);
//  --  destructor
    virtual ~GribAddressModeWrapper();
    virtual void set(const MagRequest&);
    
    GribAddressMode* me()   { return gribaddressmode_; }
   	
   	virtual GribAddressMode* object() { return gribaddressmode_; }
	

	virtual void object(GribAddressMode* o) { 
		// Remember to delete the previous object
		gribaddressmode_ = o;
		

	}
    
  

protected:
    GribAddressMode* gribaddressmode_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const GribAddressModeWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


