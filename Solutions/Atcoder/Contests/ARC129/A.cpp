//Competition #:
//Problem #: A
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
    ll n, l, r;
    cin >> n >> l >> r;

    ll res = 0;
    for (int i = 0; i < 64; ++i) {
        if ((1ll << i) & n) {
            ll lower =  max(1ll<<i, l);
            ll upper = min(1ll<<(i+1), r+1);
            if (upper > lower) {
                res += (upper-lower);
            }
        }
    }
    cout << res << endl;
}