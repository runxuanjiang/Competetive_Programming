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

        vector<ll> psum(a.begin(), a.end());
        for (int i = 1; i < n; ++i) {
            psum[i] = psum[i] + psum[i-1];
        }

        ll res = 1;
        for (int i = 1; i < n; ++i) {
            res = max(res, gcd(psum[i-1], psum.back() - psum[i-1]));
        }

        cout << res << endl;
    }
}