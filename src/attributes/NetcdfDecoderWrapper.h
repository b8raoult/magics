
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileNetcdfDecoderAttributes.h
    \brief Definition of NetcdfDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef NetcdfDecoderWrapper_H
#define NetcdfDecoderWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "NetcdfDecoder.h"








#include "NetcdfInterpretorWrapper.h"


namespace magics {

class MagRequest;



class NetcdfDecoderWrapper

{
public:
//  --  constructor
    NetcdfDecoderWrapper();
    NetcdfDecoderWrapper(NetcdfDecoder*);
//  --  destructor
    virtual ~NetcdfDecoderWrapper();
    virtual void set(const MagRequest&);

    NetcdfDecoder* me()   { return netcdfdecoder_; }

   	virtual NetcdfDecoder* object() { return netcdfdecoder_; }


	virtual void object(NetcdfDecoder* o) {
		// Remember to delete the previous object
		netcdfdecoder_ = o;
		

	}



protected:
    NetcdfDecoder* netcdfdecoder_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const NetcdfDecoderWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif