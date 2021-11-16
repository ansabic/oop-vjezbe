//
// Created by antonio on 12. 11. 2021..
//

#include "target.h"
#include "trajectory.h"

target::target(point bl, point ur, bool hit) {
    bottomLeftPoint = bl;
    upperRightPoint = ur;
    this->hit = hit;
}

void target::kill() {
    hit = true;
}

bool target::isHit() const {
    return hit;
}

bool target::onTrajectory(trajectory tr) {
    point bottomRightPoint = point(upperRightPoint.getX(), bottomLeftPoint.getY(), 0);
    point upperLeftPoint = point(bottomLeftPoint.getX(), upperRightPoint.getY(), 0);
    trajectory left = trajectory(bottomLeftPoint, upperLeftPoint);
    trajectory bottom = trajectory(bottomLeftPoint, bottomRightPoint);
    trajectory right = trajectory(bottomRightPoint, upperRightPoint);
    trajectory up = trajectory(upperLeftPoint, upperRightPoint);
    if (left.intersects(tr) || bottom.intersects(tr) || right.intersects(tr) || up.intersects(tr))
        return true;
    return false;
}

target::target() : bottomLeftPoint(point()), upperRightPoint(point()) {

}
