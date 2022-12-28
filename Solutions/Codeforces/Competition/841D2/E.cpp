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

int main() {
    fast;
    tests {
        ll n, m;
        cin >> n >> m;

        vector<ll> sieve(n/2 + 1);

        for (ll i = n/2; i >= 2; --i) {
            ll divisors = n/i;
            sieve[i] = divisors * (divisors - 1) / 2;
            for (int j = 1; i * (j+1) <= n/2; ++j) {
                sieve[i] -= sieve[i * (j+1)];
            }
        }

        ll res = 0;
        for (int i = n/2; i >= 2; --i) {
            ll avail = sieve[i] / (i-1) * (i-1);
            ll taken = m / (i-1) * (i-1);
            ll sub = min(avail, taken);

            m -= sub;
            res += (sub / (i-1)) * i;
        }

        if (m) {
            cout << -1 << endl;
        }
        else {
            cout << res << endl;
        }

    }
}