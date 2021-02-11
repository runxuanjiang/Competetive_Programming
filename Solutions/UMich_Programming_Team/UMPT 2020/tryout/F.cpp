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

ll recurse(int i, ll currgcd, vector<ll> &a, vector<unordered_map<ll, ll>> &dp) {
    if (i == a.size()) {
        return (currgcd == 1) ? 1 : 0;
    }

    if (dp[i].find(currgcd) != dp[i].end()) {
        return dp[i][currgcd];
    }

    dp[i][currgcd] = ((recurse(i+1, currgcd, a, dp) % MOD) + (recurse(i+1, gcd(currgcd, a[i]), a, dp)% MOD) ) % MOD;

    return dp[i][currgcd];
}

int main() {
    fast;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<unordered_map<ll, ll>> dp(n);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += (recurse(i+1, a[i], a, dp) % MOD);
        res = res % MOD;
    }

    cout << res << endl;

    
}