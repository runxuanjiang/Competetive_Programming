//Competition #:
//Problem #: D
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
    ll n, m;
    cin >> n >> m;


    vector<vector<ll>> grid(n, vector<ll>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    ll res = 0;

    for (int i = n-1; i >= 0; --i) {
        for (int j = m-1; j >= 0; --j) {

            if (grid[i][j]) {
                if (i != n-1 && grid[i][j] >= grid[i+1][j]) {
                    cout << -1 << endl;
                    return 0;
                }
                if (j != m-1 && grid[i][j] >= grid[i][j+1]) {
                    cout << -1 << endl;
                    return 0;
                }
            }
            else {
                grid[i][j] = min(grid[i+1][j], grid[i][j+1]) - 1;

                if (grid[i][j] <= 0) {
                    cout << -1 << endl;
                    return 0;
                }
            }

            res += grid[i][j];
        }
    }

    cout << res << endl;
}