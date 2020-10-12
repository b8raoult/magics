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
#include "py_calls.h"

extern "C" {
#include <magics_api.h>
}


#define PYTHON_VOID(python, magics) \
    MAGICS_EXPORT const char* python() { return python_1(#python, magics); }
#define PYTHON_CHAR(python, magics) \
    MAGICS_EXPORT const char* python() { return python_2(#python, magics); }


static std::string _last_error;

static void last_error(const std::string& error) {
    _last_error = error;
}

static void last_error(std::exception& e) {
    last_error(e.what());
}

static void clear_error() {
    last_error("");
}

static const char* last_error() {
    return _last_error.size() ? _last_error.c_str() : nullptr;
}

template <class T>
const char* python_1(const char* name, T proc) {
    clear_error();
    try {
        proc();
    }
    catch (std::exception& e) {
        last_error(e);
        std::cout << "EXCEPTION in " << name << ": " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "EXCEPTION in " << name << ": unknown" << std::endl;
        last_error("Unknown exception");
    }
    return last_error();
}

template <class T>
const char* python_2(const char* name, T proc) {
    clear_error();

    try {
        return proc();
    }
    catch (std::exception& e) {
        last_error(e);
        std::cout << "EXCEPTION in " << name << ": " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "EXCEPTION in " << name << ": unknown" << std::endl;
        last_error("Unknown exception");
    }

    return nullptr;
}


extern "C" {


MAGICS_EXPORT const char* knowndrivers_();
MAGICS_EXPORT const char* metagrib_();
MAGICS_EXPORT const char* metainput_();
MAGICS_EXPORT const char* metanetcdf_();
MAGICS_EXPORT void mag_keep_compatibility();
MAGICS_EXPORT void mag_legend();
MAGICS_EXPORT void mag_mute();
MAGICS_EXPORT void mag_set_python_context();
MAGICS_EXPORT void mag_unmute();
MAGICS_EXPORT void paxis_();
MAGICS_EXPORT void pboxplot_();
MAGICS_EXPORT void pclose_();
MAGICS_EXPORT void pcoast_();
MAGICS_EXPORT void pcont_();
MAGICS_EXPORT void peps_();
MAGICS_EXPORT void pepsbar_();
MAGICS_EXPORT void pepscloud_();
MAGICS_EXPORT void pepsgraph_();
MAGICS_EXPORT void pepsinput_();
MAGICS_EXPORT void pepslight_();
MAGICS_EXPORT void pepsplumes_();
MAGICS_EXPORT void pepsshading_();
MAGICS_EXPORT void pepswave_();
MAGICS_EXPORT void pepswind_();
MAGICS_EXPORT void pgeo_();
MAGICS_EXPORT void pgeojson_();
MAGICS_EXPORT void pgraph_();
MAGICS_EXPORT void pgrib_();
MAGICS_EXPORT void pimage_();
MAGICS_EXPORT void pimport_();
MAGICS_EXPORT void pinput_();
MAGICS_EXPORT void pline_();
MAGICS_EXPORT void pmapgen_();
MAGICS_EXPORT void pmetbufr_();
MAGICS_EXPORT void pmetgraph_();
MAGICS_EXPORT void pnetcdf_();
MAGICS_EXPORT void pobs_();
MAGICS_EXPORT void podb_();
MAGICS_EXPORT void popen_();
MAGICS_EXPORT void poverlay_();
MAGICS_EXPORT void pplot_();
MAGICS_EXPORT void pprint_();
MAGICS_EXPORT void praw_();
MAGICS_EXPORT void psymb_();
MAGICS_EXPORT void ptable_();
MAGICS_EXPORT void ptaylor_();
MAGICS_EXPORT void ptephi_();
MAGICS_EXPORT void ptext_();
MAGICS_EXPORT void ptile_();
MAGICS_EXPORT void pwind_();
MAGICS_EXPORT void pwrepjson_();

MAGICS_EXPORT const char* magics_last_error() {
    return last_error();
}

#define PYTHON_VOID(python, magics) \
    MAGICS_EXPORT const char* python() { return python_1(#python, magics); }

#define PYTHON_CHAR(python, magics) \
    MAGICS_EXPORT const char* python() { return python_2(#python, magics); }


PYTHON_VOID(py_axis, paxis_)
PYTHON_VOID(py_boxplot, pboxplot_)
PYTHON_VOID(py_close, pclose_)
PYTHON_VOID(py_coast, pcoast_)
PYTHON_VOID(py_cont, pcont_)
PYTHON_VOID(py_eps, peps_)
PYTHON_VOID(py_epsbar, pepsbar_)
PYTHON_VOID(py_epscloud, pepscloud_)
PYTHON_VOID(py_epsgraph, pepsgraph_)
PYTHON_VOID(py_epsinput, pepsinput_)
PYTHON_VOID(py_epslight, pepslight_)
PYTHON_VOID(py_epsplumes, pepsplumes_)
PYTHON_VOID(py_epsshading, pepsshading_)
PYTHON_VOID(py_epswave, pepswave_)
PYTHON_VOID(py_epswind, pepswind_)
PYTHON_VOID(py_geo, pgeo_)
PYTHON_VOID(py_geojson, pgeojson_)
PYTHON_VOID(py_graph, pgraph_)
PYTHON_VOID(py_grib, pgrib_)
PYTHON_VOID(py_image, pimage_)
PYTHON_VOID(py_import, pimport_)
PYTHON_VOID(py_info, mag_info)
PYTHON_VOID(py_input, pinput_)
PYTHON_VOID(py_keep_compatibility, mag_keep_compatibility)
PYTHON_VOID(py_legend, mag_legend)
PYTHON_VOID(py_line, pline_)
PYTHON_VOID(py_mapgen, pmapgen_)
PYTHON_VOID(py_metbufr, pmetbufr_)
PYTHON_VOID(py_metgraph, pmetgraph_)
PYTHON_VOID(py_mute, mag_mute)
PYTHON_VOID(py_netcdf, pnetcdf_)
PYTHON_VOID(py_obs, pobs_)
PYTHON_VOID(py_odb, podb_)
PYTHON_VOID(py_open, popen_)
PYTHON_VOID(py_overlay, poverlay_)
PYTHON_VOID(py_plot, pplot_)
PYTHON_VOID(py_print, pprint_)
PYTHON_VOID(py_raw, praw_)
PYTHON_VOID(py_set_python, mag_set_python_context)
PYTHON_VOID(py_symb, psymb_)
PYTHON_VOID(py_table, ptable_)
PYTHON_VOID(py_taylor, ptaylor_)
PYTHON_VOID(py_tephi, ptephi_)
PYTHON_VOID(py_text, ptext_)
PYTHON_VOID(py_tile, ptile_)
PYTHON_VOID(py_unmute, mag_unmute)
PYTHON_VOID(py_wind, pwind_)
PYTHON_VOID(py_wrepjson, pwrepjson_)

PYTHON_CHAR(py_knowndrivers, knowndrivers_)
PYTHON_CHAR(py_metagrib, metagrib_)
PYTHON_CHAR(py_metainput, metainput_)
PYTHON_CHAR(py_metanetcdf, metanetcdf_)

MAGICS_EXPORT const char* py_new(const char* page) {
    try {
        mag_new(page);
    }
    catch (std::exception& e) {
        std::cout << "EXCEPTION in py_new: " << e.what() << std::endl;
        last_error(e);
    }
    catch (...) {
        std::cout << "EXCEPTION in py_new: unknown" << std::endl;
        last_error("Unknown exception");
    }
    return last_error();
}

MAGICS_EXPORT const char* py_reset(const char* name) {
    try {
        mag_reset(name);
    }
    catch (std::exception& e) {
        std::cout << "EXCEPTION in py_reset: " << e.what() << std::endl;
        last_error(e);
    }
    catch (...) {
        std::cout << "EXCEPTION in py_reset: unknown" << std::endl;
        last_error("Unknown exception");
    }
    return last_error();
}

MAGICS_EXPORT const char* py_setc(const char* name, const char* value) {
    try {
        mag_setc(name, value);
    }
    catch (std::exception& e) {
        std::cout << "EXCEPTION in py_setc: " << e.what() << std::endl;
        last_error(e);
    }
    catch (...) {
        std::cout << "EXCEPTION in py_setc: unknown" << std::endl;
        last_error("Unknown exception");
    }
    return last_error();
}

MAGICS_EXPORT const char* py_setr(const char* name, const double value) {
    try {
        mag_setr(name, value);
    }
    catch (std::exception& e) {
        std::cout << "EXCEPTION in py_setr: " << e.what() << std::endl;
        last_error(e);
    }
    catch (...) {
        std::cout << "EXCEPTION in py_setr: unknown" << std::endl;
        last_error("Unknown exception");
    }
    return last_error();
}


MAGICS_EXPORT const char* py_seti(const char* name, const int value) {
    try {
        mag_seti(name, value);
    }
    catch (std::exception& e) {
        std::cout << "EXCEPTION in py_seti: " << e.what() << std::endl;
        last_error(e);
    }
    catch (...) {
        std::cout << "EXCEPTION in py_seti: unknown" << std::endl;
        last_error("Unknown exception");
    }
    return last_error();
}


MAGICS_EXPORT const char* py_set1r(const char* name, const double* data, const int dim1) {
    try {
        mag_set1r(name, data, dim1);
    }
    catch (std::exception& e) {
        std::cout << "EXCEPTION in py_set1r: " << e.what() << std::endl;
        last_error(e);
    }
    catch (...) {
        std::cout << "EXCEPTION in py_set1r: unknown" << std::endl;
        last_error("Unknown exception");
    }
    return last_error();
}


MAGICS_EXPORT const char* py_set2r(const char* name, const double* data, const int dim1, const int dim2) {
    try {
        mag_set2r(name, data, dim1, dim2);
    }
    catch (std::exception& e) {
        std::cout << "EXCEPTION in py_set2r: " << e.what() << std::endl;
        last_error(e);
    }
    catch (...) {
        std::cout << "EXCEPTION in py_set2r: unknown" << std::endl;
        last_error("Unknown exception");
    }
    return last_error();
}

MAGICS_EXPORT const char* py_set1i(const char* name, const int* data, const int dim1) {
    try {
        mag_set1i(name, data, dim1);
    }
    catch (std::exception& e) {
        std::cout << "EXCEPTION in py_set1i: " << e.what() << std::endl;
        last_error(e);
    }
    catch (...) {
        std::cout << "EXCEPTION in py_set1i: unknown" << std::endl;
        last_error("Unknown exception");
    }
    return last_error();
}

MAGICS_EXPORT const char* py_set2i(const char* name, const int* data, const int dim1, const int dim2) {
    try {
        mag_set2i(name, data, dim1, dim2);
    }
    catch (std::exception& e) {
        std::cout << "EXCEPTION in py_set2i: " << e.what() << std::endl;
        last_error(e);
    }
    catch (...) {
        std::cout << "EXCEPTION in py_set2i: unknown" << std::endl;
        last_error("Unknown exception");
    }
    return last_error();
}


MAGICS_EXPORT const char* py_set1c(const char* name, const char** data, const int dim1) {
    try {
        mag_set1c(name, data, dim1);
    }
    catch (std::exception& e) {
        std::cout << "EXCEPTION in py_set1c: " << e.what() << std::endl;
        last_error(e);
    }
    catch (...) {
        std::cout << "EXCEPTION in py_set1c: unknown" << std::endl;
        last_error("Unknown exception");
    }
    return last_error();
}


}  // end of extern "C"
