C (C) Copyright 1996-2016 ECMWF.
C 
C This software is licensed under the terms of the Apache Licence Version 2.0
C which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
C In applying this licence, ECMWF does not waive the privileges and immunities 
C granted to it by virtue of its status as an intergovernmental organisation nor
C does it submit to any jurisdiction.
C

	PROGRAM DATA05

C	PROGRAM TO DEMONSTRATE DATA INPUT FOR SYMBOL PLOTTING
C	TWO EXAMPLES ARE USED:
C	(1) PLOTTING NUMBERS IN INDIVIDUAL MODE
C	(2) PLOTTING NUMBERS IN TABLE MODE
C
C
C     OPEN MAGICS
C
      CALL POPEN 

      CALL PSETC ('PS_DEVICE','ps_a4')
      CALL PSETC ('PS_FILE_NAME','data05.ps')
      CALL PSETC ('PAGE_ID_LINE_USER_TEXT','DATA05') 

C
C     DEFINE PLOT AREA
C
      CALL PSETR('SUBPAGE_LOWER_LEFT_LATITUDE',0.0) 
      CALL PSETR('SUBPAGE_UPPER_RIGHT_LATITUDE',90.0)
      CALL PSETR('SUBPAGE_LOWER_LEFT_LONGITUDE',-90.0) 
      CALL PSETR('SUBPAGE_UPPER_RIGHT_LONGITUDE',90.0)
      CALL PSETC('PAGE_FRAME_COLOUR','BLACK')
      CALL PSETC('SUBPAGE_FRAME_COLOUR','BLACK')
      CALL PSETC('MAP_COASTLINE_COLOUR','BLACK')
      CALL PSETC('MAP_COASTLINE_COLOUR','BLACK')
      CALL PSETC('MAP_GRID','OFF') 
C
C     PLOT NUMBERS IN INDIVIDUAL AND TABLE MODE
C
      CALL ONE 
      CALL PNEW('PAGE')
      CALL TWO
C
C     CLOSE MAGICS
C 
      CALL PCLOSE 
      STOP 
      END 
      SUBROUTINE ONE
C
C 
C     PLOT NUMBERS IN INDIVIDUAL MODE
C
      DIMENSION X(10),Y(10),RAR(10) 
C
C     DEFINE LAT?LON POSITIONS
C
      DATA X/10.0,30.0,-20.,-40.,0.,-50.,-60.,-30.,20.,40./ 
      DATA Y/40.0,40.0,40.,40.,40.,50.,50.,50.,50.,50./ 
      DATA RAR/2.5,4.,6.,8.,10.,12.,14.,16.,18.,20./ 

      CALL PSETC('SYMBOL_TYPE','NUMBER') 
      CALL PSET1R('SYMBOL_INPUT_NUMBER_LIST',RAR,10) 
      CALL PSET1R('SYMBOL_INPUT_X_POSITION',X,10) 
      CALL PSET1R('SYMBOL_INPUT_Y_POSITION',Y,10) 
C
C     INDIVIDUAL SETTINGOF COLOUR, HEIGHT
C
      CALL PSETC('SYMBOL_COLOUR','MAGENTA') 
      CALL PSETR('SYMBOL_HEIGHT',0.5) 
      CALL PSETC('SYMBOL_TABLE_MODE','OFF') 
C
C     SET TEXT
C
	CALL PSETC('TEXT_LINE_1',
     X    'Symbol NUMBER plotting in INDIVIDUAL mode') 
C
C     PLOT COASTLINES, SYMBOLS AND TEXT
C
      CALL PCOAST 
      CALL PSYMB 
      CALL PTEXT 

      RETURN 
      END 



















      SUBROUTINE TWO
C
C     PLOT NUMBERS IN TABLE MODE
C
      CHARACTER*10 CTAB 
      DIMENSION ZRAR(10) 
      DIMENSION HTAB(8),CTAB(8),XMNTAB(8),XMXTAB(8) 
      DIMENSION XX(10),YY(10) 
C
C     NUMBER LIST AND MIN/MAX TABLES
C
      DATA ZRAR/2.5,4.,6.,8.,10.,12.,14.,16.,7.,13./ 
      DATA XMNTAB/1.,3.,5.,7.,9.,11.,13.,15./ 
      DATA XMXTAB/3.,5.,7.,9.,11.,13.,15.,17./ 
C
C     HEIGHT/COLOUR TABLES
C
      DATA HTAB/0.3,0.25,0.2,0.15,0.35,0.4,0.5,0.22/ 
      DATA CTAB/'RED','YELLOW','GREEN','MAGENTA','BLUE','RED',
     X          'CYAN','BLUE'/ 
C
C     DEFINE LAT/LON POSITIONS
C
      DATA XX/-25.0,-25.0,-25.,-25.,-25.,25.,25.,25.,25.,25./ 
      DATA YY/20.0,30.0,40.,50.,60.,20.,30.,40.,50.,60./ 
      CALL PSET1R('SYMBOL_INPUT_X_POSITION',XX,10) 
      CALL PSET1R('SYMBOL_INPUT_Y_POSITION',YY,10) 
      CALL PSETC('SYMBOL_TYPE','NUMBER') 
      CALL PSET1R('SYMBOL_INPUT_NUMBER_LIST',ZRAR,10) 
C
C     TABLE MODE - LEGEND ON
C 
      CALL PSETC('LEGEND_BORDER','ON')
      CALL PSETC('SYMBOL_TABLE_MODE','ON') 
      CALL PSETC('LEGEND','ON') 
      CALL PSETC('LEGEND_ENTRY','ON') 
      CALL PSET1R('SYMBOL_MAX_TABLE',XMXTAB,8) 
      CALL PSET1R('SYMBOL_MIN_TABLE',XMNTAB,8) 
      CALL PSET1C('SYMBOL_COLOUR_TABLE',CTAB,8) 
      CALL PSET1R('SYMBOL_HEIGHT_TABLE',HTAB,8) 
      CALL PSETC('TEXT_LINE_1',
     X 'Symbol NUMBER plotting in TABLE mode') 
C
C     PLOT COASTLINES, TEXT AND SYMBOLS
C
      CALL PCOAST
      CALL PTEXT 
      CALL PSYMB 
      RETURN 
      END 




