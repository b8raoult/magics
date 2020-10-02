/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

// File MutexCond.h
// Baudouin Raoult - ECMWF Jun 96

#ifndef MutexCond_H
#define MutexCond_H

#include <mutex>
#include <condition_variable>
// A mutex and a condition variable
// for Producer/Consumer architectures

class MutexCond {
public:
    // -- Contructors

    MutexCond();

    // -- Destructor

    ~MutexCond();

    // -- Methods

    void lock();
    void unlock();
    void wait();
    void signal();
    void broadcast();

private:
    // No copy allowed

    MutexCond(const MutexCond&);
    MutexCond& operator=(const MutexCond&);

    // -- Members

    std::recursive_mutex mutex_;
    std::condition_variable_any cond_;

    // Must be last
//    std::unique_lock<std::mutex> lock_;

};

#endif
