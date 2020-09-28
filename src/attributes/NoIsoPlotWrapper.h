
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileNoIsoPlotAttributes.h
    \brief Definition of NoIsoPlot Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef NoIsoPlotWrapper_H
#define NoIsoPlotWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "IsoPlot.h"


 
#include "IsoPlotWrapper.h"






 

namespace magics {

class MagRequest;


class NoIsoPlotWrapper: public IsoPlotWrapper

{
public:
//  --  constructor
    NoIsoPlotWrapper();
    NoIsoPlotWrapper(NoIsoPlot*);
//  --  destructor
    virtual ~NoIsoPlotWrapper();
    virtual void set(const MagRequest&);
    
    NoIsoPlot* me()   { return noisoplot_; }
   	
   	virtual NoIsoPlot* object() { return noisoplot_; }
	

	virtual void object(NoIsoPlot* o) { 
		// Remember to delete the previous object
		noisoplot_ = o;
		IsoPlotWrapper::object(o);
		

	}
    
  

protected:
    NoIsoPlot* noisoplot_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const NoIsoPlotWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


