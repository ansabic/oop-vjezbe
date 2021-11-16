#include <iostream>

using namespace std;

void minMax(int *&niz, int n, int &min, int &max) {
    int _min = niz[0];
    int _max = niz[0];
    for (int i = 1; i < n; i++) {
        if (niz[i] > _max)
            _max = niz[i];
        if (niz[i] < _min)
            _min = niz[i];
    }
    min = _min;
    max = _max;
}

int main() {
    int n;
    cout << "Unesi broj clanova niza:" << endl;
    cin >> n;
    int *niz = new int[n];
    for (int i = 0; i < n; i++)
        cin >> niz[i];
    int min = 9999;
    int max = -9999;
    minMax(niz, n, min, max);
    cout << min << endl;
    cout << max << endl;
}

