//Competition #:
//Problem #: C
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
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll highest = 0;
        for (auto i : a) {
            highest = max(highest, i);
        }

        if (n > 3) {
            cout << highest * n << endl;
        }

        else if (n == 3) {
            ll res = max(a[0] * 3, a[2] * 3);
            res = max(res, 3 * abs(a[0] - a[1]));
            res = max(res, 3*abs(a[2] - a[1]));
            res = max(res, a[0] + a[1] + a[2]);
            res = max(res, 2 * abs(a[0] - a[1]) + a[2]);
            res = max(res, 2 * abs(a[2] - a[1]) + a[0]);
            res = max(res, abs(a[0] - a[1]) + 2 * abs(a[2] - abs(a[0] - a[1])));
            res = max(res, abs(a[2] - a[1]) + 2 * abs(a[0] - abs(a[2] - a[1])));
            res = max(res, 3 * abs(a[0] - a[2]));
            cout << res << endl;

        }

        else {
            cout << max(a[0] + a[1], 2 * abs(a[0] - a[1])) << endl;
        }

    }
}