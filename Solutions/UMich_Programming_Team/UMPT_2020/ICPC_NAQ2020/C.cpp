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

int main() {
    fast;
    vector<string> grid(8);
    for (int i = 0; i < 8; ++i) {
        cin >> grid[i];
    }
    int queens = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (grid[i][j] == '*') {
                ++queens;
                for (int x = i+1; x < 8; ++x) {
                    if (grid[x][j] == '*') {
                        cout << "invalid";
                        return 0;
                    }
                }
                for (int y = j+1; y < 8; ++y) {
                    if (grid[i][y] == '*') {
                        cout << "invalid";
                        return 0;
                    }
                }

                int x = i, y = j;
                while (x+1 < 8 && y+1 < 8) {
                    if (grid[x+1][y+1] == '*') {
                        cout << "invalid";
                        return 0;
                    }
                    ++x;
                    ++y;
                }

                x = i;
                y = j;
                while (x+1 < 8 && y-1 >= 0) {
                    if (grid[x+1][y-1] == '*') {
                        cout << "invalid";
                        return 0;
                    }
                    ++x;
                    --y;
                }


            }
        }
    }

    if (queens == 8) {
        cout << "valid";
    }
    else {
        cout << "invalid";
    }
}