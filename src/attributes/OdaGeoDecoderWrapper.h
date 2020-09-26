
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileOdaGeoDecoderAttributes.h
    \brief Definition of OdaGeoDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef OdaGeoDecoderWrapper_H
#define OdaGeoDecoderWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "OdaGeoDecoder.h"








#include "BinningObjectWrapper.h"
 

namespace magics {

class MagRequest;


 	
class OdaGeoDecoderWrapper 

{
public:
//  --  constructor
    OdaGeoDecoderWrapper();
    OdaGeoDecoderWrapper(OdaGeoDecoder*);
//  --  destructor
    virtual ~OdaGeoDecoderWrapper();
    virtual void set(const MagRequest&);
    
    OdaGeoDecoder* me()   { return odageodecoder_; }
   	
   	virtual OdaGeoDecoder* object() { return odageodecoder_; }
	

	virtual void object(OdaGeoDecoder* o) { 
		// Remember to delete the previous object
		odageodecoder_ = o;
		

	}
    
  

protected:
    OdaGeoDecoder* odageodecoder_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const OdaGeoDecoderWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


