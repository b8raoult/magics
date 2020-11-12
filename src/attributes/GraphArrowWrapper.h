
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileGraphArrowAttributes.h
    \brief Definition of GraphArrow Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef GraphArrowWrapper_H
#define GraphArrowWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Bar.h"



#include "GraphWrapper.h"








namespace magics {

class MagRequest;


class GraphArrowWrapper: public GraphWrapper

{
public:
//  --  constructor
    GraphArrowWrapper();
    GraphArrowWrapper(GraphArrow*);
//  --  destructor
    virtual ~GraphArrowWrapper();
    virtual void set(const MagRequest&);

    GraphArrow* me()   { return grapharrow_; }

   	virtual GraphArrow* object() { return grapharrow_; }


	virtual void object(GraphArrow* o) {
		// Remember to delete the previous object
		grapharrow_ = o;
		GraphWrapper::object(o);
		

	}



protected:
    GraphArrow* grapharrow_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const GraphArrowWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif