#include "unos.h"


void newVectorWithSize(vector<int> &vector, const int size) {
    cout << "Enter " << size << " numbers in a vector:" << endl;
    for (int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        vector.push_back(temp);
    }
}

void newVectorWithLimits(vector<int> &vector, int bottom, int top) {
    cout << "Enter values in a vector while input value is in range from " << bottom << " to " << top << ":" << endl;
    int temp = bottom;
    while (temp > bottom && temp < top) {
        cin >> temp;
        vector.push_back(temp);
    }
    vector.pop_back();
}