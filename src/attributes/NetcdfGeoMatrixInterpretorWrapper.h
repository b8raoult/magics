
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileNetcdfGeoMatrixInterpretorAttributes.h
    \brief Definition of NetcdfGeoMatrixInterpretor Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef NetcdfGeoMatrixInterpretorWrapper_H
#define NetcdfGeoMatrixInterpretorWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "NetcdfGeoMatrixInterpretor.h"



#include "NetcdfInterpretorWrapper.h"








namespace magics {

class MagRequest;


class NetcdfGeoMatrixInterpretorWrapper: public NetcdfInterpretorWrapper

{
public:
//  --  constructor
    NetcdfGeoMatrixInterpretorWrapper();
    NetcdfGeoMatrixInterpretorWrapper(NetcdfGeoMatrixInterpretor*);
//  --  destructor
    virtual ~NetcdfGeoMatrixInterpretorWrapper();
    virtual void set(const MagRequest&);

    NetcdfGeoMatrixInterpretor* me()   { return netcdfgeomatrixinterpretor_; }

   	virtual NetcdfGeoMatrixInterpretor* object() { return netcdfgeomatrixinterpretor_; }


	virtual void object(NetcdfGeoMatrixInterpretor* o) {
		// Remember to delete the previous object
		netcdfgeomatrixinterpretor_ = o;
		NetcdfInterpretorWrapper::object(o);
		

	}



protected:
    NetcdfGeoMatrixInterpretor* netcdfgeomatrixinterpretor_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const NetcdfGeoMatrixInterpretorWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif