//Competition #:
//Problem #: C
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
        ll n, k;
        cin >> n >> k;

        ll res = 1;

        vector<ll> dp(n, 1);
        vector<ll> curr(n);
        ll sum = n;
        if (k > 1) {
            res += n;
        }

        // for (auto i : dp) {
        //     cout << i << " ";
        // }
        // cout << endl;

        for (int i = 0; i < k-2; ++i) {
            for (int j = 0; j < n-1; ++j) {
                if (j == 0) {
                    curr[j] = (sum - dp[n-1] + MOD) % MOD;
                    sum = curr[j];
                }
                else {
                    curr[j] = (curr[j-1] - dp[n-j-1] + MOD) % MOD;
                    sum = (sum + curr[j]) % MOD;
                }

                res = (res + curr[j]) %  MOD;

            }
            dp = curr;
            // for (auto j : dp) {
            //     cout << j << " ";
            // }
            // cout << endl;
        }

        cout << res % MOD << endl;
    }
}