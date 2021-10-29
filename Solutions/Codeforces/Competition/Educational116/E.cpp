//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 998244353;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    ll n, x;
    cin >> n >> x;

    vector<vector<ll>> dp(n+1, vector<ll>(x+1, 0));

    vector<vector<ll>> comb(501, vector<ll>(501));
    for (int i = 1; i <= 500; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                comb[i][j] = 1;
            }
            else {
                comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % MOD;
            }
        }
    }

    for (ll i = 0; i <= n; ++i) {
        for (ll j = 0; j <= x; ++j) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else if (i == 1) {
                dp[i][j] = 0;
            }
            else if (i == 2) {
                dp[i][j] = j;
            }
            else if (j == 1) {
                dp[i][j] = 1;
            }
            else if (j <= (i-1)) {
                ll tempres = 1;
                for (int c = 0; c < i; ++c) {
                    tempres = (tempres * j) % MOD;
                }
                dp[i][j] = tempres;
            }

            else {
                ll tempres = 0;
                ll perm = 1;
                for (int a = n; a >= 0; --a) {
                    tempres = (tempres + comb[i][a] * perm * dp[a][j - (i-1)]) % MOD;
                    perm = (perm * (i-1)) % MOD;
                }

                dp[i][j] = tempres;
            }
        }
    }
    for (auto i : dp) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << dp[n][x] << endl;
}