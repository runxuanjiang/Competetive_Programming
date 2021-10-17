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
        vector<ll> b(3);
        for (int i = 0; i < 3; ++i) {
            cin >> b[i];
        }

        sort(b.begin(), b.end());

        ll res = INT_MAX;

        if (b[0] == b[1]) {
            res = min(res, b[0]);
        }
        
        if (b[1] == b[2]) {
            res = min(res, b[1]);
        }

        if ((b[1] - b[0]) % 3 == 0) {
            res = min(res, b[1]);
        }

        if ((b[2] - b[0]) % 3 == 0) {
            res = min(res, b[2]);
        }
        if ((b[2] - b[1]) % 3 == 0) {
            res = min(res, b[2]);
        }

        if (res == INT_MAX) {
            cout << -1 << endl;
        }
        else {
            cout << res << endl;
        }

    }
}