/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

// File BasicGraphicsObject.cc
// Magics Team - ECMWF 2004

#include "BasicGraphicsObject.h"
#include "BaseDriver.h"

using namespace magics;
BasicGraphicsObject::BasicGraphicsObject() : parent_(0) {}

BasicGraphicsObject::~BasicGraphicsObject() {}

bool BasicGraphicsObject::reproject(BasicGraphicsObjectContainer&) const {
    MagLog::error() << "BasicGraphicsObject::reproject(...)--->Need to be implemented!\n";
    ASSERT(0);
    return false;
}

void BasicGraphicsObject::redisplay(const BaseDriver&) const {
    MagLog::dev() << "BasicGraphicsObject::redisplay(...)--->Not yet implemented\n";
}

void BasicGraphicsObject::parent(BasicGraphicsObjectContainer* parent) {
    // ASSERT(parent_ == 0);
    parent_ = parent;
}

void BasicGraphicsObject::print(ostream& out) const {
    out << "BasicGraphicsObject[";
    out << "]";
}

void BasicGraphicsObjectContainer::print(ostream& out) const {
    out << "BasicGraphicsObjectContainer[";
    for (vector<BasicGraphicsObject*>::const_iterator object = objects_.begin(); object != objects_.end(); ++object)
        out << **object << endl;
    out << "]";
}


bool BasicGraphicsObjectContainer::buildTree(const Layout& parent, unsigned int frame, const BaseDriver& driver) const {
    bool more = false;
    for (vector<BasicGraphicsObject*>::const_iterator object = objects_.begin(); object != objects_.end(); ++object) {
        if ((*object)->buildTree(parent, frame, driver))
            more = true;
    }
    return more;
}

void BasicGraphicsObjectContainer::visit(const BaseDriver& driver) const {
    for (vector<BasicGraphicsObject*>::const_iterator object = objects_.begin(); object != objects_.end(); ++object)
        (*object)->redisplay(driver);
    for (vector<BasicGraphicsObject*>::const_iterator object = last_.begin(); object != last_.end(); ++object)
        (*object)->redisplay(driver);
}

void BasicGraphicsObjectContainer::getDriverInfo(double& x, double& y, double& width, double& height) {
    if (parent_)
        parent_->getDriverInfo(x, y, width, height);
}

double BasicGraphicsObjectContainer::absoluteY() const  // absolute position from the root
{
    ASSERT(parent_);
    return parent_->absoluteY();
}

double BasicGraphicsObjectContainer::absoluteWidth() const  // absolute position from the root
{
    ASSERT(parent_);
    return parent_->absoluteWidth();
}

double BasicGraphicsObjectContainer::absoluteHeight() const  // absolute position from the root
{
    ASSERT(parent_);
    return parent_->absoluteHeight();
}

double BasicGraphicsObjectContainer::absoluteWidth(double width)  // absolute position from the root
{
    ASSERT(parent_);
    return parent_->absoluteWidth(width);
}

double BasicGraphicsObjectContainer::absoluteHeight(double height)  // absolute position from the root
{
    ASSERT(parent_);
    return parent_->absoluteHeight(height);
}

const Transformation& BasicGraphicsObjectContainer::transformation() const  // returns the Transformation
{
    ASSERT(parent_);
    return parent_->transformation();
}

const vector<BasicGraphicsObject*>& BasicGraphicsObjectContainer::objects() {  //
    // first we add
    for (vector<BasicGraphicsObject*>::iterator l = last_.begin(); l != last_.end(); ++l)
        objects_.push_back(*l);
    last_.clear();
    return objects_;
}

BasicGraphicsObjectContainer::~BasicGraphicsObjectContainer() {
    for (vector<BasicGraphicsObject*>::iterator object = objects_.begin(); object != objects_.end(); ++object) {
        if (*object)
            delete *object;
        *object = 0;
    }
    objects_.clear();
}

void BasicGraphicsObjectContainer::push_back(BasicGraphicsObject* object) {
    object->check();  // here we make sure that the object is not in 2 containres!
    objects_.push_back(object);
    object->parent(this);
}

void BasicGraphicsObjectContainer::push_last(BasicGraphicsObject* object) {
    object->check();  // here we make sure that the object is not in 2 containres!
    last_.push_back(object);
    object->parent(this);
}

void BasicGraphicsObjectContainer::clear() {
    objects_.erase(objects_.begin(), objects_.end());
}
void BasicGraphicsObjectContainer::release() {
    MagLog::debug() << "CLEAR CONTAINER" << objects_.size() << endl;
    for (vector<BasicGraphicsObject*>::iterator object = objects_.begin(); object != objects_.end(); ++object) {
        (*object)->release();
    }
    objects_.clear();
}

void BasicGraphicsObjectContainer::remove(BasicGraphicsObject* object) {
    objects_.erase(std::remove(objects_.begin(), objects_.end(), object), objects_.end());
}
void BasicGraphicsObject::check() {
    if (parent_)
        parent_->remove(this);
}

BasicGraphicsObjectContainer& BasicGraphicsObject::parent() {
    ASSERT(parent_);
    return *parent_;
}
