
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileCalculateColourTechniqueAttributes.h
    \brief Definition of CalculateColourTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef CalculateColourTechniqueWrapper_H
#define CalculateColourTechniqueWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "CalculateColourTechnique.h"



#include "ColourTechniqueWrapper.h"








namespace magics {

class MagRequest;


class CalculateColourTechniqueWrapper: public ColourTechniqueWrapper

{
public:
//  --  constructor
    CalculateColourTechniqueWrapper();
    CalculateColourTechniqueWrapper(CalculateColourTechnique*);
//  --  destructor
    virtual ~CalculateColourTechniqueWrapper();
    virtual void set(const MagRequest&);

    CalculateColourTechnique* me()   { return calculatecolourtechnique_; }

   	virtual CalculateColourTechnique* object() { return calculatecolourtechnique_; }


	virtual void object(CalculateColourTechnique* o) {
		// Remember to delete the previous object
		calculatecolourtechnique_ = o;
		ColourTechniqueWrapper::object(o);
		

	}



protected:
    CalculateColourTechnique* calculatecolourtechnique_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const CalculateColourTechniqueWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif