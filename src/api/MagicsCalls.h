/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

namespace magics {

class MagicsCalls {
public:
    static const char* known_drivers();
    static const char* meta_grib();
    static const char* meta_input();
    static const char* meta_netcdf();
    static const char* keep_compatibility();

    // =================================================================
    static void axis();
    static void boxplot();
    static int close();
    static void coast();
    static void cont();
    static void eps();
    static void epsbar();
    static void epscloud();
    static void epsgraph();
    static void epsinput();
    static void epslight();
    static void epsplumes();
    static void epsshading();
    static void epswave();
    static void epswind();
    static void geo();
    static void geojson();
    static void graph();
    static void grib();
    static void image();
    static void import();
    static void input();
    static void legend();
    static void line();
    static void mapgen();
    static void metbufr();
    static void metgraph();
    static void mute();
    static void netcdf();
    static void obs();
    static void odb();
    static void open();
    static void overlay();
    static void plot();
    static void print();
    static void raw();
    static void set_python();
    static void symb();
    static void table();
    static void taylor();
    static void tephi();
    static void text();
    static void tile();
    static void unmute();
    static void wind();
    static void wrepjson();
    static void info();

    static void page(const char* page);
    static void reset(const char* name);

    static void set(const char* name, const char* value);
    static void set(const char* name, int value);
    static void set(const char* name, double value);
    static void set(const char* name, const double* data, const int dim1);
    static void set(const char* name, const double* data, const int dim1, const int dim2);
    static void set(const char* name, const int* data, const int dim1);
    static void set(const char* name, const int* data, const int dim1, const int dim2);
    static void set(const char* name, const char** data, const int dim1);
};

}  // namespace magics
