//Competition #: 666 D2
//Problem #: C
//Acepted: No

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (n == 1) {
        cout << 1 << " " << 1 << endl;
        cout << -1*v[0] << endl;
        cout << 1 << " " << 1 << '\n' << 0 << '\n' << 1 << " " << 1 << '\n' << 0;
        return 0;
    }

    cout << 1 << " " << 1 << endl;
    cout << -1*(v[0]) << endl;
    v[0] = 0;
    cout << 2 << " " << n << endl;
    for (int i = 1; i < v.size(); ++i) {
        int added = 0;
        while (v[i] % n != 0) {
            v[i] += (n-1);
            ++added;
        }
        cout << added * (n-1) << " ";
    }
    cout << endl;

    cout << 1 << " " << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << -1*v[i] << " ";
    }
}