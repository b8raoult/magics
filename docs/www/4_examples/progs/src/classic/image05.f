C (C) Copyright 1996-2016 ECMWF.
C 
C This software is licensed under the terms of the Apache Licence Version 2.0
C which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
C In applying this licence, ECMWF does not waive the privileges and immunities 
C granted to it by virtue of its status as an intergovernmental organisation nor
C does it submit to any jurisdiction.
C

	PROGRAM IMAG05
C
C	PLOT AN IMAGE WITH COMPUTED COLOUR TABLE
C

	CALL POPEN
	CALL PSETC ('PS_DEVICE','ps_a4')
	CALL PSETC ('PS_FILE_NAME','image05.ps')
	CALL PSETC ('PAGE_ID_LINE_USER_TEXT','Tests/imag05')     
C
C	DEFINE POLAR STEREOGRAPHIC PROJECTION
C
	CALL PSETC ('IMAGE_SUBAREA_SELECTION','ON')                   
	CALL PSETC ('SUBPAGE_MAP_PROJECTION', 'INPUT_IMAGE')
	CALL PSETR ('SUBPAGE_MAP_CORNER_LONGITUDE', 50.0) 
	CALL PSETR ('SUBPAGE_MAP_CORNER_LATITUDE', 70.0) 
	CALL PSETR ('SUBPAGE_MAP_CENTRE_LONGITUDE', 0.0) 
	CALL PSETR ('SUBPAGE_MAP_CENTRE_LATITUDE', 40.0) 
C
C	PASS GRIB FILE WITH IMAGE
C
	CALL PSETC ('GRIB_INPUT_TYPE', 'FILE')
	CALL PSETC ('GRIB_INPUT_FILE_NAME','data/oldts/im96011000.img')
	CALL PGRIB
C
C	DEFINE COMPUTATION OF COLOUR TABLE
C
	CALL PSETC ('IMAGE_COLOUR_TABLE_CREATION_MODE', 'EQUIDISTANT')
	CALL PSETC ('IMAGE_MIN_LEVEL_COLOUR', 'GREEN')
	CALL PSETC ('IMAGE_MAX_LEVEL_COLOUR', 'PURPLE')
	CALL PSETC ('IMAGE_LEGEND','ON')
	CALL PSETC ('IMAGE_LEGEND_BOX_BLANKING', 'ON')
C
C	PLOT THE IMAGE
C
	CALL PIMAGE
C
C	PLOT COASTLINES AND TITLE
C
	CALL PSETC ('MAP_COASTLINE_COLOUR','BLACK')
	CALL PSETC ('MAP_GRID_COLOUR','BLACK')
	CALL PCOAST
	CALL PSETC ('TEXT_JUSTIFICATION','CENTRE')
	CALL PSETC ('TEXT_LINE_1','Image on Selected Satellite Subarea ')
	CALL PSETC ('TEXT_LINE_2','with Computed Colour Table')
	CALL PSETI ('TEXT_LINE_COUNT',2)
	CALL PTEXT
C
C	CLOSE MAGICS
C
	CALL PCLOSE
	STOP
	END
