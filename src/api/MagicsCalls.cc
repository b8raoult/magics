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

// #include <CompatibilityHelper.h>
#include "MagicsCalls.h"
#include "CompatibilityHelper.h"
#include "FortranMagics.h"

// #include <MagLog.h>
// #include <MagicsGlobal.h>
// #include <MagicsParameter.h>
// #include <WebFormat.h>

FortranMagics* magics_ = 0;


namespace magics {


const char* MagicsCalls::knowndrivers() {
    ASSERT(magics_);
    return magics_->knownDrivers();
}

const char* MagicsCalls::metagrib() {
    ASSERT(magics_);
    return magics_->metagrib();
}

const char* MagicsCalls::metainput() {
    ASSERT(magics_);
    return magics_->metainput();
}

const char* MagicsCalls::metanetcdf() {
    ASSERT(magics_);
    return magics_->metanetcdf();
}

const char* MagicsCalls::keep_compatibility() {
    NOTIMP;
}

// =================================================================
void MagicsCalls::axis() {
    ASSERT(magics_);
    magics_->paxis();
}

void MagicsCalls::boxplot() {
    ASSERT(magics_);
    magics_->pboxplot();
}

int MagicsCalls::close() {
    int code = magics_->pclose(false);
    delete magics_;
    magics_ = 0;
    return code;
}

void MagicsCalls::coast() {
    ASSERT(magics_);
    magics_->pcoast();
}

void MagicsCalls::cont() {
    ASSERT(magics_);
    magics_->pcont();
}

void MagicsCalls::eps() {
    NOTIMP;
}

void MagicsCalls::epsbar() {
    ASSERT(magics_);
    magics_->epsbar();
}

void MagicsCalls::epscloud() {
    ASSERT(magics_);
    magics_->epscloud();
}

void MagicsCalls::epsgraph() {
    ASSERT(magics_);
    magics_->epsgraph();
}

void MagicsCalls::epsinput() {
    ASSERT(magics_);
    magics_->epsinput();
}

void MagicsCalls::epslight() {
    ASSERT(magics_);
    magics_->epslight();
}

void MagicsCalls::epsplumes() {
    ASSERT(magics_);
    magics_->epsplumes();
}

void MagicsCalls::epsshading() {
    ASSERT(magics_);
    magics_->epsshading();
}

void MagicsCalls::epswave() {
    ASSERT(magics_);
    magics_->epswave();
}

void MagicsCalls::epswind() {
    ASSERT(magics_);
    magics_->epswind();
}

void MagicsCalls::geo() {
    ASSERT(magics_);
    magics_->pgeo();
}

void MagicsCalls::geojson() {
    NOTIMP;
}

void MagicsCalls::graph() {
    ASSERT(magics_);
    magics_->pgraph();
}

void MagicsCalls::grib() {
    ASSERT(magics_);
    magics_->pgrib();
}

void MagicsCalls::image() {
    ASSERT(magics_);
    magics_->pimage();
}

void MagicsCalls::import() {
    ASSERT(magics_);
    magics_->pimport();
}

void MagicsCalls::info() {
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

void MagicsCalls::input() {
    ASSERT(magics_);
    magics_->pinput();
}

void MagicsCalls::legend() {
    ASSERT(magics_);
    magics_->plegend();
}

void MagicsCalls::line() {
    ASSERT(magics_);
    magics_->pline();
}

void MagicsCalls::mapgen() {
    ASSERT(magics_);
    magics_->pmapgen();
}

void MagicsCalls::metbufr() {
    ASSERT(magics_);
    magics_->metbufr();
}

void MagicsCalls::metgraph() {
    ASSERT(magics_);
    magics_->metgraph();
}

void MagicsCalls::mute() {
    MagicsGlobal::silent(true);
}

void MagicsCalls::netcdf() {
    ASSERT(magics_);
    magics_->pnetcdf();
}

void MagicsCalls::obs() {
    ASSERT(magics_);
    magics_->pobs();
}

void MagicsCalls::odb() {
#ifdef HAVE_ODB
    ASSERT(magics_);
    magics_->podb();
#else
    if (MagicsGlobal::strict()) {
        throw NotSupported("ODB support is NOT enabled!");
    }
    MagLog::warning() << "ODB support is NOT enabled!\n";
#endif
}

void MagicsCalls::open() {
    delete magics_;
    magics_ = new FortranMagics();
    magics_->popen();
}

void MagicsCalls::overlay() {
    ASSERT(magics_);
    magics_->poverlay();
}

void MagicsCalls::plot() {
    NOTIMP;
}

void MagicsCalls::print() {
    NOTIMP;
}

void MagicsCalls::raw() {
    NOTIMP;
}

void MagicsCalls::set_python() {
    NOTIMP;
}

void MagicsCalls::symb() {
    ASSERT(magics_);
    magics_->psymb();
}

void MagicsCalls::table() {
    ASSERT(magics_);
    magics_->ptable();
}

void MagicsCalls::taylor() {
    ASSERT(magics_);
    magics_->ptaylor();
}

void MagicsCalls::tephi() {
    ASSERT(magics_);
    magics_->ptephi();
}

void MagicsCalls::text() {
    ASSERT(magics_);
    magics_->ptext();
}

void MagicsCalls::tile() {
    ASSERT(magics_);
    magics_->ptile();
}

void MagicsCalls::unmute() {
    MagicsGlobal::silent(false);
}

void MagicsCalls::wind() {
    ASSERT(magics_);
    magics_->pwind();
}

void MagicsCalls::wrepjson() {
    ASSERT(magics_);
    magics_->wrepjson();
}

void MagicsCalls::page(const std::string& page) {
    ASSERT(magics_);
    magics_->pnew(page);
}

void MagicsCalls::reset(const std::string& name) {
    CompatibilityHelper::reset(name);
    ParameterManager::reset(name);
}

void MagicsCalls::setc(const std::string& name, const std::string& value) {
    if (CompatibilityHelper::check(name, value))
        return;
    ParameterManager::set(name, value);
}

void MagicsCalls::setc(const std::string& name, const char* value) {
    ASSERT(value);
    setc(name, std::string(value));
}

void MagicsCalls::seti(const std::string& name, int value) {
    if (CompatibilityHelper::check(name, value))
        return;
    ParameterManager::set(name, value);
}

void MagicsCalls::setr(const std::string& name, double value) {
    if (CompatibilityHelper::check(name, value))
        return;
    ParameterManager::set(name, value);
}

void MagicsCalls::set1r(const std::string& name, const double* data, const int dim1) {
    ASSERT(data);

    floatarray values;
    for (int i = 0; i < dim1; i++) {
        values.push_back(data[i]);
    }

    if (CompatibilityHelper::check(name, values))
        return;

    ParameterManager::set(name, values);
}

void MagicsCalls::set2r(const std::string& name, const double* data, const int dim1, const int dim2) {
    ASSERT(data);

    Matrix matrix;
    for (int i = 0; i < dim2 * dim1; i++) {
        matrix.push_back(data[i]);
    }

    matrix.set(dim2, dim1);

    if (CompatibilityHelper::check(name, matrix))
        return;

    ParameterManager::set(name, matrix);

    MagLog::dev() << "Parameter " << name << " set to " << matrix << "\n";
}

void MagicsCalls::set1i(const std::string& name, const int* data, const int dim1) {
    ASSERT(data);

    intarray values;
    for (int i = 0; i < dim1; i++) {
        values.push_back(data[i]);
    }

    if (CompatibilityHelper::check(name, values))
        return;

    ParameterManager::set(name, values);
}

void MagicsCalls::set2i(const std::string& name, const int* data, const int dim1, const int dim2) {
    ASSERT(data);

    Matrix matrix;
    for (int i = 0; i < dim2 * dim1; i++) {
        matrix.push_back(data[i]);
    }

    matrix.set(dim2, dim1);

    if (CompatibilityHelper::check(name, matrix))
        return;

    ParameterManager::set(name, matrix);

    MagLog::dev() << "Parameter " << name << " set to " << matrix << "\n";
}

void MagicsCalls::set3i(const std::string& name, const int* data, const int dim1, const int dim2, const int dim3) {
    NOTIMP;
}


void MagicsCalls::set1c(const std::string& name, const char** data, const int dim) {
    ASSERT(data);

    //	MagLog::dev() << "entry in the new mag_set1c\n";
    //	MagLog::dev() << "\tmag_set1c("  << dim << " entries);\n";
    stringarray values;

    for (int i = 0; i < dim; i++) {
        ASSERT(data[i]);
        values.push_back(data[i]);
    }

    set1c(name, values);
}

void MagicsCalls::set3r(const std::string& name, const double* data, const int dim1, const int dim2, const int dim3) {
    NOTIMP;
}


void MagicsCalls::enqr(const std::string& n, double* value) {

    std::string name = n;

    ASSERT(value);

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
                ASSERT(magics_);
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

void MagicsCalls::enqi(const std::string& name, int* value) {
    ASSERT(value);

    int magics;
    ParameterManager::get(name, magics);
    *value = magics;
}

void MagicsCalls::enqc(const std::string& name, char* value) {
    ASSERT(value);

    string magics;

    if (magCompare(name, "magics_version")) {
        magics = getMagicsVersionString();
    }
    else
        ParameterManager::get(name, magics);

    strcpy(value, magics.c_str());
}


void MagicsCalls::set1c(const std::string& name, const std::vector<std::string>& values) {
    if (CompatibilityHelper::check(name, values))
        return;

    ParameterManager::set(name, values);
}

void MagicsCalls::add_warning_listener(void* data, void (*cb)(void*, const char*)) {
    MagLog::addWarningListener(data, cb);
}
void MagicsCalls::add_error_listener(void* data, void (*cb)(void*, const char*)) {
    MagLog::addErrorListener(data, cb);
}
void MagicsCalls::add_info_listener(void* data, void (*cb)(void*, const char*)) {
    MagLog::addInfoListener(data, cb);
}

void MagicsCalls::add_debug_listener(void* data, void (*cb)(void*, const char*)) {
    MagLog::addDebugListener(data, cb);
}

void MagicsCalls::clear_listeners() {
    MagLog::clearListeners();
}

const char* MagicsCalls::version() {
    static string version = getMagicsVersionString();
    return version.c_str();
}

const char* MagicsCalls::home() {
    static string home = getEnvVariable("MAGPLUS_HOME");
    return home.c_str();
}


}  // namespace magics

#if 0



MAGICS_EXPORT void presets_() {
    ParameterManager::reset();
}

MAGICS_EXPORT void preset_(const std::string& name, int length) {
    std::string n(name, length);
    CompatibilityHelper::reset(n);
    mag_reset(n.c_str());
}


MAGICS_EXPORT void penqi_(const std::string& name, int* value, int length) {
    std::string n(name, length);
    mag_enqi(n.c_str(), value);
}

MAGICS_EXPORT void penqc_(const std::string& name, char* value, int length, int vlength) {
    std::string n(name, length);
    mag_enqc(n.c_str(), value);

    for (int i = strlen(value); i < vlength; i++)
        value[i] = ' ';
}

MAGICS_EXPORT const char* detect_(const char* data, char* dimension, int l1, int l2) {
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




MAGICS_EXPORT const char* detect(const char* data, const char* dimension) {
    return magics_->detect(string(data), string(dimension));
}




}

}  // end of extern "C"

#endif
