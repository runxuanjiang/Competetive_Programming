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
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> base;
        for (int i = 0; i + i < n; ++i) {
            ll small = min(a[i], a[n-1-i]);
            ll large = max(a[i], a[n-i-1]);
            if (small != large) {
                base.push_back(large-small);
            }
        }

        if (base.empty()) {
            cout << 0 << endl;
        }
        else {
            ll res = base[0];
            for (auto i : base) {
                res = gcd(res, i);
            }
            cout << res << endl;
        }
    }
}