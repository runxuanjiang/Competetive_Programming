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
 
 
    vector<ll> curr(180001, 0), next(180001, 0);
    curr[90000] = 1;
    vector<ll> dp(n, 0);
    dp[0] = 1;
 
    for (ll i = 1; i < n; ++i) {
        next = vector<ll>(180001, 0);
        for (ll j = -90000; j <= 90000; ++j) {
            if (curr[j + 90000] && a[i] + j >= -90000 && a[i] + j <= 90000) {
                next[a[i] + j + 90000]++;
            }
            if (curr[j + 90000] && a[i] - j >= -90000 && a[i] - j <= 90000) {
                next[a[i] - j + 90000]++;
            }
 
        }
 
        if (i == 1) {
            dp[i] = 1;
        }
        else {
            dp[i] = (dp[i-1]*2 - curr[90000] + MOD) % MOD;
 
        }
 
        swap(curr, next);
 
 
    }
 
    cout << dp.back() << endl;
 
}