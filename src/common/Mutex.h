/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

// File Mutex.h
// Baudouin Raoult - ECMWF May 96

#ifndef Mutex_H
#define Mutex_H

#ifdef machine_H
#define marsmachine_H
#endif

#include <mutex>

class Mutex {
public:
    // -- Contructors

    Mutex();

    // -- Destructor

    ~Mutex();

    // -- Methods

    void lock();
    void unlock();

    // -- Class methods

    static Mutex& global();

private:
    // No copy allowed

    Mutex(const Mutex&);
    Mutex& operator=(const Mutex&);

protected:
    // -- Members

    std::recursive_mutex mutex_;

};

#endif
