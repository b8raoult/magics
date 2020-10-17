
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileValuePlotBaseAttributes.h
    \brief Definition of ValuePlotBase Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef ValuePlotBaseWrapper_H
#define ValuePlotBaseWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "ValuePlotBase.h"










namespace magics {

class MagRequest;



class ValuePlotBaseWrapper

{
public:
//  --  constructor
    ValuePlotBaseWrapper();
    ValuePlotBaseWrapper(ValuePlotBase*);
//  --  destructor
    virtual ~ValuePlotBaseWrapper();
    virtual void set(const MagRequest&);

    ValuePlotBase* me()   { return valueplotbase_; }

   	virtual ValuePlotBase* object() { return valueplotbase_; }


	virtual void object(ValuePlotBase* o) {
		// Remember to delete the previous object
		valueplotbase_ = o;
		

	}



protected:
    ValuePlotBase* valueplotbase_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const ValuePlotBaseWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif