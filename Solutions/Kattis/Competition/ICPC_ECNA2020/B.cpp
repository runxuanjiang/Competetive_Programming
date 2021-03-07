//Competition #:
//Problem #: B
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int XC[] = {0, 1, 0, -1, 1, 1, -1, -1};
int YC[] = {1, 0, -1, 0, 1, -1, 1, -1};
//          0   1  2  3   4  5   6  7 

ll r, c;

bool dfs(int x, int y, const vector<vector<char>> &grid, const string &targ, int idx, int k, int dir, vector<vector<vector<vector<vector<bool>>>>> &dp) {
    if (idx == targ.length() - 1) {
        return (k == 0);
    }

    if (dir != -1 && !dp[x][y][idx][k][dir]) {
        return false;
    }

    if (dir != -1) {
        if (targ.length() - idx - 1 > k) {
            int nx = x + XC[dir];
            int ny = y + YC[dir];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == targ[idx+1]) {
                if (dfs(nx, ny, grid, targ, idx+1, k, dir, dp)) {
                    return true;
                }
            }
        }

        if (k > 0) {
            for (int i = 0; i < 8; ++i) {
                if (i != dir) {
                    int nx = x + XC[i];
                    int ny = y + YC[i];

                    if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == targ[idx+1]) {
                        if (dfs(nx, ny, grid, targ, idx+1, k-1, i, dp)) {
                            return true;
                        }
                    }
                }

            }
        }
    }
    else {
        for (int i = 0; i < 8; ++i) {
            int nx = x + XC[i];
            int ny = y + YC[i];

            if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == targ[idx+1]) {
                if (dfs(nx, ny, grid, targ, idx+1, k, i, dp)) {
                    return true;
                }
            }
        }
    }

    if (dir != -1) dp[x][y][idx][k][dir] = false;
    return false;
}

int main() {
    fast;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }
    int k;
    cin >> k;
    string targ;
    cin >> targ;

    vector<vector<vector<vector<vector<bool>>>>> dp(r, vector<vector<vector<vector<bool>>>>(c, vector<vector<vector<bool>>>(targ.length(), vector<vector<bool>>(k+1, vector<bool>(8, true)))));

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == targ[0]) {
                if (dfs(i, j, grid, targ, 0, k, -1, dp)) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
}