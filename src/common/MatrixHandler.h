/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

/*! \file MatrixHandler.h
    \brief Definition of the Template class MatrixHandler.

    Magics Team - ECMWF 2004

    Started: Wed 18-Feb-2004

    Changes:

*/

#ifndef MatrixHandler_H
#define MatrixHandler_H

#include "AutoVector.h"
#include "BasePointsHandler.h"
#include "Matrix.h"
#include "ProjP.h"
#include "Timer.h"
#include "Transformation.h"
#include "magics.h"

namespace magics {

class MatrixHandler : public AbstractMatrix, public AbstractPoints {
public:
    MatrixHandler(const AbstractMatrix& matrix);
    MatrixHandler(const MatrixHandler& matrix);

    virtual ~MatrixHandler() override {}

    virtual bool tile() { return tile_; }

    virtual double operator()(int i, int j) const override { return matrix_(i, j); }

    virtual int rowIndex(double r) const override { return matrix_.rowIndex(r); }
    virtual int columnIndex(double c) const override { return matrix_.columnIndex(c); }
    virtual bool akimaEnable() const override { return matrix_.akimaEnable(); }
    virtual bool delegate() const override { return matrix_.delegate(); }

    virtual void boundRow(double r, double& row1, int& index1, double& row2, int& index2) const override {
        return matrix_.boundRow(r, row1, index1, row2, index2);
    }
    virtual void boundColumn(double r, double& column1, int& index1, double& column2, int& index2) const override {
        return matrix_.boundColumn(r, column1, index1, column2, index2);
    }

    virtual double left() const override { return matrix_.left(); }
    virtual double bottom() const override { return matrix_.bottom(); }
    virtual double right() const override { return matrix_.right(); }
    virtual double top() const override { return matrix_.top(); }

    double x(double x, double y) const override { return matrix_.x(x, y); }
    double y(double x, double y) const override { return matrix_.y(x, y); }

    virtual double nearest(double row, double column, double& rowOut, double& columnOut) const override;
    virtual double nearest(double row, double column) const override;

    virtual double interpolate(double i, double j) const override;
    virtual double nearest(double row, double column, double& rowOut, double& columnOut) const {
        rowOut    = -1;
        columnOut = -1;
        return nearest(row, column);
    }
    virtual double nearest(double row, double column) const;
    virtual double interpolate(double i, double j) const;

    void setTile() { tile_ = true; }

    virtual int rows() const override { return matrix_.rows(); }
    virtual int columns() const override { return matrix_.columns(); }
    virtual int lowerRow(double v) const override { return matrix_.lowerRow(v); }
    virtual int lowerColumn(double v) const override { return matrix_.lowerColumn(v); }
    virtual double XResolution() const override { return matrix_.XResolution(); }
    virtual double YResolution() const override { return matrix_.YResolution(); }
    virtual double width() const override { return matrix_.width(); }
    virtual double height() const override { return matrix_.height(); }

    virtual const AbstractMatrix& original() const override { return delegate() ? matrix_ : matrix_.original(); }
    virtual int firstRow() const override { return matrix_.firstRow(); }
    virtual int nextRow(int i, int f) const override { return matrix_.nextRow(i, f); }
    virtual int firstColumn() const override { return matrix_.firstColumn(); }
    virtual int nextColumn(int j, int f) const override { return matrix_.nextColumn(j, f); }

    virtual void setMinMax() const;

    double min() const override;

    double max() const override;

    virtual double minX() const override { return matrix_.minX(); }
    virtual double maxX() const override { return matrix_.maxX(); }
    virtual double minY() const override { return matrix_.minY(); }
    virtual double maxY() const override { return matrix_.maxY(); }

    // Implements the AbstractPoints interface
    virtual void setToFirst() override;

    //! Method to test the end of collection.
    virtual bool more() override { return current_ != points_.end(); }

    virtual bool accept(double x, double y) const override { return matrix_.accept(x, y); }

    virtual UserPoint& current() override { return **current_; }

    virtual void advance() override { current_++; }

    virtual vector<double>& rowsAxis() const override { return const_cast<MatrixHandler*>(this)->matrix_.rowsAxis(); }
    virtual vector<double>& columnsAxis() const override {
        return const_cast<MatrixHandler*>(this)->matrix_.columnsAxis();
    }

    virtual double row(int i, int j) const override { return matrix_.row(i, j); }
    virtual double column(int i, int j) const override { return matrix_.column(i, j); }

    virtual double regular_row(int i) const override { return matrix_.regular_row(i); }
    virtual double regular_column(int i) const override { return matrix_.regular_column(i); }

    virtual double missing() const override { return matrix_.missing(); }
    virtual bool hasMissingValues() const override;

    virtual void applyScaling(double scaling, double offset) override;

    const AbstractMatrix& matrix() { return matrix_; }

    MatrixHandler* getReady(const Transformation& transformation) { return matrix_.getReady(transformation); }

protected:
    const AbstractMatrix& matrix_;
    mutable AutoVector<UserPoint> points_;
    mutable AutoVector<UserPoint>::const_iterator current_;
    mutable double min_;
    mutable double max_;
    mutable bool internal_;
    mutable bool tile_;

    virtual void print(ostream& s) const override { s << "MatrixHandler[" << matrix_ << "]"; }
};

class TransformMatrixHandler : public MatrixHandler {
public:
    TransformMatrixHandler(const AbstractMatrix& matrix) : MatrixHandler(matrix) {}

    double operator()(int i, int j) const override { return matrix_(i + minrow_, j + mincolumn_); }

    double left() const override { return minx_; }
    double right() const override { return maxx_; }
    double bottom() const override { return miny_; }
    double top() const override { return maxy_; }

    void set();

    int rows() const override { return maxrow_ - minrow_ + 1; }
    int columns() const override { return maxcolumn_ - mincolumn_ + 1; }
    double regular_row(int index) const override { return fastRows_[index]; }
    double regular_column(int index) const override { return fastColumns_[index]; }
    double real_row(int index) const { return fastRows_[index]; }
    double real_column(int index) const { return fastColumns_[index]; }
    inline double column(int, int j) const override { return fastColumns_[j]; }
    virtual double real_row(double row, double) const { return row; }
    virtual double real_column(double, double column) const { return column; }
    inline double row(int i, int) const override { return fastRows_[i]; }
    virtual bool hasMissingValues() const override { return matrix_.hasMissingValues(); }
    double interpolate(double i, double j) const override { return matrix_.interpolate(i, j); }
    double missing() const override { return matrix_.missing(); }
    int lowerRow(double r) const override;
    int lowerColumn(double c) const override;
    int upperRow(double r) const;
    int upperColumn(double c) const;

protected:
    int minrow_;
    int maxrow_;
    int mincolumn_;
    int maxcolumn_;
    map<double, int> rowsMap_;
    map<double, int> columnsMap_;
    vector<double> fastRows_;
    vector<double> fastColumns_;
    double minx_;
    double maxx_;
    double miny_;
    double maxy_;

    bool rowrevert_;
    bool columnrevert_;
};

class DelegateMatrixHandler : public MatrixHandler {
public:
    DelegateMatrixHandler(const AbstractMatrix& matrix) : MatrixHandler(matrix) {}

    double interpolate(double row, double column) const { return matrix_.interpolate(row, column); }
    double nearest(double row, double column) const { return matrix_.nearest(row, column); }

    double column(int i, int j) { return matrix_.column(i, j); }
    double row(int i, int j) { return matrix_.row(i, j); }
    double left() const { return matrix_.left(); }
    double bottom() const { return matrix_.bottom(); }
    double right() const { return matrix_.right(); }
    double top() const { return matrix_.top(); }

protected:
};

class Proj4MatrixHandler : public MatrixHandler {
public:
    Proj4MatrixHandler(const AbstractMatrix& matrix, const string&);

    double interpolate(double row, double column) const override;
    double nearest(double row, double column) const override;

    double column(int, int) const override;
    double row(int, int) const override;

    bool delegate() const override { return true; }

protected:
    double minx_;
    double maxx_;
    double miny_;
    double maxy_;

    LatLonProjP projHelper_;

    virtual void print(ostream& s) const override { s << "Proj4MatrixHandler[]"; }
};

class RotatedMatrixHandler : public MatrixHandler {
public:
    RotatedMatrixHandler(const AbstractMatrix& matrix, double lat, double lon);

    double interpolate(double row, double column) const;
    double nearest(double row, double column) const;

    double column(int, int) const;
    double row(int, int) const;

    bool delegate() const { return true; }
    pair<double, double> unrotate(double, double) const;
    pair<double, double> rotate(double, double) const;

protected:
    double minx_;
    double maxx_;
    double miny_;
    double maxy_;
    double southPoleLat_;
    double southPoleLon_;
};

class BoxMatrixHandler : public TransformMatrixHandler {
public:
    BoxMatrixHandler(const AbstractMatrix& matrix, const Transformation& transformation);

    virtual const AbstractMatrix& original() const override;

    virtual void boundRow(double r, double& row1, int& index1, double& row2, int& index2) const override;

    virtual void boundColumn(double r, double& column1, int& index1, double& column2, int& index2) const override;
    int rowIndex(double r) const override;

    int columnIndex(double c) const override;

    virtual ~BoxMatrixHandler() override { delete original_; }

    // Implements the AbstractPoints interface
    virtual bool accept(double x, double y) const override { return transformation_.in(x, y); }

    double minX() const override { return std::min(transformation_.getMinX(), transformation_.getMaxX()); }
    double maxX() const override { return std::max(transformation_.getMinX(), transformation_.getMaxX()); }
    double minY() const override { return std::min(transformation_.getMinY(), transformation_.getMaxY()); }
    double maxY() const override { return std::max(transformation_.getMinY(), transformation_.getMaxY()); }

protected:
    const Transformation& transformation_;
    mutable BoxMatrixHandler* original_;

    virtual void print(ostream& s) const override { s << "BoxMatrixHandler[]"; }
};

class GeoBoxMatrixHandler : public TransformMatrixHandler {
public:
    GeoBoxMatrixHandler(const AbstractMatrix& matrix, const Transformation& transformation);

    virtual const AbstractMatrix& original() const override;

    int columns() const override { return columnsMap_.size(); }
    int rows() const override { return rowsMap_.size(); }

    int rowIndex(double r) const override;

    int columnIndex(double c) const override;

    inline double column(int, int column) const override { return regular_longitudes_[column]; }
    inline double row(int row, int) const override { return regular_latitudes_[row]; }
    double operator()(int row, int column) const override;

    int lowerRow(double r) const override;

    int lowerColumn(double c) const override;

    double regular_row(int i) const override { return regular_latitudes_[i]; }
    double regular_column(int i) const override { return regular_longitudes_[i]; }

    virtual ~GeoBoxMatrixHandler() override { delete original_; }

    // Implements the AbstractPoints interface
    virtual bool accept(double x, double y) const override { return transformation_.in(x, y); }

    double minX() const override { return std::min(transformation_.getMinX(), transformation_.getMaxX()); }
    double maxX() const override { return std::max(transformation_.getMinX(), transformation_.getMaxX()); }
    double minY() const override { return std::min(transformation_.getMinY(), transformation_.getMaxY()); }
    double maxY() const override { return std::max(transformation_.getMinY(), transformation_.getMaxY()); }

    double left() const override { return regular_longitudes_.front(); }
    double bottom() const override { return regular_latitudes_.front(); }
    double right() const override { return regular_longitudes_.back(); }
    double top() const override { return regular_latitudes_.back(); }

    virtual void boundRow(double r, double& row1, int& index1, double& row2, int& index2) const override;

    virtual void boundColumn(double r, double& column1, int& index1, double& column2, int& index2) const override;

    virtual void print(ostream& s) const override { s << "GeoBoxMatrixHandler[]"; }

protected:
    const Transformation& transformation_;
    mutable GeoBoxMatrixHandler* original_;
    mutable map<int, int> rows_;
    mutable map<int, int> columns_;
    vector<double> regular_latitudes_;
    vector<double> regular_longitudes_;
};

class MonotonicIncreasingMatrixHandler : public MatrixHandler {
public:
    MonotonicIncreasingMatrixHandler(const AbstractMatrix& matrix);
    virtual ~MonotonicIncreasingMatrixHandler() override {}

    double operator()(int i, int j) const override;

    int rows() const override { return matrix_.rows(); }
    virtual int columns() const override { return matrix_.columns(); }
    virtual double regular_column(int i) const override {
        return matrix_.regular_column(const_cast<MonotonicIncreasingMatrixHandler*>(this)->columns_[i]);
    }
    virtual double regular_row(int j) const override {
        return matrix_.regular_row(const_cast<MonotonicIncreasingMatrixHandler*>(this)->rows_[j]);
    }
    virtual double interpolate(double i, double j) const override { return matrix_.interpolate(i, j); }
    virtual double missing() const override { return matrix_.missing(); }
    void print();

    int lowerRow(double r) const override;

    int lowerColumn(double c) const override;

protected:
    map<int, int> rows_;
    map<int, int> columns_;
    map<double, int> newRowsMap_;
    map<double, int> newColumnsMap_;
};

class OriginalMatrixHandler : public MatrixHandler {
public:
    OriginalMatrixHandler(AbstractMatrix& matrix) : MatrixHandler(matrix.original()) {}
};

class ThinningMatrixHandler : public MatrixHandler {
public:
    ThinningMatrixHandler(const AbstractMatrix& matrix, int fr, int fc);

    int rows() const { return rowIndex_.size(); }
    int columns() const { return columnIndex_.size(); }

    double operator()(int row, int column) const { return matrix_(rowIndex(row), columnIndex(column)); }
    double column(int row, int column) const { return matrix_.column(rowIndex(row), columnIndex(column)); }
    double row(int row, int column) const { return matrix_.row(rowIndex(row), columnIndex(column)); }
    double regular_row(int row) const { return matrix_.regular_row(rowIndex(row)); }
    double regular_column(int column) const { return matrix_.regular_column(columnIndex(column)); }

protected:
    int columnIndex(int column) const;
    int rowIndex(int row) const;
    int frequencyRow_;
    int frequencyColumn_;
    map<int, int> rowIndex_;
    map<int, int> columnIndex_;
};

}  // namespace magics
#endif
