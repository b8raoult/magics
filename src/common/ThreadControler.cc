/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include <assert.h>
#include <signal.h>


#ifndef AutoLock_H
#include "AutoLock.h"
#endif

#ifndef MagLog_H
#include "MagLog.h"
#endif

#ifndef MagExceptions_H
#include "MagExceptions.h"
#endif

#ifndef ThreadControler_H
#include "ThreadControler.h"
#endif

#ifndef Thread_H
#include "Thread.h"
#endif


using namespace magics;


ThreadControler::ThreadControler(Thread* proc, bool detached) :
    thread_(nullptr),
    detached_(detached),
    proc_(proc),
    running_(false) {
}

ThreadControler::~ThreadControler() {
    AutoLock<MutexCond> lock(cond_);

    if (running_) {
        // The Thread will delete itself
        // so there is no need for:
        // delete proc_;
    }
    else {
        delete proc_;
    }

    delete thread_;
}

//------------------------------------------------------

void ThreadControler::execute() {
    static const char* here = __FUNCTION__;

    //=================
    // Make sure the logs are created...


    //============

    Thread* proc = proc_;

    {  // Signal that we are running

        AutoLock<MutexCond> lock(cond_);
        running_ = true;
        cond_.signal();
    }


    try {
        proc->run();
    }
    catch (std::exception& e) {
        magics::MagLog::error() << "** " << e.what() << " Caught in " << here << endl;
        magics::MagLog::error() << "** MagException is termiates thread " << endl;
    }
    catch (...) {
        magics::MagLog::error() << "** UNKNOWN MagException Caught in " << here << endl;
        magics::MagLog::error() << "** MagException is termiates thread " << endl;
    }

    if (proc->autodel_)
        delete proc;
}

void* ThreadControler::startThread(void* data) {
    ((ThreadControler*)data)->execute();  // static_cast or dynamic_cast ??
    return 0;
}

void ThreadControler::start() {
    thread_ = new std::thread(ThreadControler::startThread, this);

    AutoLock<MutexCond> lock(cond_);


    while (!running_)
        cond_.wait();
}

void ThreadControler::kill() {
    // pthread_cancel(thread_);
}

void ThreadControler::stop() {
    // proc_->stop();
}

void ThreadControler::wait() {
    ASSERT(!detached_);
    thread_->join();
}

bool ThreadControler::active() {
    return thread_ != nullptr;
}

// bool ThreadControler::active() {
// #ifndef MAGICS_ON_WINDOWS
//     if (thread_ != 0)
// #else
//     if (thread_.p != 0)
// #endif
//     {
//         // Try see if it exists

//         int policy;
//         sched_param param;

//         int n = pthread_getschedparam(thread_, &policy, &param);

//         // The thread does not exist
//         if (n != 0) {
// #ifndef MAGICS_ON_WINDOWS
//             thread_ = 0;
// #else
//             thread_.p = 0;
//             thread_.x = 0;
// #endif
//         }
//     }
// #ifndef MAGICS_ON_WINDOWS
//     return thread_ != 0;
// #else
//     return thread_.p != 0;
// #endif
// }
