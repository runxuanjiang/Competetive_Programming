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

        vector<vector<ll>> grid(2, vector<ll>(n));

        for (int i = 0; i < n; ++i) {
            grid[0][i] = 2*n-i;
            grid[1][n-i-1] = 2*n-i-1;
            grid[1][n-i-2] = i+1;
            grid[0][i+1] = i+2;
            ++i;
        }

        for (auto i : grid) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
}