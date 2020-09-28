
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileNoIsoShadingAttributes.h
    \brief Definition of NoIsoShading Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef NoIsoShadingWrapper_H
#define NoIsoShadingWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "IsoShading.h"








 

namespace magics {

class MagRequest;


 	
class NoIsoShadingWrapper 

{
public:
//  --  constructor
    NoIsoShadingWrapper();
    NoIsoShadingWrapper(NoIsoShading*);
//  --  destructor
    virtual ~NoIsoShadingWrapper();
    virtual void set(const MagRequest&);
    
    NoIsoShading* me()   { return noisoshading_; }
   	
   	virtual NoIsoShading* object() { return noisoshading_; }
	

	virtual void object(NoIsoShading* o) { 
		// Remember to delete the previous object
		noisoshading_ = o;
		

	}
    
  

protected:
    NoIsoShading* noisoshading_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const NoIsoShadingWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


