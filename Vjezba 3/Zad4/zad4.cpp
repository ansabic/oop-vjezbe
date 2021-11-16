//
// Created by antonio on 12. 11. 2021..
//

#include "unos.h"
#include "print.h"

using namespace std;

void removeElementAtIndex(int index, vector<int> &v) {
    v.erase(v.begin() + index);
}

int main() {
    int n;
    cout << "Enter vector size for vector 1: " << endl;
    cin >> n;
    vector<int> a = vector<int>();
    newVectorWithSize(a, n);
    removeElementAtIndex(n - 3, a);
    printVector(a);
}
