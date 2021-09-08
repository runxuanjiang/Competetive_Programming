//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 998244353;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ull modpow(ull x, ull y) {
    ull res = 1;
    x = x % MOD;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }

        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

int main() {
    fast;
    ull n;
    cin >> n;

    for (ull i = 1; i <= n; ++i) {
        if (i == n) {
            cout << 10 << "\n";
        }
        else {
            ull sides = (2 * 10 * 9 * modpow(10, n - i - 1)) % MOD;
            ull inner = ((((n - i -1) * 10 * 9 * 9) % MOD) * modpow(10, n - i - 2)) % MOD;
            cout << (sides + inner) % MOD << " ";
        }
    }
}