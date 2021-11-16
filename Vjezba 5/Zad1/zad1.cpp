//
// Created by antonio on 12. 11. 2021..
//
#include <iostream>
#include "point.h"

using namespace std;

int main() {
    point p1, p2;
    double x, y, z;
    cout << "Insert a dot: (x,y,z) " << endl;
    cin >> x >> y >> z;
    p1 = point(x, y, z);
    cout << "Insert a dot: (x,y,z) " << endl;
    cin >> x >> y >> z;
    p2 = point(x, y, z);
    cout << "Distance in a 2D space is " << p1.distance2D(p2) << endl;
    cout << "Distance in a 3D space is " << p1.distance3D(p2) << endl;

}
