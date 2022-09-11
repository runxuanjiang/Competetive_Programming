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

int casenum = 0;

int main() {
    fast;
    tests {
        ++casenum;
        cout << "Case #" << casenum << ": ";
        ll r, c;
        cin >> r >> c;
        vector<string> grid(r);
        for (int i = 0; i < r; ++i) {
            cin >> grid[i];
        }

        bool trees = 0;
        for (auto i : grid) {
            for (auto j : i) {
                if (j == '^') {
                    trees = true;
                }
            }
        }

        if ((r == 1 || c == 1) && trees) {
            cout << "Impossible" << endl;
        }
        else {
            if (trees) {
                for (auto &i : grid) {
                    for (auto &j : i) {
                        j = '^';
                    }
                }
            }

            cout << "Possible" << endl;
            for (auto i : grid) {
                cout << i << endl;
            }
        }
    }
}