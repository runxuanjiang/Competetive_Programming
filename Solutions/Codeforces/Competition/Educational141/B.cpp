//Competition #:
//Problem #: B
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
    tests {
        ll n;
        cin >> n;

        ll l = 1, r = n*n;
        vector<vector<ll>> grid(n, vector<ll>(n, 0));
        bool left = true;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int idx = j;
                if (i % 2) {
                    idx = n-j-1;
                }

                if (left) {
                    grid[i][idx] = l;
                    ++l;
                }
                else {
                    grid[i][idx] = r;
                    --r;
                }
                left = !left;
            }
        }

        for (auto i : grid) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
}