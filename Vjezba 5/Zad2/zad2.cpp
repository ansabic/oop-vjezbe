//
// Created by antonio on 12. 11. 2021..
//
#include <iostream>
#include "target.h"
#include "game.h"

using namespace std;

int main() {
    auto *targets = new target[20];
    int targetNo;
    cout << "Enter no of targets:" << endl;
    cin >> targetNo;
    for (int i = 0; i < targetNo; i++) {
        cout << "Enter bottom left and upper right point of a target:" << endl;
        point bl, ur;
        double x, y;
        cin >> x >> y;
        bl = point(x, y, 0);
        cin >> x >> y;
        ur = point(x, y, 0);
        targets[i] = target(bl, ur);
    }
    cout << "Enter starting point for a gun:" << endl;
    point start;
    double x, y;
    int n;
    cin >> x >> y;
    start = point(x, y, 0);
    cout << "Enter ammo size of a gun:" << endl;
    cin >> n;
    gun newGun = gun(start, n);
    trajectory newTrajectory = trajectory(start, 0);
    game newGame = game(newGun, targets, targetNo, newTrajectory);
    newGame.startGame();
    cout << "COMMANDS:" << endl << "shoot" << endl << "rotate $angleInDeg" << endl << "reload" << endl << "exit" << endl;
    while (newGame.getState() && !newGame.allCleared()) {
        cout << "Enter command:" << endl;
        string command;
        double angle;
        cin >> command;
        if (cin.peek() == '\n')
            newGame.execute(command);
        else {
            cin >> angle;
            newGame.execute(command, (int) angle % 360);
        }
    }
    cout << "Congratulations! Game is complete! All " << targetNo << " targets are hit!" << endl;
}
