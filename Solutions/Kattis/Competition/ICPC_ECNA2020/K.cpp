//Competition #:
//Problem #: I
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int n, m;

int recurse(int b, int p, vector<vector<int>> &dp) {

    if (b == 1) {
        dp[b][p] = 0;
        return 0;
    }
    if (b == 2) {
        dp[b][p] = 1;
        return 1;
    }
    if (p == 1) {
        dp[b][p] = b-1;
        return b-1;
    }

    if (dp[b][p] != -1) {
        return dp[b][p];
    }

    int m = INT_MAX;
    for (int i = 2; i <= b; ++i) {
        m = min(m, max(recurse(i-1, p-1, dp), recurse(b - i + 1, p, dp)));
    }
    dp[b][p] = m+1;
    return m+1;
}

int main() {
    fast;

    cin >> n >> m;

    vector<vector<int>> dp(n+2, vector<int>(m+1, -1));
    for (int i = 0; i < n+2; ++i) {
        dp[i][1] = i-1;
    }
    int res = recurse(n+1, m, dp);
    // for (auto i : dp) {
    //     for (auto j : i) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    int mi = n+1, ma = -1;
    for (int i = 1; i <= n; ++i) {
        if (max(dp[i][m-1], dp[n-i+1][m]) == res-1) {
            mi = min(mi, i);
            ma = max(mi, i);
        }
    }
    if (mi == ma) {
        cout << res << " " << mi << endl;
    }
    else {
        cout << res << " " << mi << '-' << ma << endl;
    }


}