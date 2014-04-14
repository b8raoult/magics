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

/*! \file OdaDecoder.cc
    \brief Implementation of the Template class OdaDecoder.
    
    Magics Team - ECMWF 2004
    
    Started: Fri 16-Jan-2004
    
    Changes:
    
*/

#include <vector>
#include <map>
#include <set>

#include "odblib/odb_api.h"
extern "C" {
#include "odblib/odbcapi.h"
}


#include "../common/Timer.h"
#include "OdaDecoder.h"

#include "SciMethods.h"
#include "TextVisitor.h"

#include "odblib/Reader.h"

static int getOdbColumnIndex(odb::Reader::iterator &,const string&);

int getOdbColumnIndex(odb::Reader::iterator &firstRowIt,const string& colName)
{
	int index=0;
  	for(odb::MetaData::iterator it=firstRowIt->columns().begin(); it != firstRowIt->columns().end(); ++it)
	{			
		string s=(*it)->name();
		if(s == colName)
			return index; 
		
		index++;
	}
	MagLog::warning() << "Cannot find column for "<< colName << endl;
  	return -1;

}

OdaGeoDecoder::OdaGeoDecoder() 
{
}


OdaGeoDecoder::~OdaGeoDecoder() 
{
	
}

/*!
 Class information are given to the output-stream.
*/		
void OdaGeoDecoder::print(ostream& out)  const
{
	out << "OdaGeoDecoder[";
        OdaGeoDecoderAttributes::print(out);
        out << "]";
}

double degrees(double val) 
{
	return val;
}

double radians(double val) 
{
	return val*180/3.14;
}

typedef double (*Converter)(double);

map<string, Converter> converters_;


void OdaGeoDecoder::decode(const Transformation& transformation)
{    
	if ( !empty() ) 
		return; 
	
	//Vectors. It is used for building histogram data for speed!!
	if(info("_datatype") == "ODB_geovectors")
	{		
		CustomisedPointsList points;
		std::set<string> noset;
		customisedPoints(transformation,noset,points);
		for(CustomisedPointsList::const_iterator point = points.begin(); point != points.end(); ++point) 
		{
			push_back(new UserPoint((**point)["lon"], (**point)["lat"], (**point)["colour_component"]));
		}
	}	
	else
	{

	try
	{
		odb_start();
		odb::Reader oda(path_);	
		odb::Reader::iterator it = oda.begin();
	
		int latIndex,lonIndex,valueIndex=-1;		
		
		if((latIndex=getOdbColumnIndex(it,latitude_)) == -1)
			throw exception();		
		if((lonIndex=getOdbColumnIndex(it,longitude_)) == -1)
			throw exception();
		
		if(value_.empty())
			MagLog::info() <<  "No value is specified!" << endl;
		else if((valueIndex = getOdbColumnIndex(it,value_)) == -1)
			throw exception();
			  		
		MagLog::info() <<  "Indices: " << latIndex << " " << lonIndex << " " << valueIndex << endl;
	
		int dataCnt=0;
		dataIndex_.clear();
		
		unsigned int row=0;
		
		for(; it != oda.end(); ++it) 
		{			
			double lat = (*it)[latIndex];
			double lon = (*it)[lonIndex];
			position(lat, lon);
	
			if ( transformation.in(lon, lat)  ) 
			{
				if(valueIndex != -1)
				{
				  	stats_["value"].push_back((*it)[valueIndex]);
				  	stats_["x"].push_back(lon);
				  	stats_["y"].push_back(lat);
					push_back(new UserPoint(lon, lat, (*it)[valueIndex]));
				}
				else
				{
				  	push_back(new UserPoint(lon, lat));
				}	
				
				dataIndex_.push_back(dataCnt);
				
				row++;
				if (nb_rows_ != -1 && row >= nb_rows_)
				{
					break;
				}
			}
			dataCnt++;
			
		}

		MagLog::info() <<  "Number of rows: " << row << endl;

		computeStats();
	}
	catch(exception e)
	{
		MagLog::error() << "Failed to read ODB data: " << e.what();
		return;
	}
	
	
	}
}

void OdaGeoDecoder::visit(Transformation& transformation) {MagLog::info() <<  "No value is specified!" << endl;

	return;	

	decode();
	if ( empty() ) return;
	double minx = front()->x_;
	double maxx = front()->x_;
	double miny = front()->y_;
	double maxy = front()->y_;

	for (iterator point = begin(); point != end(); ++point) {
		if ( minx > (*point)->x_ ) minx = (*point)->x_;
		if ( miny > (*point)->y_ ) miny = (*point)->y_;
		if ( maxx < (*point)->x_ ) maxx = (*point)->x_;
		if ( maxy < (*point)->y_ ) maxy = (*point)->y_;
	}

	transformation.setDataMinMaxX(minx, maxx);
	transformation.setDataMinMaxY(miny, maxy);

}
void OdaGeoDecoder::decode()
{    
	if ( !empty() ) 
		return;  

	try
	{	
	      odb_start();
	      odb::Reader oda(path_);

	      odb::Reader::iterator it = oda.begin();

	      int latIndex,lonIndex,valueIndex=-1;		
		      
	      if((latIndex=getOdbColumnIndex(it,latitude_)) == -1)
		      throw exception();		      
	      if((lonIndex=getOdbColumnIndex(it,longitude_)) == -1)
		      throw exception();
		      		      	    
	      if(value_.empty())
		      MagLog::info() <<  "No value is specified!" << endl;
	      else if((valueIndex = getOdbColumnIndex(it,value_)) == -1)
		       throw exception();	
	      			      
	      MagLog::info() <<  "Indices: " << latIndex << " " << lonIndex << " " << valueIndex << endl;

	      unsigned int row=0;
	      
	      int dataCnt=0;
	      dataIndex_.clear();
		      
	      for (; it != oda.end(); ++it) 
	      {			
		      double lat = (*it)[latIndex];
		      double lon = (*it)[lonIndex];
		      position(lat, lon);
		      
		      if(valueIndex != -1)
		      {
			      stats_["value"].push_back((*it)[valueIndex]);
			      stats_["x"].push_back(lon);
			      stats_["y"].push_back(lat);
			      push_back(new UserPoint(lon, lat, (*it)[valueIndex]));
		      }
		      else
		      {
			      push_back(new UserPoint(lon, lat));
		      }
		      
		      dataIndex_.push_back(dataCnt);
		      dataCnt++;
		      
		      row++;
		      if (nb_rows_ != -1 && row >= nb_rows_)
		      {
				      break;
		      }		
	      }

	      computeStats();

	      MagLog::info() <<  "Number of rows: " << row << endl;	
	}
	catch(exception e)
	{
		MagLog::error() << "Failed to read ODB data: " << e.what();
		return;
	}
}

void OdaGeoDecoder:: visit(TextVisitor& title)
{
	if ( !title_.empty() )
		title.addAutomaticTitle(title_);


	title.addAutomaticTitle("OdbDatabase: " + path_);
	if(stats_.find("value") == stats_.end())
	{
		ostringstream text;
		if ( !info("stats::min").empty() && !info("stats::max").empty() ) {
			text  << "Min: " << info("stats::min") << " Max: " << info("stats::max") << " (" << info("stats::points") << " points)";
		}
		else
			text << info("stats::points") << " points";
		title.addAutomaticTitle(text.str());
	}
	else if (info("stats::points").empty())
	{
		title.addAutomaticTitle(" No points found ");
	}
	else
	{
		if(info("stats::min").empty() &&  stats_["value"].size() >0)
		{	
		  	double min = *(std::min_element(stats_["value"].begin(), stats_["value"].end()));
			setInfo("stats::min",tostring(min));
		}
		if(info("stats::max").empty() &&  stats_["value"].size() >0)
		{	
		  	double max = *(std::max_element(stats_["value"].begin(), stats_["value"].end()));
			setInfo("stats::max",tostring(max));
		}
		title.addAutomaticTitle( "Min: " + info("stats::min") + "  Max: " + info("stats::max") + "    ( " + info("stats::points") + " points) ");
	}
	

}

static 
double speed(double x, double y)
{
	return sqrt(x*x+ y*y);
}

void OdaGeoDecoder::customisedPoints(const std::set<string>&, CustomisedPointsList& list)
{
     	if(!customisedPoints_.empty())
	{
	  	for (vector<CustomisedPoint*>::const_iterator point =customisedPoints_.begin(); point != customisedPoints_.end(); ++point) 
		{			  		  
			CustomisedPoint*  cp = new CustomisedPoint((*point)->longitude(), (*point)->latitude(), (*point)->identifier());
			for(CustomisedPoint::iterator key = (*point)->begin(); key != (*point)->end(); ++key)
				cp->insert(make_pair(key->first, key->second));	
			
			list.push_back(cp);	
		}
		return;		
	}	
     	
     	try
	{	
	    odb_start();
	    odb::Reader oda(path_);

	    odb::Reader::iterator it = oda.begin();
	    
	    int latIndex,lonIndex,valueIndex=-1,xIndex,yIndex;		
		      
	    if((latIndex=getOdbColumnIndex(it,latitude_)) == -1)
		     throw exception();		      
	    if((lonIndex=getOdbColumnIndex(it,longitude_)) == -1)
		     throw exception();		      
	    if(value_.empty())
		      MagLog::info() <<  "No value is specified!" << endl;   
	    else if((valueIndex=getOdbColumnIndex(it,value_)) == -1)
		     throw exception();  
	     
	    if((xIndex=getOdbColumnIndex(it,x_)) == -1)
		     throw exception();
	    if((yIndex=getOdbColumnIndex(it,y_)) == -1)
		     throw exception();
	      
	    MagLog::info() <<  "Indices: " << latIndex << " " << lonIndex << " " << valueIndex << endl;
	    
	    unsigned int row=0;
		    
	    for (; it != oda.end(); ++it, row++) 
	    {			
		    if(nb_rows_ != -1 && row >= nb_rows_)
		    {
			    break;
		    }

		    double lat = (*it)[latIndex];
		    double lon = (*it)[lonIndex];
		    position(lat, lon);
					    
		    CustomisedPoint* point = new CustomisedPoint();		
		    point->longitude(lon);
		    point->latitude(lat);
		    (*point)["x_component"] = (*it)[xIndex];
		    (*point)["y_component"] = (*it)[yIndex];
		    double val =  (valueIndex != -1) ? (*it)[valueIndex] : speed((*it)[xIndex],  (*it)[yIndex]);
		    (*point)["colour_component"] = val;
		    list.push_back(point);	
		    stats_["value"].push_back(val);		
		    //stats_["x"].push_back((*it)[xIndex]);
		    //stats_["y"].push_back((*it)[yIndex]);
		    
		    CustomisedPoint*  cp = new CustomisedPoint(point->longitude(), point->latitude(), point->identifier());
		    for(CustomisedPoint::iterator key = point->begin(); key != point->end(); ++key)
			    cp->insert(make_pair(key->first, key->second));					
		    customisedPoints_.push_back(cp);
		    
	    }	

	    computeStats();

	    MagLog::info() <<  "Number of rows: " << row << endl;

	}
	catch(exception e)
	{
		MagLog::error() << "Failed to read ODB data: " << e.what();
		return;
	}
	
}

void OdaGeoDecoder::position(double& lat, double& lon)
{
	if ( converters_.empty() ) {
		converters_["degrees"] = &degrees;
		converters_["radians"] = &radians;
	}


	map<string, Converter>::iterator converter = converters_.find(lowerCase(unit_));

	if (converter == converters_.end() ) {
		MagLog::warning() << "odb_coordinates_unit:" << unit_ << " is not valid -->Change back to default:degrees" << endl;
		converter = converters_.find("degrees");
	}
	lat = (*converter->second)(lat);
	lon = (*converter->second)(lon);

}

void OdaGeoDecoder::customisedPoints(const Transformation& transformation, const std::set<string>&, CustomisedPointsList& list)
{
	if(!customisedPoints_.empty())
	{
	  	for (vector<CustomisedPoint*>::const_iterator point =customisedPoints_.begin(); point != customisedPoints_.end(); ++point) 
		{			  		  
			CustomisedPoint*  cp = new CustomisedPoint((*point)->longitude(), (*point)->latitude(), (*point)->identifier());
			for(CustomisedPoint::const_iterator key = (*point)->begin(); key != (*point)->end(); ++key)
				cp->insert(make_pair(key->first, key->second));	
			
			list.push_back(cp);	
		}
		return;		
	}	
	
 	try
	{
		odb_start();
		odb::Reader oda(path_);

		odb::Reader::iterator it = oda.begin();
  
		int latIndex,lonIndex,valueIndex=-1,xIndex,yIndex;		
			      
	    	if((latIndex=getOdbColumnIndex(it,latitude_)) == -1)
		     throw exception();		      
	    	if((lonIndex=getOdbColumnIndex(it,longitude_)) == -1)
		     throw exception();
		      
	    	if(value_.empty())
	    		MagLog::info() <<  "No value is specified!" << endl;	      
	    	else if((valueIndex=getOdbColumnIndex(it,value_)) == -1)
		     throw exception();  
	     
	    	if((xIndex=getOdbColumnIndex(it,x_)) == -1)
		     throw exception();
	    	if((yIndex=getOdbColumnIndex(it,y_)) == -1)
		     throw exception();
		
		MagLog::info() <<  "Indices: " << latIndex << " " << lonIndex << " " << valueIndex << endl;

		unsigned int row=0;
			
		for (; it != oda.end(); ++it) 
		{	
			double lat = (*it)[latIndex];
			double lon = (*it)[lonIndex];
			position(lat, lon);
			if ( transformation.in(lon, lat)  ) 
			{							  
				CustomisedPoint* point = new CustomisedPoint();	
				point->longitude(lon);
				point->latitude(lat);
				double val =  (valueIndex != -1) ? (*it)[valueIndex] : speed((*it)[xIndex],  (*it)[yIndex]);
				(*point)["x_component"] = (*it)[xIndex];
				(*point)["y_component"] = (*it)[yIndex];
				(*point)["colour_component"] =val;
				list.push_back(point);	
				stats_["value"].push_back(val);			
				//stats_["x"].push_back((*it)[xIndex]);
				//stats_["y"].push_back((*it)[yIndex]);
		
				CustomisedPoint*  cp = new CustomisedPoint(point->longitude(), point->latitude(), point->identifier());
		    		for(CustomisedPoint::iterator key = point->begin(); key != point->end(); ++key)
			    		cp->insert(make_pair(key->first, key->second));					
		    		customisedPoints_.push_back(cp);
		    
		    		row++;
				if(nb_rows_ != -1 && row >= nb_rows_)
				{
					break;
				}
			}
		}

		computeStats();

		MagLog::info() <<  "Number of rows: " << row << endl;	
	}
	catch(exception e)
	{
		MagLog::error() << "Failed to read ODB data: " << e.what();
		return;
	}	
}

void OdaGeoDecoder::initInfo()
{
	setInfo("MV_Format","ODB");
	
	if(x_.empty())
	{
  		setInfo("_datatype","ODB_geopoints");
		setInfo("statsType","scalar");
		if(!value_.empty())
			setInfo("value",value_);
	}
	else
	{	  
		setInfo("_datatype","ODB_geovectors");
		setInfo("statsType","scalar");
		if(value_.empty())
			setInfo("value","computed speed");
		else
		  	setInfo("value",value_);
		setInfo("x",x_);
		setInfo("y",y_);		
	}
	
	setInfo("path",path_);
	setInfo("lat",latitude_);
	setInfo("lon",longitude_);
}


void OdaGeoDecoder::visit(ValuesCollector& points)
{
	points.setCollected(true);

	if(points.size() <=0)
		return;	  
	
	
	if(info("_datatype") == "ODB_geopoints")
	{  
		if(size() == 0)
	  		return;
	
		if(value_.empty())
			points.setHasValue(false);
	}
	else
	{
	  	if(customisedPoints_.size()==0)
			return;
	}	
	
	for (ValuesCollector::iterator point =  points.begin(); point != points.end(); ++point)
	{
	  	vector<int> idxV;
		double lat=(*point).y();
	  	double lon=(*point).x();
			
		if((*point).mode() == ValuesCollectorPoint::IndexMode) 
		{
		  	if((*point).index() >=0 &&  (*point).index() < size())
			{
				idxV.push_back((*point).index());
			}
			else
			{
			  	continue;
			}	
		}	
	  	else
		{  	 
			if(info("_datatype") == "ODB_geopoints")
			{		  	  
				for(int i=0; i < size(); i++)
				{
					if(fabs(at(i)->y()-lat) < points.searchRadiusY() &&
			   		   fabs(at(i)->x()-lon) <  points.searchRadiusX())
					{
			  			idxV.push_back(i);
					}
				}
			}
			else
			{		  	  
				for(int i=0; i < customisedPoints_.size(); i++)
				{
					if(fabs(customisedPoints_.at(i)->latitude()-lat) < points.searchRadiusY() &&
			   		   fabs(customisedPoints_.at(i)->longitude()-lon) <  points.searchRadiusX())
					{
			  			idxV.push_back(i);
					}
				}
			}
		}
					
		if(idxV.size() ==0)
			continue;  
		
		double dist=10000000.;
		int minIdx=-1;
		
		//MagLog::debug() << "odb collect idxV : " << lat << " " << lon << " " << idxV.size() << endl;
 		
		if(info("_datatype") == "ODB_geopoints")
		{
			for(int i=0; i < idxV.size(); i++)
			{  			
		  		int idx=idxV[i];
				double d=magics::geoDistanceInKm(at(idx)->y(),at(idx)->x(),lat,lon);
				
				if(d < dist)
				{
			  		minIdx=idx;
					dist=d;
				}			
			}
			
			if(minIdx>=0)  
			(*point).push_back(new ValuesCollectorData(at(minIdx)->x(),
							       at(minIdx)->y(),
							       at(minIdx)->value(),
							       dist,minIdx));		
			
		}
		else
		{
			for(int i=0; i < idxV.size(); i++)
			{  			
		  		int idx=idxV[i];
				double d=magics::geoDistanceInKm(customisedPoints_.at(idx)->latitude(),
								 customisedPoints_.at(idx)->longitude(),
								 lat,lon);				
				if(d < dist)
				{
			  		minIdx=idx;
					dist=d;
				}			
			}
		
			if(minIdx>=0) 
			{
				map<string,double>::iterator uIt=customisedPoints_.at(minIdx)->find("x_component");
				map<string,double>::iterator vIt=customisedPoints_.at(minIdx)->find("y_component");
				if(uIt !=customisedPoints_.at(minIdx)->end() && 
				   vIt !=customisedPoints_.at(minIdx)->end())
				{  
					(*point).push_back(new ValuesCollectorUVData(
							       customisedPoints_.at(minIdx)->longitude(),
							       customisedPoints_.at(minIdx)->latitude(),
							       uIt->second,vIt->second,dist,minIdx));
				}
			}
		}					  					     			
	}	  
}



void OdaGeoDecoder::visit(MetaDataCollector& mdc)
{	
	for(map<string, string>::iterator key = mdc.begin(); key != mdc.end(); ++key )
	{	    
	  	if(information_.find(key->first) == information_.end() &&
		  mdc.attribute(key->first).group() == MetaDataAttribute::StatsGroup)
		{
			  computeStats();
			  break;
		}
	}
	
	if(information_.find("stats::points") == information_.end())
	{
		setInfo("stats::points",tostring(size()));
	}
		
	MetviewIcon::visit(mdc);
}  

    
OdaXYDecoder::OdaXYDecoder() : matrix_(0)
{
}


OdaXYDecoder::~OdaXYDecoder() 
{
	
}

/*!
 Class information are given to the output-stream.
*/		
void OdaXYDecoder::print(ostream& out)  const
{
	out << "OdaXYDecoder[";
    OdaXYDecoderAttributes::print(out);
    out << "]";
}

void OdaXYDecoder::customisedPoints(const Transformation& transformation, const std::set<string>&, CustomisedPointsList& list)
{  
	try
	{
  
		odb_start();
		odb::Reader oda(path_);

		odb::Reader::iterator it = oda.begin();

		int xIndex=-1,yIndex=-1,valueIndex=-1,xcIndex=-1,ycIndex=-1;		
			      
		if((xIndex=getOdbColumnIndex(it,x_)) == -1)
			  throw exception();
		if((yIndex=getOdbColumnIndex(it,y_)) == -1)
			  throw exception();	    
		if(!value_.empty() && (valueIndex=getOdbColumnIndex(it,value_)) == -1)
			    throw exception();  
		if(!x_component_.empty() && (xcIndex=getOdbColumnIndex(it,x_component_)) == -1)
			    throw exception();    
		if(!y_component_.empty() && (ycIndex=getOdbColumnIndex(it,y_component_)) == -1)
			    throw exception();      
		
		MagLog::info() <<  "Indices: " << xIndex << " " << yIndex << " " << valueIndex << " " << xcIndex << " " <<  xcIndex << endl;

		int dataCnt=0;
		dataIndex_.clear();
			
		unsigned int row=0;
			
		for (; it != oda.end(); ++it) 
		{
			CustomisedPoint* point = new CustomisedPoint();		
			double x = (*it)[xIndex];
			double y = (*it)[yIndex];
			if ( transformation.in(x,y)  ) 
			{							  
				point->longitude(x);
				point->latitude(y);
				(*point)["x"] = x;
				(*point)["y"] = y;
				
				if(xcIndex != -1 && ycIndex != -1)
				{		  	
					(*point)["x_component"] = (*it)[xcIndex];
					(*point)["y_component"] = (*it)[ycIndex];
					double val =  (valueIndex != -1) ? (*it)[valueIndex] : speed((*it)[xcIndex],  (*it)[ycIndex]);
					(*point)["colour_component"] =val;				
					stats_["value"].push_back(val);			
				}
				else if(valueIndex != -1)
				{
					double val =  (*it)[valueIndex];
					(*point)["colour_component"] = val;
					stats_["value"].push_back(val);	
				}
				
				list.push_back(point);			
				stats_["x"].push_back((*it)[xIndex]);
				stats_["y"].push_back((*it)[yIndex]);
		
				dataIndex_.push_back(dataCnt);
				
				row++;
				if(nb_rows_ != -1 && row >= nb_rows_)
				{
					break;
				}
			}
			dataCnt++;			
		}

		computeStats();

		MagLog::info() <<  "Number of rows: " << row << endl;	
	}	
	catch(exception e)
	{
		MagLog::error() << "Failed to read ODB data: " << e.what();
		return;
	}		
}

void OdaXYDecoder::customisedPoints(const std::set<string>&, CustomisedPointsList& list)
{     	
	try
	{
		  odb_start();
		  odb::Reader oda(path_);

		  odb::Reader::iterator it = oda.begin();

		  int xIndex=-1,yIndex=-1,valueIndex=-1,xcIndex=-1,ycIndex=-1;		
				
		  if((xIndex=getOdbColumnIndex(it,x_)) == -1)
			    throw exception();
		  if((yIndex=getOdbColumnIndex(it,y_)) == -1)
			    throw exception();	    
		  if(!value_.empty() && (valueIndex=getOdbColumnIndex(it,value_)) == -1)
			    throw exception();  
		  if(!x_component_.empty() && (xcIndex=getOdbColumnIndex(it,x_component_)) == -1)
			    throw exception();    
		  if(!y_component_.empty() && (ycIndex=getOdbColumnIndex(it,y_component_)) == -1)
			    throw exception(); 
		    
		  MagLog::info() <<  "Indices: " << xIndex << " " << yIndex << " " << valueIndex << " " << xcIndex << " " <<  xcIndex << endl;

		  int dataCnt=0;
		  dataIndex_.clear();
		  
		  unsigned int row=0;
			  
		  for (; it != oda.end(); ++it) 
		  {
			  CustomisedPoint* point = new CustomisedPoint();		
			  double x = (*it)[xIndex];
			  double y = (*it)[yIndex];
								    
			  point->longitude(x);
			  point->latitude(y);
			  (*point)["x"] = x;
			  (*point)["y"] = y;
				  
			  if(xcIndex != -1 && ycIndex != -1)
			  {		  	
				  (*point)["x_component"] = (*it)[xcIndex];
				  (*point)["y_component"] = (*it)[ycIndex];
				  double val =  (valueIndex != -1) ? (*it)[valueIndex] : speed((*it)[xcIndex],  (*it)[ycIndex]);
				  (*point)["colour_component"] =val;				
				  stats_["value"].push_back(val);			
			  }
			  else if(valueIndex != -1)
			  {
				  double val =  (*it)[valueIndex];
				  (*point)["colour_component"] = val;
				  stats_["value"].push_back(val);	
			  }
				  
			  list.push_back(point);			
			  stats_["x"].push_back((*it)[xIndex]);
			  stats_["y"].push_back((*it)[yIndex]);
		  
			  dataIndex_.push_back(dataCnt);
			  dataCnt++;
		  
			  row++;
			  if(nb_rows_ != -1 && row >= nb_rows_)
			  {
					  break;
			  }
		  }

		  computeStats();

		  MagLog::info() <<  "Number of rows: " << row << endl;	
	}	
	catch(exception e)
	{
		MagLog::error() << "Failed to read ODB data: " << e.what();
		return;
	}		
}

void OdaXYDecoder:: visit(TextVisitor& title)
{
	if ( !title_.empty() )
		title.add(new TextEntry(title_));
	title.addAutomaticTitle("OdbDatabase: " + path_);
	
	string numStr=info("stats::points");
	if(numStr.empty() && stats_["x"].size() >0)
	{
	  	numStr=tostring(stats_["x"].size());
	}	
	  	
	
	if(numStr.empty())
	{
		title.addAutomaticTitle(" No points found " );
	}
	else
	{
		title.addAutomaticTitle("points: " + numStr);
	}	
}

void OdaXYDecoder::decode(const Transformation& transformation)
{
        if ( !empty() ) 
		return;  

	try
	{
	  
	      odb_start();
	      odb::Reader oda(path_);

	      odb::Reader::iterator it = oda.begin();

	      int xIndex=-1,yIndex=-1,valueIndex=-1;		
			    
	      if((xIndex=getOdbColumnIndex(it,x_)) == -1)
			throw exception();
	      if((yIndex=getOdbColumnIndex(it,y_)) == -1)
			throw exception();	    
	      if(!value_.empty() && (valueIndex=getOdbColumnIndex(it,value_)) == -1)
			throw exception();  
		      
	      MagLog::info() <<  "Indices: " << xIndex << " " << yIndex << " " << valueIndex << endl;

	      int dataCnt=0;
	      dataIndex_.clear();
	      
	      unsigned int row=0;

	      for (; it != oda.end(); ++it) 
	      {			
		      double x = (*it)[xIndex];
		      double y = (*it)[yIndex];		

		      if ( transformation.in(x, y)  ) 
		      {
			      double val =0;
			      if (valueIndex!=-1) {
				      val = (*it)[valueIndex];
				      stats_["value"].push_back(val);
			      }
			      push_back(new UserPoint(x, y, val));

			      stats_["x"].push_back(x);
			      stats_["y"].push_back(y);

			      dataIndex_.push_back(dataCnt);			
			      
			      row++;
			      if (nb_rows_ != -1 && row >= nb_rows_)
			      {
				      break;
			      }
		      }
		      dataCnt++;
	      }
      
	      computeStats();

	      MagLog::info() <<  "Number of rows: " << row << endl;	
	}	
	catch(exception e)
	{
		MagLog::error() << "Failed to read ODB data: " << e.what();
		return;
	}	

}

void OdaXYDecoder::decode()
{
        if ( !empty() ) 
		return;  

	try
	{
	      odb_start();
	      odb::Reader oda(path_);

	      odb::Reader::iterator it = oda.begin();

	      int xIndex=-1,yIndex=-1,valueIndex=-1;		
			    
	      if((xIndex=getOdbColumnIndex(it,x_)) == -1)
			throw exception();
	      if((yIndex=getOdbColumnIndex(it,y_)) == -1)
			throw exception();	    
	      if(!value_.empty() && (valueIndex=getOdbColumnIndex(it,value_)) == -1)
			throw exception();  
	
	      MagLog::info() <<  "Indices: " << xIndex << " " << yIndex << " " << valueIndex << endl;

	      int dataCnt=0;
	      dataIndex_.clear();
	      
	      unsigned int row=0;

	      for (; it != oda.end(); ++it) 
	      {			
		      double x = (*it)[xIndex];
		      double y = (*it)[yIndex];
				      
		      double val =0;
		      if (valueIndex!=-1) {
			      val = (*it)[valueIndex];
			      stats_["value"].push_back(val);
		      }

		      stats_["x"].push_back(x);
		      stats_["y"].push_back(y);
		      push_back(new UserPoint(x, y, val));

		      dataIndex_.push_back(dataCnt);
		      dataCnt++;
		      
		      row++;
		      if (nb_rows_ != -1 && row >= nb_rows_)
		      {
			      break;
		      }
		      
	      }
      
	      //computeStats();

	      MagLog::info() <<  "Number of rows: " << row << endl;
	} 	
	catch(exception e)
	{
		MagLog::error() << "Failed to read ODB data: " << e.what();
		return;
	}	    

}
void OdaXYDecoder::visit(Transformation& transformation) {
	decode();
	if ( empty() ) return;
	double minx = front()->x_;
	double maxx = front()->x_;
	double miny = front()->y_;
	double maxy = front()->y_;

	for (iterator point = begin(); point != end(); ++point) {
		if ( minx > (*point)->x_ ) minx = (*point)->x_;
		if ( miny > (*point)->y_ ) miny = (*point)->y_;
		if ( maxx < (*point)->x_ ) maxx = (*point)->x_;
		if ( maxy < (*point)->y_ ) maxy = (*point)->y_;
	}

	transformation.setDataMinMaxX(minx, maxx);
		transformation.setDataMinMaxY(miny, maxy);


}

MatrixHandler& OdaXYDecoder::matrix()
{
	if  ( !matrix_ ) {
		decode();
		matrix_ = (*odb_binning_)(*this);
		setInfo("hasMatrix","true");
	}

	matrixHandlers_.push_back(new MatrixHandler(*matrix_));
	return *(matrixHandlers_.back());
}


void OdaXYDecoder::initInfo()
{
	setInfo("_datatype","ODB_xy");
	setInfo("statsType","scatter");
	setInfo("path",path_);
	setInfo("value",value_);
	setInfo("x",x_);
	setInfo("y",y_);
}

void OdaXYDecoder::visit(ValuesCollector& points)
{
	if(value_.empty())
	{
	  	points.setHasValue(false);
	}
  
  	if(!matrix_ && stats_.find("value") == stats_.end())
	{
		points.setCollected(true);	
	}
	else
	{  	
		points.setCollected(true);
	}
	
	
	if( points.size() <=0)
	   return;

	for (ValuesCollector::iterator point =  points.begin(); point != points.end(); ++point)
	{
	  	double y=(*point).y();
	  	double x=(*point).x();
					
		if(!matrix_)
		{
		  	vector<int> idxV;
		  	if((*point).mode() == ValuesCollectorPoint::IndexMode) 
			{
		  		if((*point).index() >=0 &&  (*point).index() < size())
				{
					idxV.push_back((*point).index());
				}
				else
				{
			  		continue;
				}	
			}	
		  	else
			{  		  		
				for(int i=0; i < size(); i++)
				{
					if(fabs(at(i)->x()-x) < points.searchRadiusX()&&
			  	   	   fabs(at(i)->y()-y) < points.searchRadiusY())
					{
			  			idxV.push_back(i);
					}
				}
			}	
		
			if(idxV.size() ==0)
				continue;  
		
			double dist=10000000.;
			int minIdx=-1;
		
			//MagLog::debug() << "odb collect idxV : " << lat << " " << lon << " " << idxV.size() << endl;
 		
			for(int i=0; i < idxV.size(); i++)
			{  			
		  		int idx=idxV[i];
				double d=(at(idx)->x()-x)*(at(idx)->x()-x) +
			        	 (at(idx)->y()-y)*(at(idx)->y()-y);
			
				if(d < dist)
				{
			  		minIdx=idx;
					dist=d;
				}
			}
			
			if(minIdx>=0)
				(*point).push_back(new ValuesCollectorData(at(minIdx)->x(),
							       at(minIdx)->y(),
							       at(minIdx)->value(),
							       dist,minIdx));
					     		
		}			
		else
		{
			double val,xp,yp;
			val=matrix_->nearest(y,x,yp,xp);
			if(!same(val,matrix_->missing()))
			{  
				(*point).push_back(new ValuesCollectorData(xp,yp,val,-1.));
			}	
		}	
	}
}

void OdaXYDecoder::visit(MetaDataCollector& mdc)
{	
	for(map<string, string>::iterator key = mdc.begin(); key != mdc.end(); ++key )
	{	    
		if(information_.find(key->first) == information_.end() &&
		  mdc.attribute(key->first).group() == MetaDataAttribute::StatsGroup)
		{
			  computeStats();
			  break;
		}
	}
	
	MetviewIcon::visit(mdc);
}  

void OdaXYDecoder::customisedPoints(const Transformation& transformation, const std::set<string>& needs, CustomisedPointsList& points, bool)
{
	customisedPoints(transformation, needs, points);
}

void OdaGeoDecoder::customisedPoints(const Transformation& transformation, const std::set<string>& needs, CustomisedPointsList& points, bool)
{
	customisedPoints(transformation, needs, points);
}

