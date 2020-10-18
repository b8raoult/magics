
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileTitleTemplateAttributes.h
    \brief Definition of TitleTemplate Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef TitleTemplateWrapper_H
#define TitleTemplateWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "TitleTemplate.h"










namespace magics {

class MagRequest;



class TitleTemplateWrapper

{
public:
//  --  constructor
    TitleTemplateWrapper();
    TitleTemplateWrapper(TitleTemplate*);
//  --  destructor
    virtual ~TitleTemplateWrapper();
    virtual void set(const MagRequest&);

    TitleTemplate* me()   { return titletemplate_; }

   	virtual TitleTemplate* object() { return titletemplate_; }


	virtual void object(TitleTemplate* o) {
		// Remember to delete the previous object
		titletemplate_ = o;
		

	}



protected:
    TitleTemplate* titletemplate_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const TitleTemplateWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif