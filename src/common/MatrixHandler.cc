/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file MatrixHandler.cc
    \brief

    Changes:

*/

#include "MatrixHandler.h"

MatrixHandler::MatrixHandler(const magics::AbstractMatrix& matrix) :
    AbstractMatrix(), AbstractPoints(), matrix_(matrix), min_(INT_MAX), max_(-INT_MAX), tile_(false) {}

MatrixHandler::MatrixHandler(const MatrixHandler& matrix) :
    AbstractMatrix(), AbstractPoints(), matrix_(matrix), min_(INT_MAX), max_(-INT_MAX), tile_(false) {}

double MatrixHandler::nearest(double row, double column, double& rowOut, double& columnOut) const {
    rowOut    = -1;
    columnOut = -1;
    return nearest(row, column);
}

double MatrixHandler::nearest(double row, double column) const {
    if (columns() == 0 || rows() == 0)
        return matrix_.missing();

    if (column < left() && !same(column, left()))
        return matrix_.missing();
    if (column > right() && !same(column, right()))
        return matrix_.missing();
    if (row < bottom() && !same(row, bottom()))
        return matrix_.missing();
    if (row > top() && !same(row, top()))
        return matrix_.missing();

    int ri = rowIndex(row);
    int ci = columnIndex(column);
    if (ri != -1 && ci != -1)
        return (*this)(ri, ci);
    double x1, x2;
    double y1, y2;
    int r1, r2, c1, c2;
    vector<double> distances;
    map<double, pair<std::pair<double, double>, pair<int, int> > > helper;
    vector<std::pair<std::pair<double, double>, pair<int, int> > > coordinates;
    if (ri != -1) {
        boundColumn(column, x1, c1, x2, c2);
        if (x1 != -1)
            coordinates.push_back(make_pair(make_pair(row, x1), std::make_pair(ri, c1)));
        if (x2 != -1)
            coordinates.push_back(make_pair(make_pair(row, x2), std::make_pair(ri, c2)));
    }
    else if (ci != -1) {
        boundRow(row, y1, r1, y2, r2);
        if (y1 != -1)
            coordinates.push_back(make_pair(make_pair(y1, column), std::make_pair(r1, ci)));
        if (y2 != -1)
            coordinates.push_back(make_pair(make_pair(y2, column), std::make_pair(r2, ci)));
    }
    else {
        boundColumn(column, x1, c1, x2, c2);
        boundRow(row, y1, r1, y2, r2);

        // 4 points ...
        // x1, y1 - x2, y1 -  x1, y2 - x2, y2
        // find the nearest...
        if (y1 != -1) {
            if (x1 != -1)
                coordinates.push_back(make_pair(make_pair(y1, x1), std::make_pair(r1, c1)));
            if (x2 != -1)
                coordinates.push_back(make_pair(make_pair(y1, x2), std::make_pair(r1, c2)));
        }
        if (y2 != -1) {
            if (x1 != -1)
                coordinates.push_back(make_pair(make_pair(y2, x1), std::make_pair(r2, c1)));
            if (x2 != -1)
                coordinates.push_back(make_pair(make_pair(y2, x2), std::make_pair(r2, c2)));
        }
    }

    for (vector<pair<std::pair<double, double>, pair<int, int> > >::iterator coord = coordinates.begin();
         coord != coordinates.end(); ++coord) {
        double distance = (row - coord->first.first) * (row - coord->first.first) +
                          (column - coord->first.second) * (column - coord->first.second);
        // cout << distance << " [ " << coord->first.first << ", " <<
        // coord->first.second << "]" << endl;
        distances.push_back(distance);
        helper.insert(make_pair(distance, *coord));
    }

    if (distances.empty())
        return matrix_.missing();

    double min = *std::min_element(distances.begin(), distances.end());

    map<double, pair<std::pair<double, double>, pair<int, int> > >::iterator n = helper.find(min);

    if (n == helper.end())
        return matrix_.missing();

    return (*this)(n->second.second.first, n->second.second.second);
}

double MatrixHandler::interpolate(double i, double j) const {
    if (columns() == 0 || rows() == 0)
        return matrix_.missing();

    if (j < left()) {
        if (!same(j, left()))
            return matrix_.missing();
        j = left();  // not really necessary but now there will be no more obscur
        // rounding problems!
    }
    if (j > right()) {
        if (!same(j, right()))
            return matrix_.missing();
        j = right();  // id left
    }
    if (i < bottom()) {
        if (!same(i, bottom()))
            return matrix_.missing();
        i = bottom();  // id left
    }
    if (i > top()) {
        if (!same(i, top()))
            return matrix_.missing();
        i = top();  // id left
    }

    int ii = rowIndex(i);
    if (ii == -1) {
        // interpolate between 2 rows.
        double v1, v2;
        int i1, i2;
        boundRow(i, v1, i1, v2, i2);

        if (i1 == -1 || i2 == -1)
            return missing();
        internal_ = true;
        double a  = (*this).interpolate(v1, j);
        internal_ = false;

        if (same(a, missing()))
            return missing();
        if (i1 == i2 || v1 == v2)
            return a;  // already seen with Akima760 (da,db ---> zero divide !)

        internal_ = true;
        double b  = (*this).interpolate(v2, j);
        internal_ = false;
        if (same(b, missing()))
            return missing();

        double da  = (v2 - i) / (v2 - v1);
        double db  = (i - v1) / (v2 - v1);
        double val = (a * da) + (b * db);
        return val;
    }
    int jj = columnIndex(j);
    if (jj == -1) {
        double v1, v2;
        int i1, i2;
        boundColumn(j, v1, i1, v2, i2);
        if (i1 == -1 || i2 == -1)
            return missing();

        double a = (*this)(ii, i1);
        if (same(a, missing()))
            return missing();

        if (i1 == i2 || v1 == v2)
            return a;  // Id rows

        double b = (*this)(ii, i2);

        if (same(b, missing()))
            return missing();

        double da  = (v2 - j) / (v2 - v1);
        double db  = (j - v1) / (v2 - v1);
        double val = (a * da) + (b * db);
        return val;
    }

    return (*this)(ii, jj);
}

void MatrixHandler::setMinMax() const {
    int nb_rows    = rows();
    int nb_columns = columns();
    double missing = matrix_.missing();

    for (int r = 0; r < nb_rows; r++) {
        for (int c = 0; c < nb_columns; c++) {
            double val = (*this)(r, c);
            if (val == missing)
                continue;
            if (val < min_)
                min_ = val;
            if (val > max_)
                max_ = val;
        }
    }
}

double MatrixHandler::min() const {
    if (min_ != INT_MAX)
        return min_;

    setMinMax();
    return min_;
}

double MatrixHandler::max() const {
    if (max_ != -INT_MAX)
        return max_;

    setMinMax();
    return max_;
}

void MatrixHandler::setToFirst() {
    if (points_.empty()) {
        int nb_rows    = rows();
        int nb_columns = columns();

        points_.reserve(nb_rows * nb_columns);

        for (int r = 0; r < nb_rows; r++) {
            for (int c = 0; c < nb_columns; c++) {
                if (matrix_.accept(column(r, c), row(r, c)))
                    if (!same((*this)(r, c), matrix_.missing()))
                        points_.push_back(new UserPoint(column(r, c), row(r, c), (*this)(r, c)));
            }
        }
    }
    current_ = points_.begin();
}

bool MatrixHandler::hasMissingValues() const {
    for (int r = 0; r < rows(); r++) {
        for (int c = 0; c < columns(); c++) {
            if (operator()(r, c) == matrix_.missing())
                return true;
        }
    }
    return false;
}

void MatrixHandler::applyScaling(double scaling, double offset) {
    // matrix_.applyScaling(scaling, offset);
}
