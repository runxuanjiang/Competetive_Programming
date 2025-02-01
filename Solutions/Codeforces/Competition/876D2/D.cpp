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
    tests {
        ll n;
        cin >> n;
        vector<ll> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        vector<vector<ll>> dp(n, vector<ll>(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[i][n-1] = 1;
            if (i == 0) {
                for (int j = n-2; j >= 0; --j) {
                    if (c[j] < c[j+1] && dp[0][j+1] != 0) {
                        dp[0][j] = 1 + dp[0][j+1];
                    }
                }
            }
            else {
                for (int j = n-2; j >= 0; --j) {
                    dp[i][j] = 1;
                    if (c[j] < c[j+1]) {
                        dp[i][j] = 1 + dp[i][j+1];
                    }

                    for (int k = j+1; k < n; ++k) {
                        if (c[j] < c[k]) {
                            dp[i][j] = max(dp[i][j], 1 + dp[i-1][k]);
                        }
                    }
                }
            }
        }

        for (int i = 0; i+1 < n; ++i) {
            if (c[0] < c[1]) {
                dp[i][0] = max(dp[i][0], 1 + dp[i+1][1]);
            }
            for (int j = 2; j < n; ++j) {
                if (c[0] < c[j]) {
                    dp[i][0] = max(dp[i][0], 1 + dp[i][j]);
                }
            }
        }


        for (auto i : dp) {
            for (auto j : i) {
                cerr << j << " ";
            }
            cerr << endl;
        }
        cerr << endl;


        for (int i = 0; i < n; ++i) {
            cout << n - *(max_element(dp[i].begin(), dp[i].end())) << " ";
        }
        cout << endl;



    }
}
