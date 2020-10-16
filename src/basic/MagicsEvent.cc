/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file MagicsEvent.cc
    \brief

    Changes:

*/

#include "MagicsEvent.h"


magics::MagicsEvent::MagicsEvent() {}

magics::MagicsEvent::~MagicsEvent() {}

void magics::MagicsEvent::notify(magics::MagicsObserver&) {}

void magics::MagicsEvent::print(std::ostream& out) const {
    out << "MagicsEvent[]";
}
