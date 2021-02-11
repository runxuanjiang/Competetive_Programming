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

int XC[] = {0, 1, 0, -1};
int YC[] = {1, 0, -1, 0};

bool dfs(vector<string> &grid, vector<vector<bool>> &vis, ll x, ll y) {
    vis[x][y] = true;

    int move;
    if (grid[x][y] == 'N') {
        move = 3;
    }
    else if (grid[x][y] == 'S') {
        move = 1;
    }
    else if (grid[x][y] == 'E') {
        move = 0;
    }
    else if (grid[x][y] == 'W') {
        move = 2;
    }

    int nx = x + XC[move];
    int ny = y + YC[move];

    if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
        if (!vis[nx][ny]) {
            if (dfs(grid, vis, nx, ny)) {
                grid[x][y] = '+';
                return true;
            }
            else {
                grid[x][y] = '-';
                return false;
            }
        }
        else {
            if (grid[nx][ny] == '+') {
                grid[x][y] = '+';
                return true;
            }
            else {
                grid[x][y] = '-';
                return false;
            }
        }
    }
    else {
        grid[x][y] = '+';
        return true;
    }
}

int main() {
    fast;
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    ll res = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j]!= '+' && grid[i][j] != '-') {
                dfs(grid, vis, i, j);
            }

            if (grid[i][j] == '-') {
                ++res;
            }
        }
    }


    cout << res << endl;
}