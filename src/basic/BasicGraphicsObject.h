/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file BasicGraphicsObject.h
    \brief Implementation of BasicGraphicsObject class.
    \author Meteorological Visualisation Section, ECMWF

    Started: March 2004

*/
#ifndef BasicGraphicsObject_H
#define BasicGraphicsObject_H

#include "magics.h"

#include <algorithm>

#include "AutoVector.h"
#include "MagException.h"
#include "MagLog.h"

namespace magics {

class BaseDriver;

class Layout;
class Transformation;

class BasicGraphicsObjectContainer;

class BasicGraphicsObject {
public:
    BasicGraphicsObject();
    virtual ~BasicGraphicsObject();

    virtual bool reproject(BasicGraphicsObjectContainer&) const;

    virtual void redisplay(const BaseDriver&) const;

    void parent(BasicGraphicsObjectContainer* parent);
    void check();
    BasicGraphicsObjectContainer& parent();

    void makeBrother(const BasicGraphicsObject& brother) { parent_ = brother.parent_; }

    virtual void release() {}

    bool isOrphan() { return parent_ == 0; }
    void orphan() { parent_ = 0; }

    void name(const string& name) { name_ = name; }
    const string& name() const { return name_; }
    bool root() { return parent_ == 0; }

    void widthResolution(int width) { widthResolution_ = width; }
    void heightResolution(int height) { heightResolution_ = height; }
    int widthResolution() const { return widthResolution_; }
    int heightResolution() const { return heightResolution_; }

    virtual bool buildTree(const Layout&, unsigned int, const BaseDriver&) const { return false; }

protected:
    virtual void print(ostream&) const;
    int widthResolution_;
    int heightResolution_;

    BasicGraphicsObjectContainer* parent_;  // Just for reference : do not delete!
    string name_;

private:
    // No copy allowed
    // BasicGraphicsObject& operator=(const BasicGraphicsObject&);

    // -- Friends
    friend ostream& operator<<(ostream& s, const BasicGraphicsObject& p) {
        p.print(s);
        return s;
    }
};

/*!

 Inherited by SceneLayer

 \sa SceneLayer
*/
class BasicGraphicsObjectContainer : public BasicGraphicsObject {
public:
    BasicGraphicsObjectContainer() {}
    virtual ~BasicGraphicsObjectContainer();

    void push_back(BasicGraphicsObject* object);
    void push_last(BasicGraphicsObject* object);

    void clear();
    bool buildTree(const Layout&, unsigned int, const BaseDriver&) const override;
    void release() override;
    void remove(BasicGraphicsObject* object);

    void visit(const BaseDriver&) const;

    virtual void getDriverInfo(double& x, double& y, double& width, double& height);

    virtual double absoluteY() const;

    virtual double absoluteWidth() const;

    virtual double absoluteHeight() const;

    virtual double absoluteWidth(double width);

    virtual double absoluteHeight(double height);

    virtual const Transformation& transformation() const;
    const vector<BasicGraphicsObject*>& objects();

protected:
    virtual void print(ostream&) const override;
    vector<BasicGraphicsObject*> objects_;
    vector<BasicGraphicsObject*> last_;
};

}  // namespace magics
#endif
