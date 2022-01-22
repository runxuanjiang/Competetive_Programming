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
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '.') {
                if (i <= n-3 && j > 0 && j <= n-2 && grid[i+1][j-1] == '.' && grid[i+1][j] == '.' && grid[i+1][j+1] == '.' && grid[i+2][j] == '.') {
                    grid[i][j] = '#';
                    grid[i+1][j-1] = '#';
                    grid[i+1][j] = '#';
                    grid[i+1][j+1] = '#';
                    grid[i+2][j] = '#';
                }
                else {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
}