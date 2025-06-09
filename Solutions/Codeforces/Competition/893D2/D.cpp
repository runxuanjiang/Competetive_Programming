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
        ll n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<vector<ll>> dp_prefix(n, vector<ll>(k+1, 0));
        vector<vector<ll>> dp_suffix(n, vector<ll>(k+1, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                if (i == 0) {
                    if (s[i] == '0') {
                        dp_prefix[i][j] = 1;
                    }
                    else {
                        if (j > 0) {
                            dp_prefix[i][j] = 1;
                        }
                    }
                }
                else {
                    if (s[i] == '0') {
                        dp_prefix[i][j] = 1 + dp_prefix[i-1][j];
                    }
                    else {
                        if (j > 0) {
                            dp_prefix[i][j] = 1 + dp_prefix[i-1][j-1];
                        }
                    }
                }
            }
        }


        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j <= k; ++j) {
                if (i == n-1) {
                    if (s[i] == '0') {
                        dp_suffix[i][j] = 1;
                    }
                    else {
                        if (j > 0) {
                            dp_suffix[i][j] = 1;
                        }
                    }
                }
                else {
                    if (s[i] == '0') {
                        dp_suffix[i][j] = 1 + dp_suffix[i+1][j];
                    }
                    else {
                        if (j > 0) {
                            dp_suffix[i][j] = 1 + dp_suffix[i+1][j-1];
                        }
                    }
                }
            }
        }


        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp_prefix[i][j] = max(dp_prefix[i][j], dp_prefix[i-1][j]);
            }
        }

        for (int i = n-2; i >= 0; --i) {
            for (int j = 0; j <= k; ++j) {
                dp_suffix[i][j] = max(dp_suffix[i][j], dp_suffix[i+1][j]);
            }
        }

        vector<ll> res_by_length(n+1, LONG_LONG_MIN);

        res_by_length[0] = dp_prefix[n-1][k];

        for (int i = 0; i < n; ++i) {
            ll zeros = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '0') {
                    zeros++;
                }

                ll length = j-i+1;
                if (zeros <= k) {
                    if (i == 0 && j == n-1) {
                        res_by_length[length] = 0;
                    }
                    else if (i == 0) {
                        res_by_length[length] = max(res_by_length[length], dp_suffix[j+1][k-zeros]);
                    }
                    else if (j == n-1) {
                        res_by_length[length] = max(res_by_length[length], dp_prefix[i-1][k-zeros]);
                    }
                    else {
                        res_by_length[length] = max(res_by_length[length], max(dp_prefix[i-1][k-zeros], dp_suffix[j+1][k-zeros]));
                    }
                }
            }
        }

        // for (int i = 0; i <= n; ++i) {
        //     cerr << res_by_length[i] << " ";
        // }
        // cerr << endl;

        for (ll i = 1; i <= n; ++i) {
            ll res = 0;
            for (ll len = 0; len <= n; ++len) {
                if (res_by_length[len] != LONG_LONG_MIN) {
                    res = max(res, len + i*res_by_length[len]);
                }
            }

            cout << res << " ";
        }
        cout << endl;



    }
}