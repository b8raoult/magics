/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include <fstream>

#include "magics.h"
#include "py_calls.h"
#include "MagException.h"

using namespace magics;

int main(int argc, char** argv) {

    char line[10240];

    try {
        ASSERT(argc == 2);
        ifstream in(argv[1]);
        if(!in) {
            throw CannotOpenFile(argv[1]);
        }

        while(in.getline(line, sizeof(line))) {
            std::cout << line << std::endl;
        }

    }
    catch(std::exception& e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }

    exit(0);
}
