
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileImageCalculateColourTechniqueAttributes.h
    \brief Definition of ImageCalculateColourTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef ImageCalculateColourTechniqueWrapper_H
#define ImageCalculateColourTechniqueWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "ImageCalculateColourTechnique.h"








 

namespace magics {

class MagRequest;


 	
class ImageCalculateColourTechniqueWrapper 

{
public:
//  --  constructor
    ImageCalculateColourTechniqueWrapper();
    ImageCalculateColourTechniqueWrapper(ImageCalculateColourTechnique*);
//  --  destructor
    virtual ~ImageCalculateColourTechniqueWrapper();
    virtual void set(const MagRequest&);
    
    ImageCalculateColourTechnique* me()   { return imagecalculatecolourtechnique_; }
   	
   	virtual ImageCalculateColourTechnique* object() { return imagecalculatecolourtechnique_; }
	

	virtual void object(ImageCalculateColourTechnique* o) { 
		// Remember to delete the previous object
		imagecalculatecolourtechnique_ = o;
		

	}
    
  

protected:
    ImageCalculateColourTechnique* imagecalculatecolourtechnique_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const ImageCalculateColourTechniqueWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


