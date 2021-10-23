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

int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

int n;

void dfs(int x, int y, const vector<string> &grid, unordered_map<int, unordered_set<int>> &seen) {
    seen[x].insert(y);
    for (int i = 0; i < 4; ++i) {
        int nx = x + X[i], ny = y + Y[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == '0' && seen[nx].find(ny) == seen[nx].end()) {
            dfs(nx, ny, grid, seen);
        }
    }
}

int main() {
    fast;

    cin >> n;

    pair<int, int> coorda, coordb;
    cin >> coorda.first >> coorda.second;
    cin >> coordb.first >> coordb.second;

    --coorda.first;
    --coorda.second;
    --coordb.first;
    --coordb.second;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }


    int res = 2*51*51;
    unordered_map<int, unordered_set<int>> a, b;

    dfs(coorda.first, coorda.second, grid, a);

    if (a[coordb.first].find(coordb.second) != a[coordb.first].end()) {
        cout << 0 << endl;
        return 0;
    }

    dfs(coordb.first, coordb.second, grid, b);

    for (auto i : a) {
        for (auto y1 : i.second) {
            int x1 = i.first;

            for (auto j : b) {
                for (auto y2 : j.second) {
                    int x2 = j.first;

                    res = min(res, abs(x1-x2)*abs(x1-x2) + abs(y1-y2)*abs(y1-y2));
                }
            }
        }
    }

    cout << res << endl;


}