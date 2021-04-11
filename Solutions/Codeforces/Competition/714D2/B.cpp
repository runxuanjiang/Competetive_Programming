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
        int n;
        cin >> n;
        vector<ll> a(n);
        ll anded = -1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (anded == -1) anded = a[i];
            else anded &= a[i];
        }

        ll fact = 1;
        for (ll i = 1; i <= n-2; ++i) {
            fact = (fact * i) % MOD;
        }


        unordered_map<ll, ll> m;
        for (auto i : a) {
            if (m.find(i) == m.end()) m[i] = 1;
            else m[i]++;
        }

        ll res = 0;
        if (m.find(anded) != m.end() && m[anded] > 1) {
            ll mult1 = (m[anded] * (m[anded]-1)) % MOD;
            res = (res + mult1 * fact) % MOD;
        }

        cout << res << endl;
    }
}