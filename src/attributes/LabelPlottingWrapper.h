
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileLabelPlottingAttributes.h
    \brief Definition of LabelPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef LabelPlottingWrapper_H
#define LabelPlottingWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "LabelPlotting.h"


 
#include "NoLabelPlottingWrapper.h"






 

namespace magics {

class MagRequest;


class LabelPlottingWrapper: public NoLabelPlottingWrapper

{
public:
//  --  constructor
    LabelPlottingWrapper();
    LabelPlottingWrapper(LabelPlotting*);
//  --  destructor
    virtual ~LabelPlottingWrapper();
    virtual void set(const MagRequest&);
    
    LabelPlotting* me()   { return labelplotting_; }
   	
   	virtual LabelPlotting* object() { return labelplotting_; }
	

	virtual void object(LabelPlotting* o) { 
		// Remember to delete the previous object
		labelplotting_ = o;
		NoLabelPlottingWrapper::object(o);
		

	}
    
  

protected:
    LabelPlotting* labelplotting_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const LabelPlottingWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


