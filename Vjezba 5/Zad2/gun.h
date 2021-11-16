//
// Created by antonio on 12. 11. 2021..
//
#include "point.h"

#ifndef OPVJEZBE_GUN_H
#define OPVJEZBE_GUN_H


class gun {
    point position;
    int maxLoad;
    int currentLoad;
public:
    gun(point p, int maxLoad);

    void shoot();

    void reload();

    point getPosition() const;

    bool isEmpty() const;
};


#endif //OPVJEZBE_GUN_H
