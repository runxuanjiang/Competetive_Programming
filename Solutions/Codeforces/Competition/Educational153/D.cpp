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
    string s;
    cin >> s;

    ll n = s.size();


    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n+1, vector<ll>(1 + n*n/4, LONG_LONG_MAX)));

    if (s.front() == '0') {
        dp[0][1][0] = 0;
        dp[0][0][0] = 1;
    }
    else {
        dp[0][1][0] = 1;
        dp[0][0][0] = 0;
    }

    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n*n/4; ++k) {
                if (dp[i][j][k] < LONG_LONG_MAX) {
                    if (s[i+1] == '0') {
                        dp[i+1][j+1][k] = min(dp[i+1][j+1][k], dp[i][j][k]);
                        dp[i+1][j][k + j] = min(dp[i+1][j][k + j], dp[i][j][k] + 1);
                    }
                    else {
                        dp[i+1][j+1][k] = min(dp[i+1][j+1][k], dp[i][j][k] + 1);
                        dp[i+1][j][k + j] = min(dp[i+1][j][k + j], dp[i][j][k]);
                    }
                }
            }
        }
    }

    ll count_0 = 0;
    ll count_1 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            count_0++;
        }
        else {
            count_1++;
        }
    }

    cout << dp.back()[count_0][(count_0*count_1)/2]/2 << endl;















}