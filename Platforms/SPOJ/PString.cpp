//Competition #:
//Problem #: PSTRING - Remove The String
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;
const int INF = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(--testCount)

int solve(string &X, string &Y, int l, int i, vector<vector<int>>& kmpLetters, vector<vector<int>>& dp) {
    if (l == Y.length()) {
        return INF;
    }
    if (i == X.length()) {
        return 0;
    }
    if (dp[l][i] != -1) return dp[l][i];

    int keep = solve(X, Y, kmpLetters[l][X[i] - 'a'], i+1, kmpLetters, dp);
    int skip = 1 + solve(X, Y, l, i+1, kmpLetters, dp);
    dp[l][i] = min(skip, keep);
    return dp[l][i];
}

int main() {
    fast;
    string X, Y;
    while (cin >> X) {
        cin >> Y;
        vector<int> kmp(Y.length(), 0);
        vector<vector<int>> kmpLetters(Y.length(), vector<int>(26, 0));
        int comp = 0;
        for (int i = 1; i < Y.length(); ++i) {
            while (comp > 0 && Y[i] != Y[comp]) {
                comp = kmp[comp-1];
            }
            if (Y[i] == Y[comp]) {
                ++comp;
                kmp[i] = comp;
            }
        }

        vector<vector<int>> dp(Y.length(), vector<int>(X.length(), -1));

        for (int i = 0; i < Y.length(); ++i) {
            for (int c = 'a'; c <= 'z'; ++c) {
                int k = i;
                while (k > 0 && c != Y[k]) {
                    k = kmp[k-1];
                }
                if (Y[k] == c) {
                    ++k;
                    kmpLetters[i][c - 'a'] = k;
                }
            }
        }
        cout << solve(X, Y, 0, 0, kmpLetters, dp) << endl;
    }
}