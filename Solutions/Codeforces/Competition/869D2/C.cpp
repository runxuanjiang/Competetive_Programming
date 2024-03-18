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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<bool> inc(n, false);
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i-1]) {
            inc[i] = 1;
            inc[i-1] = 1;
        }
    }

    vector<ll> psum(n+1, 0);
    for (int i = 0; i < n; ++i) {
        psum[i+1] = psum[i] + inc[i];
    }

    for (int i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        if (l == r) {
            cout << 1 << endl;
        }
        else {
            ll res = 0;
            if (!inc[l-1]) ++res;
            if (!inc[r-1]) ++res;
            res += (psum[r] - psum[l-1]);
            cout << res << endl;
        }

    }
}