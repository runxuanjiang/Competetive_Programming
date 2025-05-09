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
        ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        vector<pair<ll, ll>> ranges(m);
        for (int i = 0; i < m; ++i) {
            ll l, r;
            cin >> l >> r;
            ranges[i] = {l-1, r-1};
        }

        sort(ranges.begin(), ranges.end());

        vector<ll> zeros_before_current_index(n);

        ll total_zeros = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ++total_zeros;

            }
            zeros_before_current_index[i] = total_zeros;
        }

        bool original_string = 0;

        ll range_idx = 0;

        ll res = 0;
        ll zeros = 0;
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (j < n && s[j] == '0') {
                ++j;
            }

            if (j >= n) {
                if (range_idx < m) {
                    original_string = 1;
                }
                break;
            }

            ll zeros_in_group = (s[i] == '0') ? j-i : 0;

            cerr << "currently on range " << i << " " << j << endl;

            unordered_set<int> distinct_zeros_moved;
            while (range_idx < m && ranges[range_idx].first >= i && ranges[range_idx].first <= j) {
                ll zeros_moved = max(0ll, zeros_before_current_index[ranges[range_idx].second] - zeros - (zeros_in_group));
                if (zeros_moved > 0) {
                    distinct_zeros_moved.insert(zeros_moved);
                }
                else {
                    original_string = true;
                }

                ++range_idx;
            }
            res += distinct_zeros_moved.size();

            cerr << "zeros moved: " << endl;
            for (auto x : distinct_zeros_moved) {
                cerr << x << " ";
            }
            cerr << endl;

            zeros += zeros_in_group;
            i = j;


        }

        cerr << "answer: " << endl;
        cout << res + original_string << endl;
    }
}