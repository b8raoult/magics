/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include <time.h>

#ifndef MagLog_H
#include "MagLog.h"
#endif

#ifndef MagExceptions_H
#include "MagExceptions.h"
#endif

#ifndef MutexCond_H
#include "MutexCond.h"
#endif


#define PTHREAD_INIT NULL

MutexCond::MutexCond():
    lock_(mutex_, std::defer_lock) {

}

MutexCond::~MutexCond() {

}

void MutexCond::lock() {
    lock_.lock();
}

void MutexCond::unlock() {
    lock_.unlock();
}

void MutexCond::wait() {
    cond_.wait(lock_);
}


void MutexCond::signal() {
    cond_.notify_one();
}


void MutexCond::broadcast() {
    cond_.notify_all();
}
