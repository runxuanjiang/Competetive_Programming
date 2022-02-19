//Competition #:
//Problem #: H
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

void recurse(int i, int j, const vector<string> &grid, unordered_set<string> &words, unordered_set<int> &seen, string &curr) {
    if (curr.size() == 10) {
        return;
    }

    seen.insert(i*10 + j);
    curr.push_back(grid[i][j]);
    words.insert(curr);

    for (int k = 0; k < 4; ++k) {
        int nx = i + X[k];
        int ny = j + Y[k];
        if (nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[1].size() && seen.find(nx*10 + ny) == seen.end()) {
            recurse(nx, ny, grid, words, seen, curr);
        }
    }
    seen.erase(i*10 + j);
    curr.pop_back();
}

int main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    unordered_set<string> words;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            unordered_set<int> seen;
            string curr = "";
            recurse(i, j, grid, words, seen, curr);
        }
    }


    int res = 0;
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        if (words.find(s) != words.end()) {
            ++res;
        }
    }
    cout << res << endl;
}