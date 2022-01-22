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

ll recurse(ll n, vector<ll> &dp) {
    if (n < 2) {
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    ll res = 0;
    res = (res + recurse(n-1, dp)) % MOD;
    res = (res + recurse(n-2, dp)) % MOD;

    dp[n] = res;
    return res;
}

int main() {
    fast;
    string s;
    cin >> s;
    vector<ll> runs;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'w' || s[i] == 'm') {
            cout << 0 << endl;
            return 0;
        }
        if (s[i] == 'u' || s[i] == 'n') {
            ll run = 1;
            while (i+1 < s.size() && s[i+1] == s[i]) {
                ++i;
                ++run;
            }
            if (run > 1) {
                runs.push_back(run);
            }
        }
    }

    ll res = 1;
    vector<ll> dp(s.size() + 1, -1);

    for (auto i : runs) {
        res = (res * recurse(i, dp)) % MOD;
    }
    cout << res << endl;



}