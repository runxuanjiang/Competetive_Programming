//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ll min_value = -10000000000000;


struct max_combos{
    ll minusminus = min_value;
    ll minusplus = min_value;
    ll plusminus = min_value;
    ll plusplus = min_value;
};

// inline void insert_to_monoqueue(const pair<ll, ll> element, list<pair<ll, ll>> &monoqueue) {
//     while (!monoqueue.empty() && monoqueue.front().first <= element.first) {
//         monoqueue.pop_front();
//     }

//     monoqueue.push_front(move(element));
// }

// inline ll get_max_from_monoqueue(const ll max_index, list<pair<ll, ll>> &monoqueue) {
//     while (!monoqueue.empty() && monoqueue.back().second > max_index) {
//         monoqueue.pop_back();
//     }
//     return monoqueue.back().first;
// }

int main() {
    fast;
    tests {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n), b(n);

        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
        vector<max_combos> max_seen(n+k+1);

        for (int j = 1; j <= k; ++j) {
            for (int i = n-1; i >= 0; --i) {
                ll res = dp[i+1][j];

                const ll key = j+i;
                const ll prev_dp = dp[i+1][j-1];
                const ll a_i = a[i];
                const ll b_i = b[i];
                auto &combos = max_seen[key];
                // cerr << "inserting into minusminus: " << -a[i] - b[i] + dp[i+1][j-1] << ", " << i << '\n';
                // cerr << "inserting into minusplus: " << -a[i] + b[i] + dp[i+1][j-1] << ", " << i << '\n';
                // cerr << "inserting into plusminus: " << a[i] - b[i] + dp[i+1][j-1] << ", " << i << '\n';
                // cerr << "inserting into plusplus: " << a[i] + b[i] + dp[i+1][j-1] << ", " << i << '\n';
                combos.minusminus = max(combos.minusminus, -a_i - b_i + prev_dp);
                combos.minusplus = max(combos.minusplus, -a_i + b_i + prev_dp);
                combos.plusminus = max(combos.plusminus, a_i - b_i + prev_dp);
                combos.plusplus = max(combos.plusplus, a_i + b_i + prev_dp);

                // cerr << "j = " << j << ", i = " << i << '\n';


                const ll max_index = i+k-1;
                // cerr << "max_index: " << max_index << '\n';
                // cerr << "max from minusminus: " << get_max_from_monoqueue(max_index, combos.minusminus) << '\n';
                // cerr << "max from minusplus: " << get_max_from_monoqueue(max_index, combos.minusplus) << '\n';
                // cerr << "max from plusminus: " << get_max_from_monoqueue(max_index, combos.plusminus) << '\n';
                // cerr << "max from plusplus: " << get_max_from_monoqueue(max_index, combos.plusplus) << '\n';

                res = max(res, a_i + b_i + combos.minusminus);
                res = max(res, -a_i + b_i + combos.minusplus);
                res = max(res, a_i - b_i + combos.plusminus);
                res = max(res, -a_i - b_i + combos.plusplus);

                // cerr << "res: " << res << '\n';

                dp[i][j] = res;
            }
        }

        // for (int i = 0; i <= n; ++i) {
        //     for (int j = 0; j <= k; ++j) {
        //         cerr << dp[i][j] << ' ';
        //     }
        //     cerr << '\n';
        // }
        // cerr << "-------------------\n";

        cout << dp[0][k] << '\n';


    }
}