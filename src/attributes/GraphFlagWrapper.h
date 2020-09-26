
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileGraphFlagAttributes.h
    \brief Definition of GraphFlag Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef GraphFlagWrapper_H
#define GraphFlagWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Bar.h"


 
#include "GraphWrapper.h"






 

namespace magics {

class MagRequest;


class GraphFlagWrapper: public GraphWrapper

{
public:
//  --  constructor
    GraphFlagWrapper();
    GraphFlagWrapper(GraphFlag*);
//  --  destructor
    virtual ~GraphFlagWrapper();
    virtual void set(const MagRequest&);
    
    GraphFlag* me()   { return graphflag_; }
   	
   	virtual GraphFlag* object() { return graphflag_; }
	

	virtual void object(GraphFlag* o) { 
		// Remember to delete the previous object
		graphflag_ = o;
		GraphWrapper::object(o);
		

	}
    
  

protected:
    GraphFlag* graphflag_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const GraphFlagWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


