//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 998244353;

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
        ll n;
        cin >> n;
        vector<ull> s(n);
        for (ull &i : s) cin >> i;

        ll numerator = 0;
        ll denominator = n*n;
        ll same = 0;

        sort(s.begin(), s.end());

        vector<ll> firstDiffDigit(32);

        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] != s[i-1]) {

                ll diff_idx = 0;
                for (int j = 30; j >= 0; --j) {
                    if (s[i] & (1ULL << j)) {
                        diff_idx++;
                        if (!(s[i-1] & (1ULL << j))) {
                            break;
                        }
                    }
                }

                for (int j = diff_idx+1; j <= 31; ++j) {
                    firstDiffDigit[diff_idx] += firstDiffDigit[j];
                    firstDiffDigit[j] = 0;
                }
                firstDiffDigit[diff_idx] += same + 1;
                same = 0;

            }
            else if (s[i] == s[i-1]) {
                ++same;
            }
            numerator += (popcount(s[i]) + 1) * (same*2 + 1);

            for (int j = 1; j <= 31; ++j) {
                numerator += firstDiffDigit[j] * (j + j + 1);
            }

            // cerr << "numerator is " << numerator << " after processing " << s[i] << endl;
            // cerr << "firstDiffDigit: ";
            // for (int j = 1; j <= 31; ++j) {
            //     cerr << firstDiffDigit[j] << ' ';
            // }
            // cerr << '\n';

        }

        // cerr << "numerator: " << numerator << " denominator: " << denominator << '\n';
        ll res = modularInverse(denominator, MOD) * (numerator % MOD) % MOD;
        cout << res << '\n';

    }
}