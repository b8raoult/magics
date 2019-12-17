/******************************** LICENSE ********************************

 Copyright 2007 European Centre for Medium-Range Weather Forecasts (ECMWF)

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

 ******************************** LICENSE ********************************/

/* \file drivers.c

   \brief test if the different output drivers work in C
*/

#include <magics_api.h>

int main() {
    const char* formats[] = {"svg", "kml", "ps", "pdf", "png"};
    const int num         = 5;

    /* open magics and set the output device */
    mag_open();
    mag_set1c("output_formats", formats, num);
    mag_setc("output_name", "driver_test");
    mag_coast();

    mag_close();

    return 0;
}
