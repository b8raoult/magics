
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileMarkerShadingTechniqueAttributes.h
    \brief Definition of MarkerShadingTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef MarkerShadingTechniqueWrapper_H
#define MarkerShadingTechniqueWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "MarkerShadingTechnique.h"


 
#include "ShadingTechniqueWrapper.h"






 

namespace magics {

class MagRequest;


class MarkerShadingTechniqueWrapper: public ShadingTechniqueWrapper

{
public:
//  --  constructor
    MarkerShadingTechniqueWrapper();
    MarkerShadingTechniqueWrapper(MarkerShadingTechnique*);
//  --  destructor
    virtual ~MarkerShadingTechniqueWrapper();
    virtual void set(const MagRequest&);
    
    MarkerShadingTechnique* me()   { return markershadingtechnique_; }
   	
   	virtual MarkerShadingTechnique* object() { return markershadingtechnique_; }
	

	virtual void object(MarkerShadingTechnique* o) { 
		// Remember to delete the previous object
		markershadingtechnique_ = o;
		ShadingTechniqueWrapper::object(o);
		

	}
    
  

protected:
    MarkerShadingTechnique* markershadingtechnique_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const MarkerShadingTechniqueWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


