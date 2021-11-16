#include <iostream>

using namespace std;

int &indexNiz(int *niz, int i) {
    return niz[i];
}

int main() {
    int n;
    cout << "Unesi broj clanova niza:" << endl;
    cin >> n;
    int *niz = new int[n];
    for (int i = 0; i < n; i++)
        cin >> niz[i];
    cout << "Unesi indeks u nizu: " << endl;
    int index;
    cin >> index;
    int &item = indexNiz(niz, index);
    item++;
    for (int i = 0; i < n; i++)
        cout << niz[i] << " ";
    cout << endl;
}
