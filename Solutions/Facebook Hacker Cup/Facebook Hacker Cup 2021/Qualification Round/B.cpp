//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int numtests = 0;

int main() {
    fast;
    tests {
        numtests++;
        cout << "Case #" << numtests << ": ";
        int n;
        cin >> n;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        int res = -1;
        int res2 = 0;
        unordered_set<int> checked;// checked rows

        for (int i = 0; i < n; ++i) {
            int x = 0;
            bool done = false;
            for (auto j : grid[i]) {
                if (j == 'X') {
                    ++x;
                }
                else if (j == 'O') {
                    done = true;
                }
            }

            if (done) {
                continue;
            }

            if (res == -1) {
                res = n - x;
                ++res2;
            }
            else if (n-x == res) {
                ++res2;
            }
            else if (n-x < res) {
                res = n-x;
                res2 = 1;
            }

            if (x == n-1) {
                int col;
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == '.') {
                        col = j;
                        break;
                    }
                }
                int dots = 0;
                for (int j = 0; j < n; ++j) {
                    if (grid[j][col] == '.') {
                        ++dots;
                    }
                    else if (grid[j][col] == 'O') {
                        dots = 5;
                        break;
                    }
                }
                if (dots == 1) {
                    checked.insert(col);
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            if (checked.find(j) == checked.end()) {
                int x = 0;
                bool done = false;
                for (int i = 0; i < n; ++i) {
                    if (grid[i][j] == 'X') {
                        ++x;
                    }
                    else if (grid[i][j] == 'O') {
                        done = true;
                        break;
                    }
                }

                if (done) {
                    continue;
                }

                if (res == -1) {
                    res = n - x;
                    ++res2;
                }
                else if (n-x == res) {
                    ++res2;
                }
                else if (n-x < res) {
                    res = n-x;
                    res2 = 1;
                }
            }
        }

        if (res2 == 0) {
            cout << "Impossible" << endl;
        }
        else {
            cout << res << " " << res2 << endl;
        }

    }
}