C (C) Copyright 1996-2016 ECMWF.
C 
C This software is licensed under the terms of the Apache Licence Version 2.0
C which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
C In applying this licence, ECMWF does not waive the privileges and immunities 
C granted to it by virtue of its status as an intergovernmental organisation nor
C does it submit to any jurisdiction.
C

      PROGRAM WIND04
*
*     THIS PROGRAM DEMONSTRATES MAGICS WIND FIELD AND CONTOUR 
*     PLOTTING FACILITIES.
*
*     WIND ARROWS AND COASTLINES ARE PROJECTED ONTO A POLAR 
*     STEREOGRAPHIC MAP.
*
*     THE DATA FOR WIND PLOTTING IS IN GRIB CODE IN THE 
*     FILE 10uv.grb AND THE MSL IN THE FILE msl.grb.
*
*     OPEN MAGICS
      CALL POPEN
      CALL PSETC ('PS_DEVICE','ps_a4')
      CALL PSETC ('PS_FILE_NAME','wind04.ps')
      CALL PSETC ('PAGE_ID_LINE_USER_TEXT','Tests/Wind04')
      CALL PSETC('SUBPAGE_MAP_PROJECTION','POLAR_STEREOGRAPHIC')
      CALL PSETC('SUBPAGE_MAP_AREA_DEFINITION','CENTRE')
      CALL PSETR('SUBPAGE_MAP_CENTRE_LATITUDE',50.0)   
      CALL PSETR('SUBPAGE_MAP_CENTRE_LONGITUDE',10.0)   
      CALL PSETR('SUBPAGE_MAP_SCALE',15.E6)
*
*     PASS THE DATA TO MAGICS
*
      CALL PSETC('GRIB_INPUT_TYPE','FILE')
      CALL PSETC('GRIB_INPUT_FILE_NAME',
     x'data/oldts/10uv.grb')
      CALL PSETI ('GRIB_WIND_POSITION_1',1)                 
      CALL PSETI ('GRIB_WIND_POSITION_2',2) 
      CALL PGRIB
      CALL PSETR('TEXT_REFERENCE_CHARACTER_HEIGHT',0.4)
      CALL PSETC('TEXT_JUSTIFICATION','CENTRE')
      CALL PSETC('MAP_COASTLINE_COLOUR','GREEN')
      CALL PSETC('MAP_GRID_COLOUR','GREEN')
      CALL PRESET ('GRIB_WIND_POSITION_1')                 
      CALL PRESET ('GRIB_WIND_POSITION_2') 
*
*     Plot Wind Arrows on Northern Hemisphere Polar Stereographic Map
*     ---------------------------------------------------------------
      CALL PSETC('TEXT_LINE_1',
     1           'Northern Hemisphere Polar Stereographic -'//
     1           '10 metre U/V and MSL on a Gaussian (T511) grid')
      CALL PSETC('TEXT_LINE_2',
     1           'Wind Arrows and Contours')
      CALL PSETI('TEXT_LINE_COUNT',2)
      CALL WIND04_ONE
*
*       PLOT CONTOURS ON POLAR STEREO MAP
*
      CALL PSETC('GRIB_INPUT_TYPE','FILE')
      CALL PSETC('GRIB_INPUT_FILE_NAME',
     x 'data/oldts/msl.grb')
      CALL PGRIB
      CALL WIND04_TWO
*
*     Plot Wind Flagss on Northern Hemisphere Polar Stereographic Map
*     --------------------------------------------------------------
      CALL PNEW('PAGE')
      CALL PSETC('WIND_FIELD_TYPE','FLAGS')
      CALL PSETC('WIND_FLAG_ORIGIN_MARKER','OFF')
      CALL PSETC('GRIB_INPUT_TYPE','FILE')
      CALL PSETC('GRIB_INPUT_FILE_NAME',
     x 'data/oldts/10uv.grb')
      CALL PSETI ('GRIB_WIND_POSITION_1',1)
      CALL PSETI ('GRIB_WIND_POSITION_2',2)
      CALL PGRIB
      CALL PRESET ('GRIB_WIND_POSITION_1')
      CALL PRESET ('GRIB_WIND_POSITION_2')
      CALL PSETC('TEXT_LINE_1',
     1           'Northern Hemisphere Polar Stereographic -'//
     1           '10 metre U/V and MSL on a Gaussian (T511) grid')
      CALL PSETC('TEXT_LINE_2',
     1           'Wind Flags and Contours')
      CALL PSETI('TEXT_LINE_COUNT',2)
      CALL PSETR('TEXT_REFERENCE_CHARACTER_HEIGHT',0.4)
      CALL PSETC('TEXT_JUSTIFICATION','CENTRE')
      CALL PRESET ('GRIB_WIND_POSITION_1')
      CALL PRESET ('GRIB_WIND_POSITION_2')
      CALL WIND04_ONE
*
*     Plot Contours on Polar Stereo Map
*     ---------------------------------
      CALL PSETC('GRIB_INPUT_TYPE','FILE')
      CALL PSETC('GRIB_INPUT_FILE_NAME',
     x  'data/oldts/msl.grb')
      CALL PGRIB
      CALL WIND04_TWO
*
*     Close MAGICS
*     ------------
      CALL PCLOSE
*
      END
      SUBROUTINE WIND04_ONE
*
*     THIS SUBROUTINE PLOTS THE WIND_ARROWS AND COASTLINES ON A
*     NORTHEN HEMISPHERE POLAR STEREOGRAPHIC MAP.
*     DEFAULT VALUES FOR ALL WIND ARROW PARAMETERS
*
*
*     PLOT THE TITLE, COASTLINES AND WIND_ARROWS
*
      CALL PTEXT
      CALL PCOAST
      CALL PSETR('WIND_THINNING_FACTOR',4.0)
      CALL PWIND
*
      RETURN
      END
      SUBROUTINE WIND04_TWO
*
*     THIS SUBROUTINE PLOTS THE CONTOURS FROM THE MSL GAUSSIAN (T511)
*     FIELD ON A POLAR STEREOGRAPHIC PROJECTION. THE CONTOUR INTERVAL IS
*     SET TO 5.0 
*
*     ALL CONTOUR PARAMETERS THAT ARE NOT SET IN THIS SUBROUTINE 
*     TAKE THEIR DEFAULT VALUES.
*
      CALL PSETC('CONTOUR_LEVEL_SELECTION_TYPE','INTERVAL')
      CALL PSETR('CONTOUR_INTERVAL',5.0)
      CALL PSETI('CONTOUR_LINE_THICKNESS',4)
*
*
*     PLOT CONTOURS
*
      CALL PCONT
*
      RETURN
      END
