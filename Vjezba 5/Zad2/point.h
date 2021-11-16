//
// Created by antonio on 12. 11. 2021..
//

#ifndef OPVJEZBE_POINT_H
#define OPVJEZBE_POINT_H


class point {
    double x;
    double y;
    double z;
public:
    point();

    point(double x, double y, double z);

    point(long from, long to);

    double getX() const;

    double getY() const;

    double getZ() const;

    double distance2D(point p) const;

    double distance3D(point p) const;
};


#endif //OPVJEZBE_POINT_H
