//
// Created by antonio on 12. 11. 2021..
//

#include "point.h"
#include <cstdlib>
#include <cmath>

point::point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

point::point() : point(0, 0, 0) {
}

point::point(long from, long to) : point((double) (random() % (to - from) + from),
                                         (double) (random() % (to - from) + from),
                                         (double) (random() % (to - from) + from)) {
}

double point::getX() const {
    return x;
}

double point::getY() const {
    return y;
}

double point::getZ() const {
    return z;
}

double point::distance2D(point p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

double point::distance3D(point p) const {
    return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2) + pow(z - p.z, 2));
}
