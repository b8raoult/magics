
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileSymbolIndividualModeAttributes.h
    \brief Definition of SymbolIndividualMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef SymbolIndividualModeWrapper_H
#define SymbolIndividualModeWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "SymbolMode.h"


 
#include "SymbolModeWrapper.h"






 

namespace magics {

class MagRequest;


class SymbolIndividualModeWrapper: public SymbolModeWrapper

{
public:
//  --  constructor
    SymbolIndividualModeWrapper();
    SymbolIndividualModeWrapper(SymbolIndividualMode*);
//  --  destructor
    virtual ~SymbolIndividualModeWrapper();
    virtual void set(const MagRequest&);
    
    SymbolIndividualMode* me()   { return symbolindividualmode_; }
   	
   	virtual SymbolIndividualMode* object() { return symbolindividualmode_; }
	

	virtual void object(SymbolIndividualMode* o) { 
		// Remember to delete the previous object
		symbolindividualmode_ = o;
		SymbolModeWrapper::object(o);
		

	}
    
  

protected:
    SymbolIndividualMode* symbolindividualmode_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const SymbolIndividualModeWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


