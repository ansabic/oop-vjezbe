//
// Created by antonio on 13. 11. 2021..
//

#ifndef OPVJEZBE_GAME_H
#define OPVJEZBE_GAME_H


#include "gun.h"
#include "target.h"
#include "trajectory.h"
#include <string>

using namespace std;


class game {
    gun myGun;
    target *myTargets;
    int noTargets;
    trajectory myTrajectory;
    bool state;

public:
    game(gun g, target *t, int n, trajectory tr);

    void execute(const string &command, double angle = -999);

    bool allCleared();

    void startGame();

    void endGame();

    bool getState() const;

    static void showError();
};


#endif //OPVJEZBE_GAME_H
