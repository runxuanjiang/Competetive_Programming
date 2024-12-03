//Competition #:
//Problem #: F
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)


/**
 * returns gcd(a, m), while finding x and y such that
 * a*x + m*y = gcd(a, m)
 */
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
        ll n, m;
        cin >> n >> m;
        map<ll, ll> a;
        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            if (a.find(x) == a.end()) {
                a[x] = 0;
            }
            ++a[x];
        }


        ll cons = 1;
        ll res = 0;
        auto start = a.begin();
        ll mult = start->second;
        ll prev = start->first;
        auto end = a.begin();
        for (int i = 0; i+1 < m; ++i) {
            ++end;
            if (end == a.end()) {
                break;
            }

            if (end->first == prev+1) {
                ++cons;
            }
            prev = end->first;
            mult = (mult * end->second) % MOD;
        }


        while (end != a.end()) {
            // cout << "mult: " <<  mult << endl;
            // cout << "cons: " << cons << endl;
            if (cons == m) {
                res = (res + mult) % MOD;
            }

            ++end;
            if (end == a.end()) {
                break;
            }
            if (end->first == prev+1) {
                ++cons;
            }
            prev = end->first;
            mult = (mult * end->second) % MOD;

            mult = (mult * (modularInverse(start->second, MOD))) % MOD;

            ll startPrev = start->first;
            ++start;
            if (start->first == startPrev + 1) {
                --cons;
            }
        }

        cout << res << endl;


    }
}