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

string c = "michigan";
string s;

ll recurse(int sidx, int cidx, vector<vector<ll>> &dp) {
    if (cidx < 0) {
        return 1;
    }
    else if (sidx < 0) {
        return 0;
    }

    if (dp[sidx][cidx] != -1) {
        return dp[sidx][cidx];
    }

    else {
        if (s[sidx] == c[cidx]) {
            dp[sidx][cidx] = (recurse(sidx-1, cidx, dp) + recurse(sidx, cidx-1, dp)) % MOD;
        }
        else {
            dp[sidx][cidx] = recurse(sidx-1, cidx, dp);
        }
    }
    return dp[sidx][cidx];
}

int main() {
    fast;
    cin >> s;

    vector<vector<ll>> dp(s.length(), vector<ll>(c.length(), -1));
    cout << recurse(s.length()-1, c.length()-1, dp) << endl;
}