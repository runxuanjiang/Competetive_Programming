//Competition #:
//Problem #: C
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
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll target = a[0];
        for (auto i : a) {
            target = gcd(target, i);
        }


        set<ll> div_set;

        for (auto i : a) {
            ll normalized = i / target;
            for (int j = 1; j*j <= normalized; ++j) {
                if (normalized % j == 0) {
                    div_set.insert(j);
                    if (j != normalized / j) {
                        div_set.insert(normalized / j);
                    }
                }
            }
        }

        vector<ll> divisors(div_set.begin(), div_set.end());

        unordered_map<ll, ll> divisor_to_index;
        for (int j = 0; j < divisors.size(); ++j) {
            divisor_to_index[divisors[j]] = j;
        }



        vector<vector<ll>> dp(divisors.size(), vector<ll>(n, n));
        for (int j = 0; j < divisors.size(); ++j) {
            for (int k = n - 1; k >= 0; --k) {
                ll curr_normalized = a[k]/target;
                if (divisors[j] == 1) {
                    dp[j][k] = 0;
                }
                else if (k == n-1) {
                    if (gcd(divisors[j], curr_normalized) == 1) {
                        dp[j][k] = 1;
                    }
                    else {
                        dp[j][k] = n;
                    }
                }
                else {
                    dp[j][k] = min(dp[j][k+1], dp[divisor_to_index[gcd(curr_normalized, divisors[j])]][k+1] + 1);
                }
            }
        }

        ll min_to_target = n;
        for (int i = 0; i < n; ++i) {
            ll normalized = a[i] / target;

            if (normalized == 1) {
                min_to_target = 0;
                break;
            }

            min_to_target = min(min_to_target, dp[divisor_to_index[normalized]][0]);

        }

        ll res = 0;
        if (min_to_target > 0) {
            cout << n + min_to_target - 1 << endl;
        }
        else {
            for (auto i : a) {
                if (i != target) {
                    ++res;
                }
            }
            cout << res << endl;
        }

    }
}