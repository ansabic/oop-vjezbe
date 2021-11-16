#include<iostream>
#include <ostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void minMaxUsingRecursion(int *niz, int position, int n, int *min, int *max) {
    if (position != n) {
        if (niz[position] > *max)
            *max = niz[position];
        if (niz[position] < *min)
            *min = niz[position];
        minMaxUsingRecursion(niz, position + 1, n, min, max);
    }
}

int main() {
    int n;
    cout << "Unesi broj clanova niza: \n";
    cin >> n;
    int niz[n];
    cout << "Unesi niz od " << n << " clanova: \n";
    for (int i = 0; i < n; i++) {
        cin >> niz[i];
    }
    int *min = new int;
    int *max = new int;
    *min = niz[0];
    *max = niz[0];
    minMaxUsingRecursion(niz, 0, n, min, max);
    cout << "Min je " << *min << endl;
    cout << "Max je " << *max << endl;
}
