C (C) Copyright 1996-2016 ECMWF.
C 
C This software is licensed under the terms of the Apache Licence Version 2.0
C which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
C In applying this licence, ECMWF does not waive the privileges and immunities 
C granted to it by virtue of its status as an intergovernmental organisation nor
C does it submit to any jurisdiction.
C

	PROGRAM GRAF02
C
C	THIS PROGRAM DEMONSTRATES MAGICS GRAPH PLOTTING FACILITIES.
C	THERE ARE THREE FEATURES DEMONSTRATED:

C	(1) HIDDEN BARS
C	(2) CLUSTERED BARS
C	(3) OVERLAPPING BARS
C
C	OPEN MAGICS
C
	CALL POPEN
	CALL PSETC ('PS_DEVICE','ps_a4')
	CALL PSETC ('PS_FILE_NAME','graf02.ps')
C
	CALL PSETC ('PAGE_ID_LINE_USER_TEXT','TESTS/GRAF02')
C
C	PLOT HIDDEN BARS
C
	CALL GRAF02_ONE
	CALL PNEW ('PAGE')
C
C	PLOT CLUSTERED BARS   
C
	CALL GRAF02_TWO
	CALL PNEW ('PAGE')
C
C	PLOT OVERLAPPING BARS  
C
	CALL GRAF02_THREE
	CALL PCLOSE
	STOP
	END
	SUBROUTINE GRAF02_ONE
C
C   PLOT ONE SET OF BARS ON TOP OF ANOTHER
C
	DIMENSION X(6),YL(6),YU1(6),YU2(6)
	DATA X/1.,2.,3.,4.,5.,6./    
	DATA YL /6*0.0/
	DATA YU1/3.0,5.,9.,1.,2.,9./
	DATA YU2/5.0,2.,3.,6.,5.,2./
C
C	SET UP AXIS    
C
	CALL PSETC ('AXIS_ORIENTATION','HORIZONTAL')
	CALL PSETC ('AXIS_POSITION','BOTTOM')
	CALL PSETR ('AXIS_MIN_VALUE',0.0)     
	CALL PSETR ('AXIS_MAX_VALUE',7.0)     
	CALL PSETR ('AXIS_TICK_INTERVAL',1.0) 
	CALL PAXIS
	CALL PSETC ('AXIS_ORIENTATION','VERTICAL')
	CALL PSETC ('AXIS_POSITION','LEFT')       
	CALL PSETR ('AXIS_MIN_VALUE',1.0)     
	CALL PSETR ('AXIS_MAX_VALUE',10.0)    
	CALL PSETR ('AXIS_TICK_INTERVAL',1.0)
	CALL PAXIS
C
C	FIRST SET OF BARS WITH HATCH STYLE SHADING
C
	CALL PSETC ('GRAPH_TYPE','BAR')
	CALL PSETR ('GRAPH_BAR_WIDTH',1.20) 
	CALL PSETC ('GRAPH_SHADE','ON')    
	CALL PSETC ('GRAPH_SHADE_STYLE','HATCH')    
	CALL PSETC ('GRAPH_SHADE_COLOUR','RED')
	CALL PSET1R ('GRAPH_BAR_X_VALUES',X,6)
	CALL PSET1R ('GRAPH_BAR_Y_LOWER_VALUES',YL, 6)
	CALL PSET1R ('GRAPH_BAR_Y_UPPER_VALUES',YU1,6)
	CALL PSETC ('LEGEND','ON')
	CALL PSETC ('LEGEND_USER_TEXT','SYNOP')
	CALL PGRAPH
C
C	SECOND SET OF BARS WITH DOT SHADING
C
	CALL PSETC ('GRAPH_SHADE_STYLE','DOT')    
	CALL PSETC ('GRAPH_SHADE_COLOUR','BLUE')
	CALL PSET1R ('GRAPH_BAR_Y_UPPER_VALUES',YU2,6)
	CALL PSETC ('LEGEND_USER_TEXT','TEMP')
	CALL PGRAPH
	CALL PSETC ('TEXT_LINE_1','Graph BAR Plotting with '//
     x             'HIDDEN BARS ')
	CALL PTEXT
	RETURN      
	END
	SUBROUTINE GRAF02_TWO
C
C	PLOT BARS IN CLUSTERS
C
	DIMENSION X(6),YL(6),YU1(6),YU2(6),YU3(6)
	DATA X/0.75,1.75,2.75,3.75,4.75,5.75/
	DATA YL /6*0.0/
	DATA YU1/3.0,5.,9.,1.,2.,9./
	DATA YU2/5.0,2.,7.,6.,8.,7./
	DATA YU3/2.0,1.,2.,3.,9.,8./
C
C	SET UP AXIS             
C
	CALL PSETC ('AXIS_ORIENTATION','HORIZONTAL')
	CALL PSETC ('AXIS_POSITION','BOTTOM')
	CALL PSETR ('AXIS_MIN_VALUE',0.0)     
	CALL PSETR ('AXIS_MAX_VALUE',7.0)     
	CALL PSETR ('AXIS_TICK_INTERVAL',1.0) 
	CALL PAXIS
	CALL PSETC ('AXIS_ORIENTATION','VERTICAL')
	CALL PSETC ('AXIS_POSITION','LEFT')       
	CALL PSETR ('AXIS_MIN_VALUE',0.0)
	CALL PSETR ('AXIS_MAX_VALUE',10.0)     
	CALL PSETR ('AXIS_TICK_INTERVAL',1.0)
	CALL PAXIS
C
C	FIRST SET OF BARS - RED WITH HATCH SHADING
C
	CALL PSETC ('GRAPH_TYPE','BAR')    
	CALL PSETR ('GRAPH_BAR_WIDTH',0.88) 
	CALL PSETC ('GRAPH_SHADE','ON')    
	CALL PSETC ('GRAPH_SHADE_STYLE','HATCH')    
	CALL PSETI ('GRAPH_SHADE_HATCH_INDEX',5)
	CALL PSETC ('GRAPH_SHADE_COLOUR','RED')
	CALL PSET1R ('GRAPH_BAR_X_VALUES',X,6)
	CALL PSET1R ('GRAPH_BAR_Y_LOWER_VALUES',YL, 6)
	CALL PSET1R ('GRAPH_BAR_Y_UPPER_VALUES',YU1,6)
	CALL PSETC ('LEGEND','ON')
	CALL PSETC ('LEGEND_USER_TEXT','SYNOP')
	CALL PGRAPH
	DO 100 I=1,6
		X(I)=X(I)+0.25
100	CONTINUE
C
C	SECOND SET OF BARS - BLUE WITH HATCH SHADING
C
	CALL PSETC ('GRAPH_SHADE_COLOUR','BLUE')
	CALL PSET1R ('GRAPH_BAR_X_VALUES',X,6)
	CALL PSET1R ('GRAPH_BAR_Y_UPPER_VALUES',YU2,6)
	CALL PSETC ('LEGEND_USER_TEXT','TEMP')
	CALL PGRAPH
	DO 200 I=1,6
		X(I)=X(I)+0.25
200	CONTINUE
C
C	THIRD SET OF BARS - GREEN WITH HATCH SHADING
C
	CALL PSETC ('GRAPH_SHADE_COLOUR','GREEN')
	CALL PSET1R ('GRAPH_BAR_X_VALUES',X,6)
	CALL PSET1R ('GRAPH_BAR_Y_UPPER_VALUES',YU3,6)
	CALL PSETC ('LEGEND_USER_TEXT','PILOT')
	CALL PGRAPH
	CALL PSETC ('TEXT_LINE_1','Graph BAR plotting in '//
     x             'CLUSTERS ')
	CALL PTEXT
	RETURN
C
	END
	SUBROUTINE GRAF02_THREE
C
C	PLOT OVERLAPPING BARS
C
	DIMENSION X(6),YL(6),YU1(6),YU2(6),YU3(6)
	DATA X/.9,1.9,2.9,3.9,4.9,5.9/
	DATA YL /6*0.0/
	DATA YU1/3.0,5.,9.,1.,2.,9./
	DATA YU2/5.0,2.,7.,6.,8.,7./
	DATA YU3/2.0,1.,2.,3.,9.,8./
C
C	SET UP AXIS SYSTEM
C
	CALL PSETC ('AXIS_ORIENTATION','HORIZONTAL')
	CALL PSETC ('AXIS_POSITION','BOTTOM')
	CALL PSETR ('AXIS_MIN_VALUE',0.0)
	CALL PSETR ('AXIS_MAX_VALUE',7.0)
	CALL PSETR ('AXIS_TICK_INTERVAL',1.0)
	CALL PAXIS
	CALL PSETC ('AXIS_ORIENTATION','VERTICAL')
	CALL PSETC ('AXIS_POSITION','LEFT')
	CALL PSETR ('AXIS_MIN_VALUE',0.0)
	CALL PSETR ('AXIS_MAX_VALUE',10.0)
	CALL PSETR ('AXIS_TICK_INTERVAL',1.0)
	CALL PAXIS
C
C	FIRST SET OF BARS - SOLID RED
C
	CALL PSETC ('GRAPH_TYPE','BAR')
	CALL PSETR ('GRAPH_BAR_WIDTH',1.20)
	CALL PSETC ('GRAPH_SHADE','ON')
	CALL PSETC ('GRAPH_SHADE_STYLE','AREA_FILL')
	CALL PSETC ('GRAPH_SHADE_COLOUR','RED')
	CALL PSET1R ('GRAPH_BAR_X_VALUES',X,6)
	CALL PSET1R ('GRAPH_BAR_Y_LOWER_VALUES',YL,6)
	CALL PSET1R ('GRAPH_BAR_Y_UPPER_VALUES',YU1,6)
	CALL PSETC ('LEGEND','ON')
	CALL PSETC ('LEGEND_USER_TEXT','SYNOP')
	CALL PGRAPH
C
C	SECOND SET OF BARS - SOLID BLUE
C
	DO 100 I=1,6
		X(I)=X(I)+0.2
100	CONTINUE
	CALL PSETC ('GRAPH_SHADE_COLOUR','BLUE')
	CALL PSET1R ('GRAPH_BAR_X_VALUES',X,6)
	CALL PSET1R ('GRAPH_BAR_Y_UPPER_VALUES',YU2,6)
	CALL PSETC ('LEGEND_USER_TEXT','TEMP')
	CALL PGRAPH
	CALL PSETC ('TEXT_LINE_1','Graph BAR plotting with '//
     x             'OVERLAPPING ')
	CALL PTEXT
	DO 200 I=1,6
		X(I)=X(I)+0.15
200	CONTINUE
	CALL PSETC ('GRAPH_SHADE_COLOUR','GREEN')
	CALL PSET1R ('GRAPH_BAR_X_VALUES',X,6)
	CALL PSET1R ('GRAPH_BAR_Y_UPPER_VALUES',YU3,6)
	CALL PSETC ('LEGEND_USER_TEXT','PILOT')
	CALL PGRAPH
	RETURN
C
	END

