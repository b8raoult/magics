
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileEmagramGridAttributes.h
    \brief Definition of EmagramGrid Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef EmagramGridWrapper_H
#define EmagramGridWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "EmagramGrid.h"


 
#include "TephiGridWrapper.h"






 

namespace magics {

class MagRequest;


class EmagramGridWrapper: public TephiGridWrapper

{
public:
//  --  constructor
    EmagramGridWrapper();
    EmagramGridWrapper(EmagramGrid*);
//  --  destructor
    virtual ~EmagramGridWrapper();
    virtual void set(const MagRequest&);
    
    EmagramGrid* me()   { return emagramgrid_; }
   	
   	virtual EmagramGrid* object() { return emagramgrid_; }
	

	virtual void object(EmagramGrid* o) { 
		// Remember to delete the previous object
		emagramgrid_ = o;
		TephiGridWrapper::object(o);
		

	}
    
  

protected:
    EmagramGrid* emagramgrid_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const EmagramGridWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


