//
// Created by antonio on 12. 11. 2021..
//
#include "point.h"

#ifndef OPVJEZBE_TARGET_H
#define OPVJEZBE_TARGET_H

#include "trajectory.h"

class target {
    point bottomLeftPoint;
    point upperRightPoint;
    bool hit{};
public:
    target();

    target(point bl, point ur, bool hit = false);

    bool onTrajectory(trajectory tr);

    bool isHit() const;

    void kill();
};


#endif //OPVJEZBE_TARGET_H
