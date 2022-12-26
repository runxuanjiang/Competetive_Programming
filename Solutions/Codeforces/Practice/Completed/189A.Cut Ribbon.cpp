//Competition #:
//Problem #:
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

    ll n;
    vector<ll> a(3);
    cin >> n;
    cin >> a[0] >> a[1] >> a[2];

    sort(a.begin(), a.end());

    vector<ll> dp(n+1, 0);
    for (ll i = 0; i * a[0] <= n; ++i) {
        for (ll j = 0; j * a[1] <= n; ++j) {
            ll prod = i * a[0] + j * a[1];
            if (prod <= n) {
                dp[prod] = max(dp[prod], i + j);
            }
        }
    }

    ll res = 0;
    for (ll i = 0; i * a[2] <= n; ++i) {
        res = max(res, dp[n - i * a[2]] + i);
    }

    cout << res << endl;
}