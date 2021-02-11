//Competition #:
//Problem #: E
//Accepted: YES

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int n, m;

int xcoord[] = {0, 1, 0, -1};
int ycoord[] = {1, 0, -1, 0};

void dfs(vector<string> &grid, vector<vector<bool>> &vis, int x, int y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + xcoord[i];
        int ny = y + ycoord[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] == grid[x][y]) {
            dfs(grid, vis, nx, ny);
        }
    }
}

int count(vector<string> &grid) {
    int res = 0;
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j]) {
                dfs(grid, vis, i, j);
                ++res;
            }
        }
    }
    return res;
}

int main() {
    fast;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '?') {
                q.push_back({i, j});
            }
        }
    }

    int res = 10000;

    unsigned lim = 1 << q.size();
    for (unsigned i = 0; i < lim; ++i) {
        bitset<16> bits(i);
        for (int j = 0; j < q.size(); ++j) {
            grid[q[j].first][q[j].second] = (bits[j]) ? '1' : '0';
        }
        res = min(res, count(grid));
    }

    cout << res << endl;
}