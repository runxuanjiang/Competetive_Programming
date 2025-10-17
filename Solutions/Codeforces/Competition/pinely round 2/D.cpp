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
    fast;
    tests {
        ll n, m;
        cin >> n >> m;

        vector<string> g(n);
        for (auto &i : g) cin >> i;

        ll count = 0;
        bool good = true;
        for (int i = 0; i < n; ++i) {
            count = 0;
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 'U') {
                    ++count;
                    g[i][j] = (count % 2) ? 'B' : 'W'; 
                    g[i+1][j] = (count % 2) ? 'W' : 'B';
                }
            }
            if (count % 2) {
                good = false;
                break;
            }
        }

        if (good) {
            for (int j = 0; j < m; ++j) {
                count = 0;
                for (int i = 0; i < n; ++i) {
                    if (g[i][j] == 'L') {
                        ++count;
                        g[i][j] = (count % 2) ? 'B' : 'W';
                        g[i][j+1] = (count % 2) ? 'W' : 'B';
                    }
                }
                if (count % 2) {
                    good = false;
                    break;
                }
            }
        }


        if (good) {
            for (auto i : g) {
                cout << i << endl;
            }
        }
        else {
            cout << -1 << endl;
        }


    }
}