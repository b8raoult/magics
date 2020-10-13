/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

/*! \file MagicsCalls.cc
    \brief Implementation of Fortran and C interface

 To use the C interface "magics_api.h" must be included.

 Changes: 13-06-2006 Added C interface (Stephan)

 \sa magics_api.h
*/

#include <FortranMagics.h>
#include <MagLog.h>
#include <MagicsGlobal.h>
#include <MagicsParameter.h>
#include <WebFormat.h>
#include <CompatibilityHelper.h>

extern "C" {
#include <magics_api.h>
}
/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

/*! \file MagicsCalls.cc
    \brief Implementation of Fortran and C interface

 To use the C interface "magics_api.h" must be included.

 Changes: 13-06-2006 Added C interface (Stephan)

 \sa magics_api.h
*/

#include "MagicsCalls.h"
#include "magics.h"
// #include <MagLog.h>
// #include <MagicsGlobal.h>
// #include <MagicsParameter.h>
// #include <WebFormat.h>
// #include "py_calls.h"

// extern "C" {
// #include <magics_api.h>
// }

using namespace magics;

template <class T>
void c_void(const char* name, T proc) {
    try {
        proc();
    }
    catch (std::exception& e) {
        MagLog::error() << "EXCEPTION in mag_" << name << ": " << e.what() << std::endl;
    }
    catch (...) {
        MagLog::error() << "EXCEPTION in mag_" << name << ": unknown" << std::endl;
    }
}

template <class T>
const char* c_char(const char* name, T proc) {

    try {
        return proc();
    }
    catch (std::exception& e) {
        MagLog::error() << "EXCEPTION in mag_" << name << ": " << e.what() << std::endl;
    }
    catch (...) {
        MagLog::error() << "EXCEPTION in mag_" << name << ": unknown" << std::endl;
    }

    return nullptr;
}


extern "C" {


#define C_VOID(NAME) \
    MAGICS_EXPORT void mag_##NAME() { c_void(#NAME, MagicsCalls::NAME); }

#define C_CHAR(NAME) \
    MAGICS_EXPORT const char* mag_##NAME() { return c_char(#NAME, MagicsCalls::NAME); }


C_VOID(axis)
C_VOID(boxplot)
C_VOID(close)
C_VOID(coast)
C_VOID(cont)
C_VOID(eps)
C_VOID(epsbar)
C_VOID(epscloud)
C_VOID(epsgraph)
C_VOID(epsinput)
C_VOID(epslight)
C_VOID(epsplumes)
C_VOID(epsshading)
C_VOID(epswave)
C_VOID(epswind)
C_VOID(geo)
C_VOID(geojson)
C_VOID(graph)
C_VOID(grib)
C_VOID(image)
C_VOID(import)
C_VOID(info)
C_VOID(input)
C_VOID(keep_compatibility)  // TODO: review name
C_VOID(legend)
C_VOID(line)
C_VOID(mapgen)
C_VOID(metbufr)
C_VOID(metgraph)
C_VOID(mute)
C_VOID(netcdf)
C_VOID(obs)
C_VOID(odb)
C_VOID(open)
C_VOID(overlay)
C_VOID(plot)
C_VOID(print)
C_VOID(raw)
C_VOID(set_python)  // TODO: review name
C_VOID(symb)
C_VOID(table)
C_VOID(taylor)
C_VOID(tephi)
C_VOID(text)
C_VOID(tile)
C_VOID(unmute)  // TODO: review name
C_VOID(wind)
C_VOID(wrepjson)

C_CHAR(knowndrivers)  // TODO: review name
C_CHAR(metagrib)      // TODO: review name
C_CHAR(metainput)     // TODO: review name
C_CHAR(metanetcdf)    // TODO: review name

MAGICS_EXPORT void mag_new(const char* page) {
    c_void("new", [page] { MagicsCalls::page(page); });
}

MAGICS_EXPORT void mag_reset(const char* name) {
    c_void("reset", [name] { MagicsCalls::reset(name); });
}

MAGICS_EXPORT void mag_setc(const char* name, const char* value) {
    c_void("setc", [name, value] { MagicsCalls::setc(name, value); });
}

MAGICS_EXPORT void mag_setr(const char* name, const double value) {
    c_void("setr", [name, value] { MagicsCalls::setr(name, value); });
}

MAGICS_EXPORT void mag_seti(const char* name, const int value) {
    c_void("seti", [name, value] { MagicsCalls::seti(name, value); });
}

MAGICS_EXPORT void mag_set1r(const char* name, const double* data, const int dim1) {
    c_void("set1r", [name, data, dim1] { MagicsCalls::set1r(name, data, dim1); });
}

MAGICS_EXPORT void mag_set2r(const char* name, const double* data, const int dim1, const int dim2) {
    c_void("set2r", [name, data, dim1, dim2] { MagicsCalls::set2r(name, data, dim1, dim2); });
}

MAGICS_EXPORT void mag_set1i(const char* name, const int* data, const int dim1) {
    c_void("set1i", [name, data, dim1] { MagicsCalls::set1i(name, data, dim1); });
}

MAGICS_EXPORT void mag_set2i(const char* name, const int* data, const int dim1, const int dim2) {
    c_void("set2i", [name, data, dim1, dim2] { MagicsCalls::set2i(name, data, dim1, dim2); });
}

MAGICS_EXPORT void mag_set1c(const char* name, const char** data, const int dim1) {
    c_void("set1c", [name, data, dim1] { MagicsCalls::set1c(name, data, dim1); });
}

MAGICS_EXPORT void mag_set3r(const char* name, const double* data, const int dim1, const int dim2, const int dim3) {
    c_void("set3r", [name, data, dim1, dim2, dim3] { MagicsCalls::set3r(name, data, dim1, dim2, dim3); });
}

MAGICS_EXPORT void mag_enqr(const char* name, double* value) {
    c_void("enqr", [name, value] { MagicsCalls::enqr(name, value); });
}

MAGICS_EXPORT void mag_enqi(const char* name, int* value) {
    c_void("enqi", [name, value] { MagicsCalls::enqi(name, value); });
}

MAGICS_EXPORT void mag_enqc(const char* name, char* value) {
    c_void("enqc", [name, value] { MagicsCalls::enqc(name, value); });
}

MAGICS_EXPORT void mag_add_warning_listener(void* data, void (*cb)(void*, const char*)) {
    c_void("add_warning_listener", [data, cb] { MagicsCalls::add_warning_listener(data, cb); });
}

MAGICS_EXPORT void mag_add_error_listener(void* data, void (*cb)(void*, const char*)) {
    c_void("add_error_listener", [data, cb] { MagicsCalls::add_error_listener(data, cb); });
}

MAGICS_EXPORT void mag_add_info_listener(void* data, void (*cb)(void*, const char*)) {
    c_void("add_info_listener", [data, cb] { MagicsCalls::add_info_listener(data, cb); });
}

MAGICS_EXPORT void mag_add_debug_listener(void* data, void (*cb)(void*, const char*)) {
   c_void("add_debug_listener", [data, cb] { MagicsCalls::add_debug_listener(data, cb); });
}

C_VOID(clear_listeners)



}  // end of extern "C"



#if 0

// =================================================================


extern "C" {



MAGICS_EXPORT void detect_(const char* data, char* dimension, int l1, int l2) {
    std::string sdata(data, l1);
    std::string sdim(dimension, l2);

    return magics_->detect(sdata, sdim);
}

/* **************************************************************************

***
***  C interface  ( calling Fortran 90 interface above )
***

****************************************************************************/
// FIXME: Not thread safe...



MAGICS_EXPORT void mag_open() {
    popen_();
}

MAGICS_EXPORT void mag_mute() {
    MagicsGlobal::silent(true);
}

MAGICS_EXPORT void mag_unmute() {
    MagicsGlobal::silent(false);
}

MAGICS_EXPORT void mag_set_python_context() {
    MagicsGlobal::compatibility(false);
}

MAGICS_EXPORT void mag_keep_compatibility() {
    MagicsGlobal::compatibility(true);
}

MAGICS_EXPORT int mag_close() {
    return pclose_();
}

MAGICS_EXPORT void mag_coast() {
    pcoast_();
}

MAGICS_EXPORT void mag_grib() {
    pgrib_();
}

MAGICS_EXPORT void mag_mapgen() {
    pmapgen_();
}

MAGICS_EXPORT void mag_line() {
    pline_();
}

MAGICS_EXPORT void mag_legend() {
    magics_->simplelegend();
}

MAGICS_EXPORT void mag_test() {
    ptest_();
}
MAGICS_EXPORT void mag_odb() {
    podb_();
}

MAGICS_EXPORT void mag_import() {
    pimport_();
}

MAGICS_EXPORT void mag_overlay() {
    poverlay_();
}

MAGICS_EXPORT void mag_netcdf() {
    pnetcdf_();
}

MAGICS_EXPORT void mag_cont() {
    pcont_();
}

MAGICS_EXPORT void mag_input() {
    pinput_();
}

MAGICS_EXPORT void mag_table() {
    ptable_();
}

MAGICS_EXPORT void mag_obs() {
    pobs_();
}




MAGICS_EXPORT void detect(const char* data, const char* dimension) {
    return magics_->detect(string(data), string(dimension));
}

MAGICS_EXPORT void mag_new(const char* page) {
    magics_->pnew(page);
}


MAGICS_EXPORT void mag_setc(const char* name, const char* value) {
    string n(name);
    string v(value);
    psetc_(n.c_str(), value, n.size(), v.size());
    // cout << "setc("<<name<<","<<value<<")"<<endl;
}


MAGICS_EXPORT void mag_setr(const char* name, const double value) {
    std::string n(name);

    if (CompatibilityHelper::check(n, value))
        return;

    ParameterManager::set(n, value);

}

MAGICS_EXPORT void mag_seti(const char* name, const int value) {
    string n(name);
    pseti_(name, &value, n.size());
    // cout << "seti("<<name<<","<<value<<")"<<endl;
}

MAGICS_EXPORT void mag_act(const char* a, const char* b, const char* c) {
    string aa(a);
    string bb(b);
    string cc(c);
    pact_(a, b, c, aa.size(), bb.size(), cc.size());
}


MAGICS_EXPORT void mag_set1r(const char* name, const double* data, const int dim1) {
    std::string n(name);
    floatarray values;
    for (int i = 0; i < dim1; i++)
        values.push_back(data[i]);

    try {
        if (CompatibilityHelper::check(n, values))
            return;
        ParameterManager::set(n, values);
    }
    catch (MagicsException& e) {
        MagLog::error() << e << "\n";
    }
}


MAGICS_EXPORT void mag_set2r(const char* name, const double* data, const int dim1, const int dim2) {
    string param(name);
    Matrix matrix;
    for (int i = 0; i < (dim2) * (dim1); i++) {
        matrix.push_back(data[i]);
    }

    matrix.set(dim2, dim1);

    try {
        if (CompatibilityHelper::check(param, matrix))
            return;
        ParameterManager::set(param, matrix);
    }
    catch (MagicsException& e) {
        MagLog::error() << e << "\n";
    }
    MagLog::dev() << "Parameter " << string(name) << " set to " << matrix << "\n";
}

MAGICS_EXPORT void mag_set3r(const char*, const double*, const int, const int, const int) {
    MagLog::warning() << "pset3r --> not yet implemented\n";
    if(MagicsGlobal::strict()) {
        NOTIMP;
    }
}


MAGICS_EXPORT void mag_set1i(const char* name, const int* data, const int dim1) {
    std::string param(name);
    intarray values;
    for (int i = 0; i < dim1; i++)
        values.push_back(data[i]);

    try {
        if (CompatibilityHelper::check(param, values))
            return;
        ParameterManager::set(param, values);
    }
    catch (MagicsException& e) {
        if(MagicsGlobal::strict()) {
            throw;
        }
        MagLog::error() << e << "\n";
    }
}


MAGICS_EXPORT void mag_set2i(const char* name, const int* data, const int dim1, const int dim2) {
    string param(name);
    Matrix matrix;
    for (int i = 0; i < (dim2) * (dim1); i++)
        matrix.push_back(data[i]);

    matrix.set(dim2, dim1);
    try {
        if (CompatibilityHelper::check(param, matrix))
            return;
        ParameterManager::set(param, matrix);
    }
    catch (MagicsException& e) {
        MagLog::error() << e << "\n";
    }
    MagLog::dev() << "Parameter " << param << " set to " << matrix << "\n";
}

MAGICS_EXPORT void mag_set3i(const char*, const int*, const int, const int, const int) {
    if(MagicsGlobal::strict()) {
        NOTIMP;
    }

    MagLog::warning() << "pset3i --> not yet implemented\n";
}

MAGICS_EXPORT void mag_set1c(const char* name, const char** data, const int dim) {
    string param(name);

    //	MagLog::dev() << "entry in the new mag_set1c\n";
    //	MagLog::dev() << "\tmag_set1c("  << dim << " entries);\n";
    stringarray values;

    for (int i = 0; i < dim; i++) {
        string work(data[i]);
        // remove the space at the start and end of the string

        string::size_type index1 = work.find_first_not_of(" ");
        string::size_type index2 = work.find_last_not_of(" ");
        string val = (index1 == string::npos || index2 == string::npos) ? "" : work.substr(index1, index2 + 1);
        values.push_back(val);
    }

    try {
        if (CompatibilityHelper::check(param, values))
            return;
        ParameterManager::set(param, values);
    }
    catch (MagicsException& e) {
        if(MagicsGlobal::strict()) {
                throw;
        }
        MagLog::error() << e << "\n";
    }
    // cout << "set1c("<<name<<","<<data[0]<<","<<dim<<")"<<endl;
}

MAGICS_EXPORT void mag_enqr(const char* fname, double* value) {
    string name(fname);
    vector<string> special;
    special.push_back("subpage_x_position");
    special.push_back("subpage_y_position");
    special.push_back("subpage_x_length");
    special.push_back("subpage_y_length");
    // parameters needs magics to get reday!

    string projection;

    ParameterManager::get("subpage_map_projection", projection);

    for (vector<string>::iterator param = special.begin(); param != special.end(); ++param) {
        if (magCompare(name, *param)) {
            double val;
            ParameterManager::get(name, val);
            if (!magCompare(projection, "cartesian")) {
                magics_->prepare();
                name = name + "_internal";
            }
        }
    }
    double magics;
    ParameterManager::get(name, magics);
    *value = magics;
    MagLog::dev() << "mag_enqr->" << name << " = " << magics << endl;
}

MAGICS_EXPORT void mag_enqi(const char* name, int* value) {
    int magics;
    ParameterManager::get(string(name), magics);
    *value = magics;
}

MAGICS_EXPORT void mag_enqc(const char* name, char* value) {
    string magics;

    if (magCompare(string(name), "magics_version")) {
        magics = getMagicsVersionString();
    }
    else
        ParameterManager::get(string(name), magics);

    strcpy(value, magics.c_str());
}

// TODO: add a try/catch
MAGICS_EXPORT void mag_add_warning_listener(void* data, void (*cb)(void*, const char*)) {
    MagLog::addWarningListener(data, cb);
}
MAGICS_EXPORT void mag_add_error_listener(void* data, void (*cb)(void*, const char*)) {
    MagLog::addErrorListener(data, cb);
}
MAGICS_EXPORT void mag_add_info_listener(void* data, void (*cb)(void*, const char*)) {
    MagLog::addInfoListener(data, cb);
}

MAGICS_EXPORT void mag_add_debug_listener(void* data, void (*cb)(void*, const char*)) {
    MagLog::addDebugListener(data, cb);
}

MAGICS_EXPORT void mag_clear_listeners() {
    MagLog::clearListeners();
}

MAGICS_EXPORT void mag_pie() {
    ppie_();
}

MAGICS_EXPORT void mag_graph() {
    pgraph_();
}

MAGICS_EXPORT void mag_axis() {
    paxis_();
}

MAGICS_EXPORT void mag_geo() {
    pgeo_();
}
MAGICS_EXPORT void mag_eps() {
    peps_();
}

MAGICS_EXPORT void mag_print() {
    pprint_();
}

MAGICS_EXPORT void mag_info() {
    MagLog::userInfo() << "INFO:\n"
                       << "INFO: " << getMagicsVersionString() << "\n"
                       << "INFO:\n"
                       << "INFO: Machine: " << getEnvVariable("HOSTNAME") << " is running " << getEnvVariable("VENDOR")
                       << " " << getEnvVariable("OSTYPE") << " " << getEnvVariable("MACHTYPE") << "\n"
                       << "INFO:\n"
                       << "INFO: $MAGPLUS_HOME    = " << getEnvVariable("MAGPLUS_HOME") << "\n"
                       << "INFO: $TMPDIR          = " << getEnvVariable("TMPDIR") << "\n"
                       << "INFO: $ODB_LIBS        = " << getEnvVariable("ODB_LIBS") << "\n"
                       << "INFO: $LD_LIBRARY_PATH = " << getEnvVariable("LD_LIBRARY_PATH") << "\n"
                       << "INFO:\n";
}

}  // end of extern "C"

#endif
