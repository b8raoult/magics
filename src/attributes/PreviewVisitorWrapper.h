
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \filePreviewVisitorAttributes.h
    \brief Definition of PreviewVisitor Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef PreviewVisitorWrapper_H
#define PreviewVisitorWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "PreviewVisitor.h"


 
#include "NoPreviewVisitorWrapper.h"






 

namespace magics {

class MagRequest;


class PreviewVisitorWrapper: public NoPreviewVisitorWrapper

{
public:
//  --  constructor
    PreviewVisitorWrapper();
    PreviewVisitorWrapper(PreviewVisitor*);
//  --  destructor
    virtual ~PreviewVisitorWrapper();
    virtual void set(const MagRequest&);
    
    PreviewVisitor* me()   { return previewvisitor_; }
   	
   	virtual PreviewVisitor* object() { return previewvisitor_; }
	

	virtual void object(PreviewVisitor* o) { 
		// Remember to delete the previous object
		previewvisitor_ = o;
		NoPreviewVisitorWrapper::object(o);
		

	}
    
  

protected:
    PreviewVisitor* previewvisitor_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const PreviewVisitorWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


