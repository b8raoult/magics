
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileArrowPlottingAttributes.h
    \brief Definition of ArrowPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef ArrowPlottingWrapper_H
#define ArrowPlottingWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "ArrowPlotting.h"


 
#include "WindPlottingWrapper.h"






#include "CalmIndicatorWrapper.h"
 

namespace magics {

class MagRequest;


class ArrowPlottingWrapper: public WindPlottingWrapper

{
public:
//  --  constructor
    ArrowPlottingWrapper();
    ArrowPlottingWrapper(ArrowPlotting*);
//  --  destructor
    virtual ~ArrowPlottingWrapper();
    virtual void set(const MagRequest&);
    
    ArrowPlotting* me()   { return arrowplotting_; }
   	
   	virtual ArrowPlotting* object() { return arrowplotting_; }
	

	virtual void object(ArrowPlotting* o) { 
		// Remember to delete the previous object
		arrowplotting_ = o;
		WindPlottingWrapper::object(o);
		

	}
    
  

protected:
    ArrowPlotting* arrowplotting_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const ArrowPlottingWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


