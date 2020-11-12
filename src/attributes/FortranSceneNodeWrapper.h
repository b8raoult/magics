
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileFortranSceneNodeAttributes.h
    \brief Definition of FortranSceneNode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef FortranSceneNodeWrapper_H
#define FortranSceneNodeWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "SceneNode.h"








#include "NoPageIDWrapper.h"


namespace magics {

class MagRequest;



class FortranSceneNodeWrapper

{
public:
//  --  constructor
    FortranSceneNodeWrapper();
    FortranSceneNodeWrapper(FortranSceneNode*);
//  --  destructor
    virtual ~FortranSceneNodeWrapper();
    virtual void set(const MagRequest&);

    FortranSceneNode* me()   { return fortranscenenode_; }

   	virtual FortranSceneNode* object() { return fortranscenenode_; }


	virtual void object(FortranSceneNode* o) {
		// Remember to delete the previous object
		fortranscenenode_ = o;
		

	}



protected:
    FortranSceneNode* fortranscenenode_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const FortranSceneNodeWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif