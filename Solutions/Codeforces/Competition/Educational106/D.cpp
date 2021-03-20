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
        ll c, d, x;
        cin >> c >> d >> x;
        ll res = 0;
        for (ll i = 1; i*i <= x; ++i) {
            if (x % i == 0) {
                if (i * (x + d*i) % c == 0) {
                    ll targ = i * (x + d*i) / c;
                    for (int j = 1; j*j <= targ; ++j) {
                        if (targ % j == 0 && gcd(j, targ/j) == i) {
                            res += (j == targ/j) ? 1 : 2;
                        }
                    }
                }

                if (x/i != i) {
                    i = x/i;
                        if (i * (x + d*i) % c == 0) {
                            ll targ = i * (x + d*i) / c;
                            for (int j = 1; j*j <= targ; ++j) {
                                if (targ % j == 0 && gcd(j, targ/j) == i) {
                                    res += (j == targ/j) ? 1 : 2;
                                }
                            }
                        }
                    i = x/i;
                }
            }
        }
        cout << res << endl;
    }
}