//Competition #:
//Problem #: D
//Accepted: 
 
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MOD = 998244353;
 
#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)
 
int main() {
    fast;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(2, vector<ll>(200001, 0));
    dp[0][a[1] + 100000]++;

    for (ll i = 0; i < n-2; ++i) {
        ll next = a[i+2];
        for (ll j = -90000; j <= 90000; ++j) {
            if (j == 0) {
                dp[1][next + 100000] = (dp[1][next + 100000] + dp[0][j + 100000]) % MOD;
            }
            else {
                dp[1][next + j + 100000] = (dp[1][next + j + 100000] + dp[0][j + 100000]) % MOD;
                dp[1][next - j + 100000] = (dp[1][next - j + 100000] + dp[0][j + 100000]) % MOD;
            }
        }

        swap(dp[0], dp[1]);
        dp[1] = vector<ll>(200001, 0);
    }

    ll res = 0;
    for (auto i : dp.front()) {
        res = (res + i) % MOD;
    }
    cout << res << endl;


 
}