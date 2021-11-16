//
// Created by antonio on 12. 11. 2021..
//
#include "unos.h"
#include "print.h"

using namespace std;

bool notInVector(int x, vector<int> &vector) {
    while (!vector.empty()) {
        if (vector.back() == x)
            return false;
        vector.pop_back();
    }
    return true;
}

int main() {
    int n, m;
    cout << "Enter vector size for vector 1: " << endl;
    cin >> n;
    cout << "Enter vector size for vector 2: " << endl;
    cin >> m;
    vector<int> a = vector<int>();
    vector<int> b = vector<int>();
    newVectorWithSize(a, n);
    newVectorWithSize(b, m);
    vector<int> c = vector<int>();
    for (int i = 0; i < n; i++) {
        if (notInVector(a[i], b))
            c.push_back(a[i]);
    }
    printVector(c);
}

