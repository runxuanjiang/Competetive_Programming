//Competition #: 946
//Problem #: D
//Accepted: yes

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<vector<int>> days;
    for (int i = 0; i < n; ++i) {
        vector<int> day;
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == '1') {
                day.push_back(j);
            }
        }
        days.push_back(day);
    }

    vector<vector<int>> dp1(n, vector<int>(k+1, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j >= days[i].size()) {
                dp1[i][j] = 0;
                continue;
            }
            for (int l = 0; l <= j; ++l) {
                int r = days[i].size() - (j - l);

                int len;
                if (l == r) {
                    len = 0;
                }
                else {
                    len = (days[i][r-1] - days[i][l] + 1);
                }

                if (dp1[i][j] == -1) {
                    dp1[i][j] = len;
                }
                else {
                    dp1[i][j] = min(dp1[i][j], len);
                }
                
            }
        }
    }
    // cout << "dp1: " << endl;
    // for (auto i : dp1) {
    //     for (auto j : i) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    vector<vector<int>> dp2(n, vector<int>(k+1, -1));
    for (int j = 0; j <= k; ++j) {
        dp2[0][j] = dp1[0][j];

    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            int len = -1;
            for (int l = 0; l <= k; ++l) {
                if (dp1[i][l] == -1 || l > j || dp2[i-1][j-l] == -1) {
                    continue;
                }
                
                if (len == -1) {
                    len = dp1[i][l] + dp2[i-1][j - l];
                }
                else {
                    len = min(len, dp1[i][l] + dp2[i-1][j - l]);
                }
            }
            if (len == -1) {
                dp2[i][j] = dp2[i][j-1];
            }
            else {
                dp2[i][j] = len;
            }

        }
    }

    // cout << "dp2:" << endl;
    // for (auto i : dp2) {
    //     for (auto j : i) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    cout <<  dp2[n-1][k] << endl;

}