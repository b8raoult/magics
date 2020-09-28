
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileMvRootSceneNodeAttributes.h
    \brief Definition of MvRootSceneNode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef MvRootSceneNodeWrapper_H
#define MvRootSceneNodeWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "RootSceneNode.h"








 

namespace magics {

class MagRequest;


 	
class MvRootSceneNodeWrapper 

{
public:
//  --  constructor
    MvRootSceneNodeWrapper();
    MvRootSceneNodeWrapper(MvRootSceneNode*);
//  --  destructor
    virtual ~MvRootSceneNodeWrapper();
    virtual void set(const MagRequest&);
    
    MvRootSceneNode* me()   { return mvrootscenenode_; }
   	
   	virtual MvRootSceneNode* object() { return mvrootscenenode_; }
	

	virtual void object(MvRootSceneNode* o) { 
		// Remember to delete the previous object
		mvrootscenenode_ = o;
		

	}
    
  

protected:
    MvRootSceneNode* mvrootscenenode_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const MvRootSceneNodeWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


