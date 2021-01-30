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
    int n;
    cin >> n;
    ll x = 1;
    ll m = 1;
    for (int i = 0; i < n; ++i) {
        x = (x * (i+1)) % MOD;
        if (i > 0) m = (m*2) % MOD;
    }
    cout << (x + MOD - m) % MOD;
}