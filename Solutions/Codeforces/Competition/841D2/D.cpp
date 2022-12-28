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

bool check (ll m, const vector<vector<ll>> &grid) {
    vector<vector<bool>> bgrid(grid.size(), vector<bool>(grid[0].size()));

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            bgrid[i][j] = (grid[i][j] >= m);
        }
    }


    vector<vector<ll>> psum(grid.size() + 1, vector<ll>(grid[0].size() + 1));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            psum[i+1][j+1] = bgrid[i][j] + psum[i][j+1] + psum[i+1][j] - psum[i][j];
        }
    }


    for (int i = 0; i < grid.size(); ++i) {
        if (i + m > grid.size()) {
            break;
        }
        for (int j = 0; j < grid[0].size(); ++j) {
            if (j + m > grid[0].size()) {
                break;
            }

            if (psum[i+m][j+m] - psum[i+m][j] - psum[i][j+m] + psum[i][j] >= m*m) {
                return true;
            }

        }
    }

    return false;


}

int main() {
    fast;
    tests {
        ll n, m;
        cin >> n >> m;

        vector<vector<ll>> grid(n, vector<ll>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        ll res = 1;
        ll l = 1, r = min(n, m);
        while (l <= r) {
            ll mid = l + (r-l)/2;
            if (check(mid, grid)) {
                res = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }

        cout << res << endl;


    }
}