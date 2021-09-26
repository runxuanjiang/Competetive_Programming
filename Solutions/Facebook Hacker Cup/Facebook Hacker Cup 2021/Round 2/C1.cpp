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
int testnum = 0;

int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";

        ll r, c, k;
        cin >> r >> c >> k;
        --k;
        vector<vector<bool>> grid(r, vector<bool>(c, false));
        for (int i = 0; i < r; ++i) {
            string in;
            cin >> in;
            for (int j = 0; j < c; ++j) {
                if (in[j] == 'X') {
                    grid[i][j] = 1;
                }
            }
        }


        ll res;
        ll tres1 = INT_MAX;
        vector<ll> ccount(c, 0);
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j]) {
                    ccount[j]++;
                }
            }
        }

        for (int i = k; i < r; ++i) {
            ll cars = 0;
            for (int j = 0; j < c; ++j) {
                if (grid[i][j]) {
                    ++cars;
                    ccount[j]++;
                }
                else if (ccount[j] > k) {
                    ++cars;
                }
            }

            // cout << (i-k) + cars << endl;

            tres1 = min(tres1, (i - k) + cars);
        }
        ll tcars = 0;
        for (int j = 0; j < c; ++j) {
            if (ccount[j] > k) {
                ++tcars;
            }
        }
        tres1 = min(tres1, (r - k) + tcars);
        // cout << (r-k) + tcars << endl;
        // cout << endl;


        ll tres2 = INT_MAX;
        ccount = vector<ll>(c, 0);
        for (int i = r-1; i > k; --i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j]) {
                    ccount[j]++;
                }
            }
        }

        for (int i = k; i >= 0; --i) {
            ll cars = 0;
            for (int j = 0; j < c; ++j) {
                if (grid[i][j]) {
                    ++cars;
                    ccount[j]++;
                }
                else if (ccount[j] >= r-k) {
                    ++cars;
                }
            }
            tres2 = min(tres2, (k-i) + cars);
            // cout << (k-i) + cars << endl;
        }
        tcars = 0;
        for (int j = 0; j < c; ++j) {
            if (ccount[j] >= r - k) {
                ++tcars;
            }
        }
        tres2 = min(tres2, k + 1 + tcars);
        // cout << k+1+tcars << endl;


        res = min(tres1, tres2);
        cout << res << endl;


    }
}