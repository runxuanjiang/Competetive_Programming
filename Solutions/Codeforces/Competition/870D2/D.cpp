//Competition #:
//Problem #: D
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

        vector<ll> l(n, 0);
        vector<ll> r(n, 0);
        ll m = INT_MIN;
        for (int i = 0; i < n; ++i) {
            m = max(m, a[i] + i);
            l[i] = m;
        }
        m = INT_MIN;
        for (int i = n-1; i >= 0; --i) {
            m = max(m, a[i] - i);
            r[i] = m;
        }

        ll res = 0;
        for (int i = 1; i+1 < n; ++i) {
            res = max(res, l[i-1] + a[i] + r[i+1]);
        }

        cout << res << endl;
    }

}