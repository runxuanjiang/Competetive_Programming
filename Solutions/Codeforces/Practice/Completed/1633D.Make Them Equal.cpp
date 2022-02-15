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

struct Comp{
    bool operator() (const pair<ll, ll> &l, const pair<ll, ll> &r) {
        return (l.first * r.second > r.first * l.second);
    }
};

ll recurse(int i, ll k, const vector<ll> &c, const vector<ll> &rounds, vector<unordered_map<ll, ll>> &dp) {
    if (i >= rounds.size()) {
        return 0;
    }

    if (dp[i].find(k) != dp[i].end()) {
        return dp[i][k];
    }

    if (k < rounds[i]) {
        dp[i][k] = recurse(i+1, k, c, rounds, dp);
    }
    else dp[i][k] = max(recurse(i+1, k, c, rounds, dp), c[i] + recurse(i+1, k - rounds[i], c, rounds, dp));
    return dp[i][k];
}

int main() {
    fast;
    tests {
        int n;
        cin >> n;
        ll k;
        cin >> k;
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<ll> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        vector<ll> calc(1001, 1001);
        calc[1] = 0;
        for (int i = 1; i <= 1000; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (i + i/j <= 1000) {
                    calc[i + i/j] = min(calc[i + i/j], 1 + calc[i]);
                }

            }
        }

        vector<ll> rounds(n);
        for (int i = 0; i < n; ++i) {
            rounds[i] = calc[b[i]];
        }

        ll res = 0;

        if (k > 50000) {
            for (auto i : c) {
                res += i;
            }
        }
        else {
            vector<unordered_map<ll, ll>> dp(n);
            res = recurse(0, k, c, rounds, dp);
        }

        cout << res << endl;


    }
}