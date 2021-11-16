#include<iostream>
#include <ostream>

using namespace std;

void findMinAndMax(int *niz, int n, int *min, int *max) {
    for (int i = 1; i < n; i++) {
        if (niz[i] > *max) {
            *max = niz[i];
        }
        if (niz[i] < *min) {
            *min = niz[i];
        }
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
    findMinAndMax(niz, n, min, max);
    cout << "minimum is " << min[0] << endl;
    cout << "maximum is " << max[0] << endl;
}
