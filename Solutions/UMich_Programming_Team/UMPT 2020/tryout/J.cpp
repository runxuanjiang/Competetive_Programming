//Competition #:
//Problem #: J
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


    string c = "michigan";

    vector<vector<ll>> dp(s.length() + 1, vector<ll>(9, 0));

    for (int i = 0; i <= s.length(); ++i) {
        dp[i][0] = 1;
    }

    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; j < 8; ++j) {
            if (s[i] == c[j]) {
                dp[i+1][j+1] = ((dp[i][j]%MOD) + (dp[i][j+1]%MOD)) % MOD;
            }
            else {
                dp[i+1][j+1] = dp[i][j+1];
            }
        }
    }

    cout << dp.back().back() << endl;
}