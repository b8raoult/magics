/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file ContourLibrary.h
    \brief Definition of the Template class ContourLibrary.

    Magics Team - ECMWF 2010

    Started: Fri 16-Jul-2010

    Changes:

*/

#ifndef CliMetLabLibrary_H
#define CliMetLabLibrary_H

#include "magics.h"

#include "ContourLibrary.h"

namespace magics {

class CliMetLabLibrary : public ContourLibrary {
public:
    CliMetLabLibrary();
    virtual ~CliMetLabLibrary();

    // set the meta data to be collected
    void askId(MetaDataCollector&);

    bool checkId(MetaDataCollector&, MetaDataCollector&);
    void setCriteria(MetaDataCollector&, const string&);

    // set the map to set the contour!
    void getStyle(MetaDataCollector&, MagDef&, StyleEntry&);
    void getStyle(const string&, MagDef&);

    void getScaling(MetaDataCollector&, double&, double&);



protected:
    //! Method to print string about this class on to a stream of type ostream (virtual).
    virtual void print(ostream&) const;

};


}  // namespace magics
#endif
