#include <bits/stdc++.h>

using namespace std;

int xcoord[] = {0, 0, 1, -1};
int ycoord[] = {1, -1, 0, 0};

bool dfsMazeGrid(vector<vector<int>> grid) {
    // if (x < 0 || x >= grid.size()) return false;
    // if (y < 0 || y >= grid[0].size()) return false;

    pair<int, int> start = {0, 0};

    stack<pair<int, int>> dfs;
    dfs.push(start);
    while (!dfs.empty()) {
        pair<int, int> p = dfs.top();
        dfs.pop();
        for (int i = 0; i < 4; ++i) {
            int x = p.first + xcoord[i];
            int y = p.second + ycoord[i];
            if (x < 0 || x >= grid.size()) continue;
            if (y < 0 || y >= grid[0].size()) continue;
            dfs.push({x, y});
        }
    }
}