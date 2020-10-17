
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \filePolyShadingTechniqueAttributes.h
    \brief Definition of PolyShadingTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef PolyShadingTechniqueWrapper_H
#define PolyShadingTechniqueWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "PolyShadingTechnique.h"



#include "ShadingTechniqueWrapper.h"






#include "PolyShadingMethodWrapper.h"


namespace magics {

class MagRequest;


class PolyShadingTechniqueWrapper: public ShadingTechniqueWrapper

{
public:
//  --  constructor
    PolyShadingTechniqueWrapper();
    PolyShadingTechniqueWrapper(PolyShadingTechnique*);
//  --  destructor
    virtual ~PolyShadingTechniqueWrapper();
    virtual void set(const MagRequest&);

    PolyShadingTechnique* me()   { return polyshadingtechnique_; }

   	virtual PolyShadingTechnique* object() { return polyshadingtechnique_; }


	virtual void object(PolyShadingTechnique* o) {
		// Remember to delete the previous object
		polyshadingtechnique_ = o;
		ShadingTechniqueWrapper::object(o);
		

	}



protected:
    PolyShadingTechnique* polyshadingtechnique_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const PolyShadingTechniqueWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif