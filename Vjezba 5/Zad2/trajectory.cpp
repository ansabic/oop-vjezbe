//
// Created by antonio on 13. 11. 2021..
//

#include "trajectory.h"

trajectory::trajectory(point gunPosition, double angle) {
    length = false;
    limitFrom = gunPosition;
    if (angle >= 0 && angle < 180)
        positive = true;
    else if (angle >= 180 && angle < 360)
        positive = false;
    if ((int) (angle) % 90 != 0) {
        k = tan(angle * M_PI / 180);
        l = gunPosition.getY() - k * gunPosition.getX();
        parametrized = false;
    } else if (((int) (angle) % 270 == 0 || (int) (angle) % 270 == 90) && (int) angle != 0) {
        paramX = gunPosition.getX();
        parametrized = true;
        parametrizedX = true;
    } else if ((int) (angle) % 180 == 0) {
        paramY = gunPosition.getY();
        parametrized = true;
        parametrizedX = false;
    }
}

trajectory::trajectory(point p1, point p2) {
    length = true;
    if (p1.getX() == p2.getX()) {
        parametrized = true;
        parametrizedX = true;
        paramX = p1.getX();
        double x1, x2;
        double y1, y2;
        if (p1.getX() < p2.getX()) {
            x1 = p1.getX();
            x2 = p2.getX();
        } else {
            x1 = p2.getX();
            x2 = p1.getX();
        }
        if (p1.getY() < p2.getY()) {
            y1 = p1.getY();
            y2 = p2.getY();
        } else {
            y1 = p2.getY();
            y2 = p1.getY();
        }
        limitFrom = point(x1, y1, 0);
        limitTo = point(x2, y2, 0);

    }
    if (p1.getY() == p2.getY()) {
        parametrized = true;
        parametrizedX = false;
        paramY = p1.getY();
        double x1, x2;
        double y1, y2;
        if (p1.getX() < p2.getX()) {
            x1 = p1.getX();
            x2 = p2.getX();
        } else {
            x1 = p2.getX();
            x2 = p1.getX();
        }
        if (p1.getY() < p2.getY()) {
            y1 = p1.getY();
            y2 = p2.getY();
        } else {
            y1 = p2.getY();
            y2 = p1.getY();
        }
        limitFrom = point(x1, y1, 0);
        limitTo = point(x2, y2, 0);
    } else {
        if (p1.getX() > p2.getX())
            positive = false;
        else
            positive = true;
        k = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
        l = p1.getY() - k * p1.getX();
    }
}

bool trajectory::isParametrized() const {
    return parametrized;
}

bool trajectory::isParametrizedX() const {
    return parametrizedX;
}

double trajectory::getParamY() const {
    return paramY;
}

double trajectory::getParamX() const {
    return paramX;
}

double trajectory::getK() const {
    return k;
}

double trajectory::getL() const {
    return l;
}

point trajectory::getLimitFrom() const {
    return limitFrom;
}

point trajectory::getLimitTo() const {
    return limitTo;
}

bool trajectory::isPositive() const {
    return positive;
}

point trajectory::intersection(trajectory tr2) const {
    if (this->isParametrized() && tr2.isParametrized()) {
        if (this->isParametrizedX() && !tr2.isParametrizedX())
            return {this->getParamX(), tr2.getParamY(), 0};
        return {tr2.getParamX(), this->getParamY(), 0};
    } else if (!this->isParametrized() && !tr2.isParametrized()) {
        return {(tr2.getL() - this->getL()) / (this->k - tr2.getK()),
                (tr2.getL() - this->getL()) / (this->k - tr2.getK()) *
                this->getK() + this->getL(), 0};
    } else if (this->isParametrized() && !tr2.isParametrized()) {
        if (this->isParametrizedX())
            return {this->getParamX(), tr2.getK() * this->getParamX() + tr2.getL(), 0};
        return {(this->getParamY() - tr2.getL()) / tr2.getK(), this->getParamY(), 0};
    } else if (!this->isParametrized() && tr2.isParametrized()) {
        if (tr2.isParametrizedX())
            return {tr2.getParamX(), this->getK() * tr2.getParamX() + this->getL(), 0};
        return {(tr2.getParamY() - this->getL()) / this->getK(), tr2.getParamY(), 0};
    }
}

bool trajectory::intersects(trajectory tr2) const {
    if (this->isParametrized() && tr2.isParametrized()) {
        if (this->isParametrizedX() && tr2.isParametrizedX()) {
            if (this->paramX != tr2.paramX)
                return false;
            else if ((tr2.isPositive() && this->limitFrom.getX() >= tr2.limitFrom.getX()) ||
                     (!tr2.isPositive() && this->limitFrom.getX() <= tr2.limitFrom.getX()))
                return true;
            return false;
        } else if (!this->isParametrizedX() && !tr2.isParametrizedX()) {
            if (this->paramY != tr2.paramY)
                return false;
            else if ((tr2.isPositive() && this->limitFrom.getY() >= tr2.limitFrom.getY()) ||
                     (!tr2.isPositive() && this->limitFrom.getY() <= tr2.limitFrom.getY()))
                return true;
            return false;
        } else if (this->isParametrizedX() != tr2.isParametrizedX()) {
            point intersection = this->intersection(tr2);
            if (!parametrizedX) {
                if (intersection.getX() >= limitFrom.getX() && intersection.getX() <= limitTo.getX() &&
                    (tr2.positive && intersection.getY() >= limitFrom.getY() ||
                     !tr2.positive && intersection.getY() <= limitFrom.getY()))
                    return true;
                return false;
            } else {
                if (intersection.getY() >= limitFrom.getY() && intersection.getY() <= limitTo.getY() &&
                    (tr2.positive && intersection.getX() >= tr2.limitFrom.getX() ||
                     !tr2.positive && intersection.getX() <= tr2.limitFrom.getX()))
                    return true;
                return false;
            }
        }
    } else if (!this->isParametrized() && !tr2.isParametrized()) {
        point intersection = this->intersection(tr2);
        if ((this->positive && this->limitFrom.getY() > intersection.getY()) ||
            (!this->positive && this->limitFrom.getY() < intersection.getY()) ||
            (tr2.positive && tr2.limitFrom.getY() > intersection.getY()) ||
            (!tr2.positive && tr2.limitFrom.getY() < intersection.getY()))
            return false;
        if (this->getK() == tr2.getK())
            return false;
        return true;
    } else if (this->isParametrized() != tr2.isParametrized()) {
        point intersection = this->intersection(tr2);
        if (length) {
            if (intersection.getX() < limitFrom.getX() ||
                intersection.getX() > limitTo.getX() ||
                intersection.getY() < limitFrom.getY() ||
                intersection.getY() > limitTo.getY() ||
                tr2.positive && intersection.getX() < tr2.limitFrom.getX()
                && intersection.getY() < tr2.limitFrom.getY() ||
                !tr2.positive && intersection.getX() > tr2.limitFrom.getX()
                && intersection.getY() > tr2.limitFrom.getY())
                return false;
            return true;
        } else {
            if (intersection.getX() < tr2.limitFrom.getX() ||
                intersection.getX() > tr2.limitTo.getX() ||
                intersection.getY() < tr2.limitFrom.getY() ||
                intersection.getY() > tr2.limitTo.getY() ||
                positive && intersection.getX() < limitFrom.getX()
                && intersection.getY() < limitFrom.getY() ||
                !positive && intersection.getX() > limitFrom.getX()
                && intersection.getY() > limitFrom.getY())
                return false;
            return true;
        }
    }
    return true;
}

bool trajectory::isLength() const {
    return length;
}


