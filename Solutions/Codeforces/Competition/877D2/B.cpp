//Competition #:
//Problem #: B
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        ll id_1;
        ll id_2;
        ll id_n;
        for (int i = 0; i < n; ++i) {
            if (p[i] == 1) {
                id_1 = i;
            }
            else if (p[i] == 2) {
                id_2 = i;
            }
            else if (p[i] ==n) {
                id_n = i;
            }
        }

        if (id_2 > id_1 && id_n > id_1) {
            if (id_2 > id_n) {
                cout << 1 << " " << 1 << endl;
            }
            else {
                cout << id_2 + 1 << " " << id_n + 1 << endl;
            }
        }
        else if (id_2 < id_1 && id_n < id_1) {
            if (id_2 < id_n) {
                cout << 1 << " " << 1 << endl;
            }
            else {
                cout << id_2 + 1 << " " << id_n + 1 << endl;
            }
        }
        else {
            cout << id_1 + 1 << " " << id_n + 1 << endl;
        }
    }
}