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

#if 0
extern "C" {
#include <magics_api.h>
}

extern FortranMagics* magics_;



// =================================================================


extern "C" {


/* **************************************************************************

***
***  Fortran 77 interface
***

****************************************************************************/

MAGICS_EXPORT void popen_() {
    delete magics_;
    // if (magics_ == 0)
    magics_ = new FortranMagics();
    magics_->popen();
}

MAGICS_EXPORT void pcoast_() {
    magics_->pcoast();
}

MAGICS_EXPORT void ptaylor_() {
    magics_->ptaylor();
}

MAGICS_EXPORT void ptephi_() {
    magics_->ptephi();
}

MAGICS_EXPORT void pgrib_() {
    magics_->pgrib();
}

MAGICS_EXPORT const char* metagrib_() {
    return magics_->metagrib();
}

MAGICS_EXPORT const char* knowndrivers_() {
    return magics_->knownDrivers();
}

MAGICS_EXPORT const char* version() {
    static string version = getMagicsVersionString();
    return version.c_str();
}

MAGICS_EXPORT const char* home() {
    static string home = getEnvVariable("MAGPLUS_HOME");
    return home.c_str();
}

MAGICS_EXPORT const char* metanetcdf_() {
    return magics_->metanetcdf();
}

MAGICS_EXPORT const char* metainput_() {
    return magics_->metainput();
}

MAGICS_EXPORT void pmapgen_() {
    magics_->pmapgen();
}

MAGICS_EXPORT void ptest_() {
    magics_->ptest();
}

MAGICS_EXPORT void podb_() {
#ifdef HAVE_ODB
    magics_->podb();
#else
    if(MagicsGlobal::strict()) {
        throw NotSupported("ODB support is NOT enabled!");
    }
    MagLog::warning() << "ODB support is NOT enabled!\n";
#endif
}

MAGICS_EXPORT void pimport_() {
    magics_->pimport();
}

MAGICS_EXPORT void poverlay_() {
    magics_->poverlay();
}

MAGICS_EXPORT void pnetcdf_() {
    magics_->pnetcdf();
}

MAGICS_EXPORT void pcont_() {
    magics_->pcont();
}

MAGICS_EXPORT void pobs_() {
    magics_->pobs();
}

MAGICS_EXPORT void praw_() {
#ifdef MAGICS_NETPBM
    MagLog::warning() << "praw->not implemented\n";
    if(MagicsGlobal::strict()) {
        NOTIMP;
    }
#else
    if(MagicsGlobal::strict()) {
        throw NotSupported("Netpbm NOT supported!");
    }

    MagLog::warning() << "Netpbm NOT supported!" << endl;
#endif
}

MAGICS_EXPORT void pimage_() {
    magics_->pimage();
}

MAGICS_EXPORT void pplot_() {
    MagLog::warning() << "pplot has no effect ... use pimport instead" << endl;
}

MAGICS_EXPORT void pnew_(const char* name, int length) {
    std::string n(name, length);
    mag_new(n.c_str());
}

MAGICS_EXPORT void ptext_() {
    magics_->ptext();
}

MAGICS_EXPORT void pwind_() {
    magics_->pwind();
}

MAGICS_EXPORT void pline_() {
    magics_->pline();
}

MAGICS_EXPORT void psymb_() {
    magics_->psymb();
}

MAGICS_EXPORT int pclose_() {
    int code = magics_->pclose(false);

    delete magics_;
    magics_ = 0;
    return code;
}

MAGICS_EXPORT void pact_(const char*, const char*, const char*, int, int, int) {
    MagLog::dev() << "PACT will NOT be implemented!\n";
}

MAGICS_EXPORT void presets_() {
    ParameterManager::reset();
}

MAGICS_EXPORT void preset_(const char* name, int length) {
    std::string n(name, length);
    CompatibilityHelper::reset(n);
    mag_reset(n.c_str());
}

MAGICS_EXPORT void psetc_(const char* name, const char* value, int namel, int valuel) {
    try {
        string val              = string(value, valuel);
        string::size_type index = val.find_last_not_of(" ");
        val                     = (index == string::npos) ? "" : val.substr(0, index + 1);
        if (CompatibilityHelper::check(string(name, namel), val))
            return;
        ParameterManager::set(string(name, namel), val);
    }
    catch (MagicsException& e) {
        if(MagicsGlobal::strict()) {
            throw;
        }
        MagLog::error() << e << "\n";
    }
}

MAGICS_EXPORT void pseti_(const char* name, const int* value, int namel) {
    try {
        if (CompatibilityHelper::check(string(name, namel), int(*value)))
            return;
        ParameterManager::set(string(name, namel), int(*value));
    }
    catch (MagicsException& e) {
        if(MagicsGlobal::strict()) {
            throw;
        }
        MagLog::error() << e << "\n";
    }
}

MAGICS_EXPORT void pset1i_(const char* name, const int* data, const int* dim, int length) {
    std::string n(name, length);
    try {
        mag_set1i(n.c_str(), data, *dim);
    }
    catch (MagicsException& e) {
        if(MagicsGlobal::strict()) {
            throw;
        }
        MagLog::error() << e << "\n";
    }
}

MAGICS_EXPORT void pset2i_(const char* name, const int* data, const int* dim1, const int* dim2, int length) {
    std::string n(name, length);
    try {
        mag_set2i(n.c_str(), data, *dim1, *dim2);
    }
    catch (MagicsException& e) {
        if(MagicsGlobal::strict()) {
            throw;
        }
        MagLog::error() << e << "\n";
    }
}

MAGICS_EXPORT void pset3i_(const char* name, const int* data, const int* dim, const int* dim2, const int* dim3,
                           int length) {
    std::string n(name, length);
    mag_set3i(n.c_str(), data, *dim, *dim2, *dim3);
}

MAGICS_EXPORT void pset1c_(const char* name, const char* value, const int* dim, int namel, int l) {
    stringarray values;
    string work(value, (*dim) * l);
    int first = 0;
    for (int i = 0; i < *dim; i++) {
        // remove the  space at the end of the string
        string val = work.substr(first, l);

        string::size_type index = val.find_last_not_of(" ");
        if (index == string::npos)
            values.push_back("");
        else
            values.push_back(val.substr(0, index + 1));
        first += l;
    }

    try {
        string n(name, namel);
        if (CompatibilityHelper::check(n, values))
            return;
        ParameterManager::set(n, values);
    }
    catch (MagicsException& e) {

        if(MagicsGlobal::strict()) {
            throw;
        }

        MagLog::error() << e << "\n";
    }
}

MAGICS_EXPORT void penqi_(const char* name, int* value, int length) {
    std::string n(name, length);
    mag_enqi(n.c_str(), value);
}

MAGICS_EXPORT void penqc_(const char* name, char* value, int length, int vlength) {
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

MAGICS_EXPORT void ppie_() {
    MagLog::warning() << "ppie-> is deprecated and will NOT be implemented.\n";
}

MAGICS_EXPORT void pgraph_() {
    magics_->pgraph();
}

MAGICS_EXPORT void paxis_() {
    magics_->paxis();
}

MAGICS_EXPORT void pgeo_() {
    magics_->pgeo();
}

MAGICS_EXPORT void pinput_() {
    magics_->pinput();
}

MAGICS_EXPORT void ptable_() {
    magics_->ptable();
}

MAGICS_EXPORT void peps_() {
    MagLog::warning() << "peps-->not yet implemented\n";
}

MAGICS_EXPORT void pboxplot_() {
    magics_->pboxplot();
}

MAGICS_EXPORT void ptile_() {
    magics_->ptile();
}

MAGICS_EXPORT void pwrepjson_() {
    magics_->wrepjson();
}

MAGICS_EXPORT void pgeojson_() {
    magics_->geojson();
}

MAGICS_EXPORT void pepsinput_() {
    magics_->epsinput();
}

MAGICS_EXPORT void pmetgraph_() {
    magics_->metgraph();
}

MAGICS_EXPORT void pmetbufr_() {
    magics_->metbufr();
}

MAGICS_EXPORT void pepscloud_() {
    magics_->epscloud();
}

MAGICS_EXPORT void pepsplumes_() {
    magics_->epsplumes();
}

MAGICS_EXPORT void pepsgraph_() {
    magics_->epsgraph();
}

MAGICS_EXPORT void pepslight_() {
    magics_->epslight();
}

MAGICS_EXPORT void pepswave_() {
    magics_->epswave();
}

MAGICS_EXPORT void pepswind_() {
    magics_->epswind();
}

MAGICS_EXPORT void pepsbar_() {
    magics_->epsbar();
}

MAGICS_EXPORT void pepsshading_() {
    magics_->epsshading();
}

MAGICS_EXPORT void pprint_() {
    MagLog::warning() << "pprint-->not yet implemented\n";
}

MAGICS_EXPORT void pinfo_() {
    mag_info();
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

MAGICS_EXPORT void mag_raw() {
    praw_();
}

MAGICS_EXPORT void mag_image() {
    pimage_();
}

MAGICS_EXPORT void mag_plot() {
    pplot_();
}

MAGICS_EXPORT void mag_text() {
    ptext_();
}

MAGICS_EXPORT void mag_wind() {
    pwind_();
}

MAGICS_EXPORT void mag_symb() {
    psymb_();
}

MAGICS_EXPORT void mag_boxplot() {
    pboxplot_();
}

MAGICS_EXPORT void mag_taylor() {
    ptaylor_();
}
MAGICS_EXPORT void mag_tile() {
    ptile_();
}

MAGICS_EXPORT void mag_tephi() {
    ptephi_();
}

MAGICS_EXPORT void mag_geojson() {
    pgeojson_();
}

MAGICS_EXPORT void mag_wrepjson() {
    pwrepjson_();
}

MAGICS_EXPORT void mag_epsinput() {
    pepsinput_();
}

MAGICS_EXPORT void mag_epscloud() {
    pepscloud_();
}

MAGICS_EXPORT void mag_metgraph() {
    pmetgraph_();
}

MAGICS_EXPORT void mag_metbufr() {
    pmetbufr_();
}


MAGICS_EXPORT void mag_epsgraph() {
    pepsgraph_();
}

MAGICS_EXPORT void mag_epswave() {
    pepswave_();
}

MAGICS_EXPORT void mag_epswind() {
    pepswind_();
}
MAGICS_EXPORT void mag_epsbar() {
    pepsbar_();
}

MAGICS_EXPORT void mag_epsshading() {
    pepsshading_();
}

MAGICS_EXPORT void mag_epsplumes() {
    pepsplumes_();
}

MAGICS_EXPORT void mag_epslight() {
    pepslight_();
}

MAGICS_EXPORT const char* detect(const char* data, const char* dimension) {
    return magics_->detect(string(data), string(dimension));
}

MAGICS_EXPORT void mag_new(const char* page) {
    magics_->pnew(page);
}

MAGICS_EXPORT void mag_reset(const char* name) {
    ParameterManager::reset(name);
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
