//
// Created by antonio on 12. 11. 2021..
//

#include "gun.h"
#include "iostream"

using namespace std;

gun::gun(point p, int maxLoad) {
    position = p;
    this->maxLoad = maxLoad;
    this->currentLoad = maxLoad;
}

void gun::shoot() {
    if (currentLoad != 0) {
        currentLoad--;
        cout << currentLoad << "/" << maxLoad << endl;
    } else
        cout << "Empty!" << endl;
}

void gun::reload() {
    currentLoad = maxLoad;
    cout << "Reloaded!" << endl;
    cout << currentLoad << "/" << maxLoad << endl;
}

point gun::getPosition() const {
    return position;
}

bool gun::isEmpty() const {
    return currentLoad == 0;
}
