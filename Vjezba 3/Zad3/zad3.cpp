//
// Created by antonio on 12. 11. 2021..
//
#include "unos.h"
#include "print.h"
#include <bits/stdc++.h>

using namespace std;
int main() {
    int n;
    cout << "Enter vector size for vector 1: " << endl;
    cin >> n;
    vector<int> a = vector<int>();
    newVectorWithSize(a, n);
    sort(a.begin(), a.end());
    a.insert(a.begin(), 0);
    int result = accumulate(a.begin(), a.end(), 0);
    a.push_back(result);
    printVector(a);
}

