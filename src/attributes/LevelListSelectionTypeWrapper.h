
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileLevelListSelectionTypeAttributes.h
    \brief Definition of LevelListSelectionType Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef LevelListSelectionTypeWrapper_H
#define LevelListSelectionTypeWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "LevelListSelectionType.h"



#include "LevelSelectionWrapper.h"








namespace magics {

class MagRequest;


class LevelListSelectionTypeWrapper: public LevelSelectionWrapper

{
public:
//  --  constructor
    LevelListSelectionTypeWrapper();
    LevelListSelectionTypeWrapper(LevelListSelectionType*);
//  --  destructor
    virtual ~LevelListSelectionTypeWrapper();
    virtual void set(const MagRequest&);

    LevelListSelectionType* me()   { return levellistselectiontype_; }

   	virtual LevelListSelectionType* object() { return levellistselectiontype_; }


	virtual void object(LevelListSelectionType* o) {
		// Remember to delete the previous object
		levellistselectiontype_ = o;
		LevelSelectionWrapper::object(o);
		

	}



protected:
    LevelListSelectionType* levellistselectiontype_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const LevelListSelectionTypeWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif