
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileListColourTechniqueAttributes.h
    \brief Definition of ListColourTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef ListColourTechniqueWrapper_H
#define ListColourTechniqueWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "ListColourTechnique.h"



#include "ColourTechniqueWrapper.h"








namespace magics {

class MagRequest;


class ListColourTechniqueWrapper: public ColourTechniqueWrapper

{
public:
//  --  constructor
    ListColourTechniqueWrapper();
    ListColourTechniqueWrapper(ListColourTechnique*);
//  --  destructor
    virtual ~ListColourTechniqueWrapper();
    virtual void set(const MagRequest&);

    ListColourTechnique* me()   { return listcolourtechnique_; }

   	virtual ListColourTechnique* object() { return listcolourtechnique_; }


	virtual void object(ListColourTechnique* o) {
		// Remember to delete the previous object
		listcolourtechnique_ = o;
		ColourTechniqueWrapper::object(o);
		

	}



protected:
    ListColourTechnique* listcolourtechnique_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const ListColourTechniqueWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif