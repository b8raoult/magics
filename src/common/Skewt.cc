/*
 * (C) Copyright 1996-2018 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include <Skewt.h>
#include <Polyline.h>
#include "SciMethods.h"
#include "MagJSon.h"

using namespace magics;

//=====================================================
//
// Skewt
//
//=====================================================

Skewt::Skewt()
{
}

Skewt::~Skewt()
{
}

void Skewt::print(ostream& out) const
{
    out << "Skewt[";
    out << "]";
}

#define sinus  -0.7071
#define cosinus  0.7071

//the right edge of the real skew-t area. To the right of
//lays the info area to plot the wind profile.
static double maxpcx;

void Skewt::init()
{
    //When default input visualiser values are specified: we assing a meaningful default
    if( x_min_ == 0 && x_max_ == 100 ) //temperature (K)
    {
        x_min_ = -90;
        x_max_ = 50;
    }

    if ( y_min_ == 0 && y_max_ == 100 ) //pressure (hPa)
    {
        y_min_ = 1060.;
        y_max_ = 100;
    }

    assert(y_min_ > 0 && y_max_ > 0);
    assert(y_min_ > y_max_);

    //To have a proper ascpect ratio we always work with a 100x100 rectangle
    minPCX_=0;
    maxPCX_=100;

    minPCY_=0;
    maxPCY_=100;

    // now we add 25% to the right for the info panel!
    maxpcx = maxPCX_;

    MagLog::dev() << "useful area width in skew-t: " << maxpcx << endl;
    maxPCX_ += (maxPCX_ - minPCX_)*(annotation_width_/100.);
    MagLog::dev() << "witdth set for skew-t in grid " << maxpcx << endl;
}

const double KAPPA=0.285611;

//Converts (t,p) coordinates to paper coordinates
PaperPoint Skewt::operator()(const UserPoint& xy)  const
{
    double t=xy.x(); //t is linear
    double p=(maxPCY_-minPCY_)*(log(y_min_)- log(xy.y()))/(log(y_min_)-log(y_max_));

    double tc=x_min_+(x_max_-x_min_)/2.;
    double x=(t-tc)*(maxpcx-minPCX_)/(0.5*(x_max_-x_min_))+(p-minPCY_);
    double y=p;

    return PaperPoint(x, y, xy.value());
}

PaperPoint Skewt::operator()(const PaperPoint& pt)  const
{
#if 0
    // UserPoint X = temperature in deg Y = Pressure in hPa
    // First we calculate theta and we rotate!
    double tempe = pt.x() *cosinus + pt.y()*sinus;
    double theta = - (pt.x() * sinus) + pt.y()*cosinus;

    double p = magics::pressureFromTheta(theta+273.15, tempe+273.15)/100;

    return PaperPoint(tempe, p);
#endif
    return PaperPoint(pt);
}

void Skewt::revert(const PaperPoint& pt, UserPoint& point)  const
{
    // UserPoint X = temperature in deg Y = Pressure in hPa
        // First we calculate theta and we rotate!
    double tempe = pt.x() *cosinus + pt.y()*sinus;
    double theta = - (pt.x() * sinus) + pt.y()*cosinus;

    double p = magics::pressureFromTheta(theta+273.15, tempe+273.15)/100;

    point.x_ = tempe;
    point.y_ = p;
}

void Skewt::revert(const vector< std::pair<double, double> > & in, vector< std::pair<double, double> > & out) const
{
    out.reserve(in.size());
    for (vector< std::pair<double, double> >::const_iterator p = in.begin(); p != in.end(); ++p) {
        double tempe = p->first *cosinus + p->second*sinus;
        double theta = - (p->first * sinus) + p->second*cosinus;

        double pt = magics::pressureFromTheta(theta+273.15, tempe+273.15)/100;
        MagLog::dev() << " tempe = " << tempe << "  Pressure = " << pt << endl;
        out.push_back(make_pair(tempe, pt));
    }

}

bool Skewt::needShiftedCoastlines()  const
{
    return false;
}

void Skewt::setMinMaxX(double min, double max)
{
    if ( min > 1000 || max > 1000) return;
    setMinX(min);
    setMaxX(max);
    init();
}

void Skewt::setMinMaxY(double min, double max)
{
    // Careful, Skewt are in pressure levels...
    if ( min < 50.)
    {
        MagLog::warning() << " Top Pressure reset to 50." << endl;
        min = 50.;
    }


    setMinY(max);
    setMaxY(min);
    init();
}

void Skewt::aspectRatio(double& width, double& height)
{
    Transformation::aspectRatio(width, height);
}

void Skewt::boundingBox(double& xmin, double& ymin, double& xmax, double& ymax)  const
{
    vector< std::pair<double, double> > geo;
    vector< std::pair<double, double> > xy;

    double xpcmax =  maxpcx;
    double xpcmin =  minPCX_;
    double ypcmax =  maxPCY_;
    double ypcmin =  minPCY_;
    xmin = x_min_;
    xmax = x_max_;
    ymin = y_max_;
    ymax = y_min_;

#if 0
    return;

    const double xs = (xpcmax- xpcmin)/99.;
    const double ys = (ypcmax- ypcmin)/99.;
    // Walk along the boundary...
    double x,y;
    for (int i = 0; i < 100; i++) {
        x = xpcmin +(i*xs);
        for (int i = 0; i < 100; i++) {
            y = ypcmin +(i*ys);
            double tempe =x *cosinus + y*sinus;
            double theta = - (x * sinus) + y*cosinus;
            double p = magics::pressureFromTheta(theta+273.15, tempe+273.15)/100;

            if ( xmin > tempe) xmin = tempe;
            if ( xmax < tempe) xmax = tempe;
            if ( ymin > p) ymin = p;
            if ( ymax < p) ymax = p;
        }
    }
#endif

}

double Skewt::getMinX()  const
{
    return -1.5;
}

double Skewt::getMinY()  const
{
    return y_min_;
}

double Skewt::getMaxX()  const
{
    return 1.5;;
}

double Skewt::getMaxY()  const
{
    return y_max_;
}

void Skewt::setMinX(double x)
{
    if ( x < x_min_ )
        x_min_ = x;
}

void Skewt::setMinY(double y)
{
    if ( y > y_min_ )
        y_min_ = y;
}

void Skewt::setMaxX(double x)
{
    if ( x > x_max_ )
        x_max_ = x;
}

void Skewt::setMaxY(double y)
{
    if ( y < y_max_ )
        y_max_ = y;
}

double Skewt::getMinPCX()  const
{

    return minPCX_;
}

double Skewt::getMinPCY()  const
{

    return minPCY_;
}

double Skewt::getMaxPCX()  const
{

    return maxPCX_;
}

double Skewt::getMaxPCY()  const
{
    return maxPCY_;
}

double Skewt::getMaxTestPCX () const{
    return maxpcx;
}

Polyline& Skewt::getPCBoundingBox() const
{
    if ( PCEnveloppe_->empty() ) {
        PCEnveloppe_->push_back(PaperPoint(getMinPCX(), getMinPCY()));
        PCEnveloppe_->push_back(PaperPoint(getMinPCX(), getMaxPCY()));
        PCEnveloppe_->push_back(PaperPoint(getMaxPCX(), getMaxPCY()));
        PCEnveloppe_->push_back(PaperPoint(getMaxPCX(), getMinPCY()));
        PCEnveloppe_->push_back(PaperPoint(getMinPCX(), getMinPCY()));
    }

    return *PCEnveloppe_;

}

Polyline& Skewt::getUserBoundingBox() const
{
    if ( userEnveloppe_->empty() ) {
        userEnveloppe_->push_back(PaperPoint(x_min_, y_min_));
        userEnveloppe_->push_back(PaperPoint(x_min_, y_max_));
        userEnveloppe_->push_back(PaperPoint(x_max_, y_max_));
        userEnveloppe_->push_back(PaperPoint(x_max_, y_min_));
        userEnveloppe_->push_back(PaperPoint(x_min_, y_min_));
    }

    return *userEnveloppe_;
}

void Skewt::setDefinition(const string& json)
{
    if(json.empty())
        return;

        MagJSon helper;
        helper.interpret(json);

        XmlNode node = **helper.tree_.firstElement();

        node.name("Skewt");
        set(node);
}

static void toxml2(string& out, const map<string, string>& def)
{
    ostringstream os;
    string sep = "";
    for (map<string, string>::const_iterator entry = def.begin(); entry != def.end(); ++entry ) {
        os << sep << "\"" << entry->first << "\" : \"" << entry->second << "\"";
        sep = ",\n";
    }

    out = os.str();
}

void Skewt::getNewDefinition(const UserPoint& ll, const UserPoint& ur, string& out) const
{
    map<string, string> def;
    def["subpage_map_projection"] = "Skewt";

    def["x_min"]= tostring(ll.x_);
    def["x_max"]= tostring(ur.x_);
    def["y_min"]= tostring(ll.y_);
    def["y_max"]= tostring(ur.y_);


    ::toxml2(out, def);

    out = "{" + out + "}";

    MagJSon helper;

    helper.interpret(out);
}

void Skewt::operator()(const Polyline& from,  BasicGraphicsObjectContainer& out) const
{
    if (from.empty())
            return;
        PaperPoint ll(getMinPCX(), getMinPCY());
        PaperPoint ur(maxpcx, getMaxPCY());
        boost::geometry::model::box<PaperPoint> box(ll, ur);
        boost::geometry::correct(box);
        if ( from.closed() ) {
            deque<PaperPoint> line;

            for (unsigned i = 0; i < from.size(); i++) {
                line.push_back(from.get(i));

            }

            boost::geometry::correct(line);
            vector<deque<PaperPoint> > result;
            boost::geometry::intersection(box, line, result);

            // Now we feed the graphic container!

            for (vector<deque<PaperPoint> >::iterator l = result.begin(); l != result.end(); l++)
            {
                Polyline* poly = from.getNew();

                for (deque<PaperPoint>::iterator point = l->begin(); point != l->end(); ++point)
                    poly->push_back(*point);

                if ( !poly->empty() )
                    out.push_back(poly);
            }
        }
        else {
            vector<PaperPoint> line;

            for (unsigned i = 0; i < from.size(); i++) {
                line.push_back(from.get(i));
            }
            boost::geometry::correct(line);
            vector<vector<PaperPoint> > result;
            boost::geometry::intersection(box, line, result);

            // Now we feed the graphic container!

            for (vector<vector<PaperPoint> >::iterator l = result.begin(); l != result.end(); l++)
            {
                Polyline* poly = from.getNew();

                for (vector<PaperPoint>::iterator point = l->begin(); point != l->end(); ++point)
                    poly->push_back(*point);

                if ( !poly->empty() )
                    out.push_back(poly);
            }
        }

}

bool Skewt::in(const PaperPoint& point) const
{
    static Polyline enveloppe;
         if ( enveloppe.empty()) {
             enveloppe.push_back(PaperPoint(getMinPCX(), getMinPCY()));
             enveloppe.push_back(PaperPoint(getMinPCX(), getMaxPCY()));
             enveloppe.push_back(PaperPoint(getMaxPCX(), getMaxPCY()));
             enveloppe.push_back(PaperPoint(getMaxPCX(), getMinPCY()));
             enveloppe.push_back(PaperPoint(getMinPCX(), getMinPCY()));
         }

         return boost::geometry::covered_by(point, enveloppe.polygon_);
}



//=====================================================
//
// SkewtInfo
//
//=====================================================

SkewtInfo::SkewtInfo()
{

}

SkewtInfo::~SkewtInfo()
{
}


void SkewtInfo::init()
{
    Skewt::init();

    reference_ = maxPCX_;
    minPCX_ = -1.5;
    maxPCX_ = 1.5;
    MagLog::dev() << "minPCY-->" << minPCY_ <<  " " << y_min_ << endl;
    MagLog::dev() << "maxPCY-->" << maxPCY_ << " " << y_max_ << endl;
    UserPoint min(0, y_min_);
    UserPoint max(0, y_max_);
    (*this)(min);
    (*this)(max);
}

void SkewtInfo::print(ostream& out) const
{
    out << "SkewtInfo[";
    out << "]";
}

PaperPoint SkewtInfo::operator()(const UserPoint& xy)  const
{
    //x=x
    //y=p
    //pressure is log
    double y=(maxPCY_-minPCY_)*(log(y_min_)- log(xy.y()))/(log(y_min_)-log(y_max_));
    return PaperPoint(xy.x(), y);
}

PaperPoint SkewtInfo::operator()(const PaperPoint& pt)  const
{
#if 0
    // UserPoint X = temperature in deg Y = Pressure in hPa
    // First we calculate theta and we rotate!
    double tempe = pt.x() *cosinus + pt.y()*sinus;
    double theta = - (pt.x() * sinus) + pt.y()*cosinus;

    double p = magics::pressureFromTheta(theta+273.15, tempe+273.15)/100;

    return PaperPoint(tempe, p);
#endif
    return PaperPoint(pt);
}

void SkewtInfo::revert(const PaperPoint& pt, UserPoint& point)  const
{
    // UserPoint X = temperature in deg Y = Pressure in hPa
        // First we calculate theta and we rotate!
        double tempe = pt.x() *cosinus + pt.y()*sinus;
        double theta = - (pt.x() * sinus) + pt.y()*cosinus;

        double p = magics::pressureFromTheta(theta+273.15, tempe+273.15)/100;

        point.x_ = tempe;
        point.y_ = p;

}

bool SkewtInfo::needShiftedCoastlines()  const
{
    return false;
}

void SkewtInfo::aspectRatio(double& width, double& height)
{
init();
    //Transformation::aspectRatio(width, height);
}

void SkewtInfo::boundingBox(double& xmin, double& ymin, double& xmax, double& ymax)  const
{
}

double SkewtInfo::getMinPCX()  const
{
    return -1.5;
}

double SkewtInfo::getMinPCY()  const
{
    return minPCY_;
}

double SkewtInfo::getMaxPCX()  const
{
    return 1.5;
}

double SkewtInfo::getMaxPCY()  const
{
    return maxPCY_;
}

Polyline& SkewtInfo::getPCBoundingBox() const
{
    if ( PCEnveloppe_->empty() ) {
        PCEnveloppe_->push_back(-1.5, getMinPCY());
        PCEnveloppe_->push_back(-1.5, getMaxPCY());
        PCEnveloppe_->push_back(1.5, getMaxPCY());
        PCEnveloppe_->push_back(1.5, getMinPCY());
        PCEnveloppe_->push_back(-1.5, getMinPCY());
    }

    return *PCEnveloppe_;
}

Polyline& SkewtInfo::getUserBoundingBox() const
{
    if ( userEnveloppe_->empty() ) {
        userEnveloppe_->push_back(PaperPoint(x_min_, y_min_));
        userEnveloppe_->push_back(PaperPoint(x_min_, y_max_));
        userEnveloppe_->push_back(PaperPoint(x_max_, y_max_));
        userEnveloppe_->push_back(PaperPoint(x_max_, y_min_));
        userEnveloppe_->push_back(PaperPoint(x_min_, y_min_));
    }

    return *userEnveloppe_;
}

void SkewtInfo::setDefinition(const string& json)
{
    if (json.empty())
            return;

    MagJSon helper;
    helper.interpret(json);

    XmlNode node = **helper.tree_.firstElement();
    node.name("SkewtInfo");
    set(node);
}

void SkewtInfo::getNewDefinition(const UserPoint& ll, const UserPoint& ur, string& out) const
{
    map<string, string> def;
    def["subpage_map_projection"] = "SkewtInfo";

    def["x_min"]= tostring(ll.x_);
            def["x_max"]= tostring(ur.x_);
        def["y_min"]= tostring(ll.y_);
        def["y_max"]= tostring(ur.y_);


    ::toxml2(out, def);

    out = "{" + out + "}";

    MagJSon helper;

    helper.interpret(out);
}
