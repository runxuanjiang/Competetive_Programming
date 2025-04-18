//Competition #:
//Problem #: A
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
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll res = MOD;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i-1]) {
                res = 0;
            }
            else {
                res = min(res, (a[i] - a[i-1] + 2) / 2);
            }
        }
        cout << res << endl;
    }
}