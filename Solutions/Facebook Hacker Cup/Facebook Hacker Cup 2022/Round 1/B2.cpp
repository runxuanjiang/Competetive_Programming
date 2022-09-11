//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

long long quadratic(const vector<ll> &l, const vector<ll> &r) {
    ll a = 0, b = 0, c = 0;
    ll res = 0;

    for (auto i : l) {
        a = (a + 1) % MOD;
        b = (b + 2 * i) % MOD;
        c = (c + i * i ) % MOD;
    }

    for (auto i : r) {
        res = (res + ((a * ((i * i) % MOD)) % MOD)) % MOD;
        res = (res - b * i) % MOD;
        res = (res + c) % MOD;
        res = (res + MOD) % MOD;
    }

    return res;


}

int main() {
    fast;

    int test = 0;
    tests {
        ++test;
        cout << "Case #" << test << ": ";

        ll n;
        cin >> n;
        vector<ll> nx(n);
        vector<ll> ny(n);
        for (int i = 0; i < n; ++i) {
            cin >> nx[i];
            cin >> ny[i];
        }

        ll q;
        cin >> q;
        vector<ll> qx(q);
        vector<ll> qy(q);
        for (int i = 0; i < q; ++i) {
            cin >> qx[i];
            cin >> qy[i];
        }

        ll res = 0;
        res = (res + quadratic(nx, qx)) % MOD;
        res = (res + quadratic(ny, qy)) % MOD;
        res = (res + MOD) % MOD;

        cout << res << endl;

    }
}