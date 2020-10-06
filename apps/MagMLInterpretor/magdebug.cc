/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include "MagYaml.h"

using namespace magics;

int main(int argc, char** argv) {
    try {
        for(int i = 1; i < argc; i++){
            MagYaml::processFile(argv[i]);
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }

    exit(0);
}
