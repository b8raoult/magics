
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \filePostScriptDriverAttributes.h
    \brief Definition of PostScriptDriver Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef PostScriptDriverWrapper_H
#define PostScriptDriverWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "PostScriptDriver.h"



#include "BaseDriverWrapper.h"








namespace magics {

class MagRequest;


class PostScriptDriverWrapper: public BaseDriverWrapper

{
public:
//  --  constructor
    PostScriptDriverWrapper();
    PostScriptDriverWrapper(PostScriptDriver*);
//  --  destructor
    virtual ~PostScriptDriverWrapper();
    virtual void set(const MagRequest&);

    PostScriptDriver* me()   { return postscriptdriver_; }

   	virtual PostScriptDriver* object() { return postscriptdriver_; }


	virtual void object(PostScriptDriver* o) {
		// Remember to delete the previous object
		postscriptdriver_ = o;
		BaseDriverWrapper::object(o);
		

	}



protected:
    PostScriptDriver* postscriptdriver_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const PostScriptDriverWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif