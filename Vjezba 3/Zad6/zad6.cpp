//
// Created by antonio on 12. 11. 2021..
//
#include "unos.h"
#include "print.h"
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> v = vector<string>();
    int n;
    cout << "Enter number of strings: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string myStr;
        cout << "Enter a string:" << endl;
        cin >> myStr;
        reverse(myStr.begin(), myStr.end());
        v.push_back(myStr);
    }
    sort(v.begin(), v.end());
    for (const string &s: v)
        cout << s << " ";


}
