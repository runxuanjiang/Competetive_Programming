//Competition #:
//Problem #: F
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ll recurse(int idx, ll gcf, vector<ll> &a, vector<unordered_map<ll, ll>> &dp) {
    if (idx == a.size() - 1) {
        return (gcf == 1) ? 1 : 0;
    }
    

    if (dp[idx].find(gcf) == dp[idx].end()) {
        dp[idx][gcf] = (recurse(idx+1, gcf, a, dp) + recurse(idx+1, gcd(gcf, a[idx+1]), a, dp)) % MOD;
    }
    return dp[idx][gcf];
}

int main() {
    fast;
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<unordered_map<ll, ll>> dp(n-1);

    ll res = 0;
    for (int i = 0; i < n-1; ++i) {
        res = (res + recurse(i, a[i], a, dp)) % MOD;
    }
    if (a.back() == 1) {
        res = (res+1) % MOD;
    }

    cout << res << endl;

}