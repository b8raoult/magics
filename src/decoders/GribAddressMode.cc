/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file GribAddressMode.cc
    \brief

    Changes:

*/

#include "GribAddressMode.h"

GribAddressMode* magics::GribAddressMode::clone() const {
    MagLog::dev() << "GribAddressMode::set(const map<string, string&)---> to be checked!...\n";
    return new GribAddressMode();
}

void GribAddressMode::toxml(ostream&, int) const {
    MagLog::dev() << "GribAddressMode::toxml(ostream&, int = 0)---> to be checked!...\n";
}

grib_handle* GribAddressMode::operator()(grib_context*, FILE*, int) const {
    MagLog::dev() << "GribAddressMode::toxml(ostream&, int = 0)---> to be checked!...\n";
    return 0;
}


grib_handle* GribAddressMode::operator()(grib_context*, FILE*, long) const {
    MagLog::dev() << "GribAddressMode::toxml(ostream&, int = 0)---> to be checked!...\n";
    return 0;
}

void GribAddressMode::print(ostream& out) const {
    out << "GribAddressMode[]";
}

GribAddressMode* GribAddressRecordMode::clone() const {
    GribAddressMode* mode = new GribAddressRecordMode();
    return mode;
}

grib_handle* GribAddressRecordMode::operator()(grib_context*, FILE* file, int position) const {
    grib_handle* handle = 0;


    grib_context* context = grib_context_get_default();
    int error;
    for (int i = 0; i < position - 1; i++) {
        // grib_read_any_from_file_alloc (context, file,  &msg , &size);
        // grib_context_free(context,msg);
        // MagLog::debug() << "call to grib_handle_new_from_file for position " << i << "\n";
        handle = grib_handle_new_from_file(context, file, &error);
        grib_handle_delete(handle);
    }

    handle = grib_handle_new_from_file(0, file, &error);

    return handle;
}

void GribAddressRecordMode::print(ostream& out) const {
    out << "GribAddressRecordMode\n";
}

GribAddressMode* GribAddressByteMode::clone() const {
    GribAddressMode* mode = new GribAddressByteMode();
    return mode;
}

grib_handle* GribAddressByteMode::operator()(grib_context* context, FILE* file, long position) const {
    fseek(file, position, SEEK_SET);
    grib_handle* handle = 0;

    int error;
    handle = grib_handle_new_from_file(0, file, &error);

    return handle;
}

void GribAddressByteMode::print(ostream& out) const {
    out << "GribAddressRecordMode\n";
}

grib_handle* GribAddressByteMode::operator()(grib_context* context, FILE* file, int position) const {
    long int offset = (long int)position;
    // cout << "OFFSET-->" << offset << endl;
    fseek(file, (long int)position, SEEK_SET);
    grib_handle* handle = 0;

    int error;
    handle = grib_handle_new_from_file(0, file, &error);

    return handle;
}
