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
#include "MagException.h"
#include "MagicsCalls.h"
#include "magics.h"
#include "MagLog.h"

using namespace magics;

// =================================================================

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

template <class T>
int c_int(const char* name, T proc) {
    try {
        return proc();
    }
    catch (std::exception& e) {
        MagLog::error() << "EXCEPTION in mag_" << name << ": " << e.what() << std::endl;
    }
    catch (...) {
        MagLog::error() << "EXCEPTION in mag_" << name << ": unknown" << std::endl;
    }

    return -1;
}


extern "C" {


/* **************************************************************************

***
***  Fortran 77 interface
***

****************************************************************************/

static std::string fortran_string(const char* p, int len, bool lstrip = false) {
    std::string s(p, len);
    // remove the space at the start and end of the string
    string::size_type index1 = lstrip ? s.find_first_not_of(" ") : 0;
    string::size_type index2 = s.find_last_not_of(" ");
    return (index1 == string::npos || index2 == string::npos) ? "" : s.substr(index1, index2 + 1);
}

//================================================================

MAGICS_EXPORT void psetc_(const char* namep, const char* valuep, int namel, int valuel) {
    std::string name  = fortran_string(namep, namel);
    std::string value = fortran_string(valuep, valuel);
    c_void("setc", [name, value] { MagicsCalls::setc(name, value); });
}

MAGICS_EXPORT void pset1c_(const char* namep, const char* value, const int* dim, int namel, int valuel) {
    std::string name = fortran_string(namep, namel);
    stringarray values;
    for (int i = 0; i < *dim; i++) {
        values.push_back(fortran_string(value + i * valuel, valuel));
    }
    c_void("set1c", [name, values] { MagicsCalls::set1c(name, values); });
}

//================================================================

MAGICS_EXPORT void pseti_(const char* namep, const int* value, int namel) {
    std::string name = fortran_string(namep, namel);
    c_void("seti", [name, value] { MagicsCalls::seti(name, *value); });
}

MAGICS_EXPORT void pset1i_(const char* namep, const int* data, const int* dim, int namel) {
    std::string name = fortran_string(namep, namel);
    c_void("set1i", [name, data, dim] { MagicsCalls::set1i(name, data, *dim); });
}

MAGICS_EXPORT void pset2i_(const char* namep, const int* data, const int* dim1, const int* dim2, int namel) {
    std::string name = fortran_string(namep, namel);
    c_void("set2i", [name, data, dim1, dim2] { MagicsCalls::set2i(name, data, *dim1, *dim2); });
}

MAGICS_EXPORT void pset3i_(const char* namep, const int* data, const int* dim1, const int* dim2, const int* dim3,
                           int namel) {
    std::string name = fortran_string(namep, namel);
    c_void("set3i", [name, data, dim1, dim2, dim3] { MagicsCalls::set3i(name, data, *dim1, *dim2, *dim3); });
}

//================================================================
MAGICS_EXPORT void psetr_double(const char* namep, const double* value, int namel) {
    std::string name = fortran_string(namep, namel);
    c_void("setr", [name, value] { MagicsCalls::setr(name, *value); });
}

MAGICS_EXPORT void pset1r_double(const char* namep, const double* data, const int* dim, int namel) {
    std::string name = fortran_string(namep, namel);
    c_void("set1r", [name, data, dim] { MagicsCalls::set1r(name, data, *dim); });
}

MAGICS_EXPORT void pset2r_double(const char* namep, const double* data, const int* dim1, const int* dim2, int namel) {
    std::string name = fortran_string(namep, namel);
    c_void("set2r", [name, data, dim1, dim2] { MagicsCalls::set2r(name, data, *dim1, *dim2); });
}

MAGICS_EXPORT void pset3r_double(const char* namep, const double* data, const int* dim1, const int* dim2, const int* dim3,
                           int namel) {
    std::string name = fortran_string(namep, namel);
    c_void("set3r", [name, data, dim1, dim2, dim3] { MagicsCalls::set3r(name, data, *dim1, *dim2, *dim3); });
}

MAGICS_EXPORT void penqr_double(const char* namep, double* value, int namel) {
    std::string name = fortran_string(namep, namel);
    c_void("enqr", [name, value] { MagicsCalls::enqr(name, value); });
}

//================================================================

MAGICS_EXPORT void penqi_(const char* namep, int* value, int namel) {
    std::string name = fortran_string(namep, namel);
    c_void("enqi", [name, value] { MagicsCalls::enqi(name, value); });
}

MAGICS_EXPORT void penqc_(const char* namep, char* value, int namel, int vlength) {
    std::string name = fortran_string(namep, namel);
    c_void("enqc", [name, value] { MagicsCalls::enqc(name, value); });

    for (int i = strlen(value); i < vlength; i++)
        value[i] = ' ';
}

}  // end of extern "C"
