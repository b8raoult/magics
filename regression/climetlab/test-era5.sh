#!/bin/bash

set -e
if [[ ! -f era5.grib ]]
then
    python3 ./get-era5.py
    cat era5-pl.grib era5-sfc.grib > era5.grib
    rm -f era5-pl.grib era5-sfc.grib
fi

export MAGPLUS_HOME=../..

for i in $(seq $(grib_count era5.grib))
do
if [[ $i -eq 28 || $i -eq 31 || $i == 207 ]]
then
continue
fi
p=$i
png=$(printf "era5-%04d.png" $i)

if [[ -f $png ]]
then
    continue
fi

cat<<EOF >tmp.yaml
plot:
    - output:
        output_formats:
            - png
        output_name: tmp
        output_name_first_page_number: false
    - mgrib:
        grib_field_position: $p
        grib_input_file_name: era5.grib
    - mcont:
        contour_automatic_setting: climetlab
        legend: false
EOF

~/build/magics-b8raoult/bin/magics tmp.yaml
mv tmp.png $png

done
