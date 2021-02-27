//Competition #:
//Problem #: H
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int X, Y;

int recurse(vector<string> &grid, string &key, int y, int x, int idx, vector<vector<vector<int>>> &dp) {
    if (dp[y][x][idx] != -1) {
        return dp[y][x][idx];
    }

    int res = (int) (grid[y][x] - '0');
    int keyIdx = 0;
    if (idx < key.size()) {
        keyIdx = (int) (key[idx] - '0');
    }

    int plus = MOD;
    if (y-1 >= 0) {
        plus = min(plus, recurse(grid, key, y-1, x, idx, dp));
    }
    if (keyIdx && y-1-keyIdx >= 0) {
        plus = min(plus, recurse(grid, key, y-1-keyIdx, x, idx+1, dp));
    }
    if (x+1 < X) {
        plus = min(plus, recurse(grid, key, y, x+1, idx, dp));
    }
    if (keyIdx && x+1+keyIdx < X) {
        plus = min(plus, recurse(grid, key, y, x+1+keyIdx, idx+1, dp));
    }
    dp[y][x][idx] = res + plus;

    return dp[y][x][idx];
}

int main() {
    fast;
    cin >> X >> Y;
    string key;
    cin >> key;
    vector<string> grid(Y);
    for (int i = 0; i < Y; ++i) {
        cin >> grid[i];
    }
    vector<vector<vector<int>>> dp(Y, vector<vector<int>>(X, vector<int>(key.size()+1, -1)));
    for (int i = 0; i < key.size()+1; ++i) {
        dp[0][X-1][i] = (int) (grid[0][X-1] - '0');
    }
    int res = recurse(grid, key, Y-1, 0, 0, dp);
    cout << res << '\n';
}