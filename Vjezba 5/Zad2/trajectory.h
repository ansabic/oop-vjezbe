//
// Created by antonio on 13. 11. 2021..
//
#include "point.h"
#include <cmath>

#ifndef OPVJEZBE_TRAJECTORY_H
#define OPVJEZBE_TRAJECTORY_H


class trajectory {
    double k;
    double l;

    double paramX;
    double paramY;

    bool parametrized;
    bool parametrizedX;

    point limitFrom;
    point limitTo;

    bool length;

    bool positive{};
public:
    trajectory(point gunPosition, double angle);

    trajectory(point p1, point p2);

    bool isParametrized() const;

    bool isParametrizedX() const;

    bool isLength() const;

    double getParamX() const;

    double getParamY() const;

    double getK() const;

    double getL() const;

    point getLimitFrom() const;

    point getLimitTo() const;

    bool isPositive() const;

    point intersection(trajectory tr2) const;

    bool intersects(trajectory tr2) const;

};


#endif //OPVJEZBE_TRAJECTORY_H
