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
    ll n, m, q;
    cin >> n >> m >> q;

    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }
    for (int i = 0; i < q; ++i) {
        ll bit;
        cin >> bit;
        
    }
}