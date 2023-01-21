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

        ll res = (n * (n-1)) % MOD;
        ll nfact = 1;
        for (ll i = 1; i <= n; ++i) {
            nfact = (nfact * i) % MOD;
        }

        res = (res * nfact) % MOD;
        cout << res << endl;
    }
}