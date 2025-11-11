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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        for (ll& x : a) cin >> x;
        for (ll& x : b) cin >> x;

        ll res = 0;
        for (auto i : a) {
            res ^= i;
        }

        bitset<32> res2(res);
        for (auto i : b) {
            for (int j = 0; j < 32; ++j) {
                if (i & (1 << j)) {
                    res2[j] = (n%2 != 0);
                }
            }
        }

        if (n % 2 == 0) {
            cout << res2.to_ulong() << " " << res << endl;
        }
        else {
            cout << res << " " << res2.to_ulong() << endl;
        }




    }
}