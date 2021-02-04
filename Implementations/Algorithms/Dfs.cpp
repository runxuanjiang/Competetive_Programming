#include <iostream>
#include <cassert>
#include <vector>
#include <utility>

using namespace std;

int xcoord[] = {0, 1, 0, -1};
int ycoord[] = {1, 0, -1, 0};

// Given a grid of 1's and 0's, determines whether you can reach the bottom right corner from the x, y.
// through a path of 1's only.
bool dfsMazeGrid(vector<vector<int>> &grid, vector<vector<bool>> &vis, int x, int y) {
    vis[x][y] = true;
    if (x == grid.size() -1 && y == grid[0].size() -1) {
        return true;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + xcoord[i];
        int ny = y + ycoord[i];

        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && !vis[nx][ny] && grid[nx][ny] == 1) {
            if (dfsMazeGrid(grid, vis, nx, ny)) {
                return true;
            }
        }
    }

    return false;
}

// determines if there is a cycle of 1's in the grid starting from x, y.
bool cycleInGrid(vector<vector<int>> &grid, vector<vector<bool>> &vis, int x, int y, int prevx, int prevy) {
    vis[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + xcoord[i];
        int ny = y + ycoord[i];
        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1) {
            if (vis[nx][ny] && (nx != prevx || ny != prevy)) {
                return true;
            }
            else if (!vis[nx][ny]) {
                if (cycleInGrid(grid, vis, nx, ny, x, y)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int>> grid1 = {
        {1, 1, 0, 0, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 1},
        {1, 1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1}
    };

    vector<vector<int>> grid2 = {
        {1, 0, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1}
    };

    vector<vector<int>> grid3 = {
        {1, 1, 0, 0, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 1},
        {1, 1, 0, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 1, 1}
    };

    vector<vector<bool>> vis1(7, vector<bool>(7, false));
    vector<vector<bool>> vis2(4, vector<bool>(4, false));
    vector<vector<bool>> vis3(7, vector<bool>(7, false));

    assert(dfsMazeGrid(grid1, vis1, 0, 0));
    assert(dfsMazeGrid(grid2, vis2, 0, 0));
    assert(!dfsMazeGrid(grid3, vis3, 0, 0));

    vector<vector<int>> grid4 = {
        {1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 1, 1}
    };

    vector<vector<int>> grid5 = {
        {1, 0, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1}
    };

    vector<vector<bool>> vis4(7, vector<bool>(7, false));
    vector<vector<bool>> vis5(4, vector<bool>(4, false));
    bool cycle4 = false, cycle5 = false;

    for (int i = 0; i < grid4.size(); ++i) {
        for (int j = 0; j < grid4[0].size(); ++j) {
            if (grid4[i][j] == 1 && !vis4[i][j] && cycleInGrid(grid4, vis4, i, j, -1, -1)) {
                cycle4 = true;
                break;
            }
        }
        if (cycle4) break;
    }


    for (int i = 0; i < grid5.size(); ++i) {
        for (int j = 0; j < grid5[0].size(); ++j) {
            if (grid5[i][j] == 1 && !vis5[i][j] && cycleInGrid(grid5, vis5, i, j, -1, -1)) {
                cycle5 = true;
                break;
            }
        }
        if (cycle5) break;
    }

    assert(cycle4);
    assert(!cycle5);


    cout << "tests passed" << endl;
}