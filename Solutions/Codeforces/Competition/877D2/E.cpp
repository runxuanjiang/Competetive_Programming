//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ll fastExp(ll base, ll exp) {
    if (exp == 1) {
        return base;
    }
    if (exp % 2 == 1) {
        return (base * fastExp((base*base) % MOD, exp/2) ) % MOD;
    }
    else {
        return fastExp((base*base) % MOD, exp/2) % MOD;
    }
}

long long extendedEuclidean(long long a, long long m, long long &x, long long &y) {
    if (m > a) {
        return extendedEuclidean(m, a, y, x);
    }

    if (!m) {
        x = 1;
        y = 0;
        return a;
    }


    long long mult = a/m;
    long long prevx, prevy;
    long long res = extendedEuclidean(m, a-(m*mult), prevx, prevy);
    x = prevy;
    y = prevx - prevy * mult;
    return res;
}

long long modularInverse(long long num, long long mod) {
    long long x, _;
    long long g = extendedEuclidean(num, mod, x, _);
    return ((x % mod) + mod ) % mod;

}

int main() {
    fast;
    tests {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll res = fastExp(k, m) % MOD;
        // cerr << "starting res: " << res << endl;
        ll num = fastExp(k-1, m);
        ll denom = 1;
        for (ll i = 0; i < n; ++i) {
            // cerr << "starting iteration " << i << endl;
            // cerr << "num, denom: " << num << " " << denom << endl;
            ll comb = (num * modularInverse(denom, MOD)) % MOD;
            res = (((res - comb) % MOD) + MOD) % MOD; // make it positive
            // cerr << "res: " << res << endl;
            num = (num * (m-i)) % MOD;
            denom = (denom * (i+1)) % MOD;
            denom = (denom * (k-1)) % MOD;
        }

        cout << res << endl;        
    }
}