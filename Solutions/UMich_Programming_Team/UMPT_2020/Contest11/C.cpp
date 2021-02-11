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

vector<int> CX = {0, 1, 0, -1};
vector<int> CY = {1, 0, -1, 0};


int n, m;

bool dfs(vector<string> &grid, vector<vector<bool>> &vis, int x, int y, int prevx, int prevy) {
    vis[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int cx = x + CX[i];
        int cy = y + CY[i];


        if (cx >= 0 && cx < n && cy >= 0 && cy < m ) {
            if ((cx != prevx || cy != prevy) && vis[cx][cy] && grid[x][y] == grid[cx][cy]) {
                return true;
            }
        }
    }



    for (int i = 0; i < 4; ++i) {
        int nx = x + CX[i];
        int ny = y + CY[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == grid[x][y] && !vis[nx][ny]) {
            if (dfs(grid, vis, nx, ny, x, y)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    fast;
    cin >> n >> m;

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    bool found = false;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j]) {
                if (dfs(grid, vis, i, j, -1, -1)) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
}