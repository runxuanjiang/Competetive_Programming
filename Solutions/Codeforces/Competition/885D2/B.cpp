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
        ll n, k;
        cin >> n >> k;

        vector<ll> c(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        unordered_map<ll, ll> color_to_previous_occurrence;
        unordered_map<ll, pair<ll, ll>> color_to_longest_two_gaps;

        for (int i = 0; i < n; ++i) {

            if (i - color_to_previous_occurrence[c[i]] > color_to_longest_two_gaps[c[i]].first) {
                color_to_longest_two_gaps[c[i]].second = color_to_longest_two_gaps[c[i]].first;
                color_to_longest_two_gaps[c[i]].first = i - color_to_previous_occurrence[c[i]];
            }
            else if (i - color_to_previous_occurrence[c[i]] > color_to_longest_two_gaps[c[i]].second) {
                color_to_longest_two_gaps[c[i]].second = i - color_to_previous_occurrence[c[i]];
            }
            color_to_previous_occurrence[c[i]] = i+1;
        }

        ll res = n;
        for (const auto i : color_to_longest_two_gaps) {
            ll longest_gap = i.second.first;
            ll second_longest_gap = i.second.second;
            if (n - color_to_previous_occurrence[i.first] > longest_gap) {
                second_longest_gap = longest_gap;
                longest_gap = n - color_to_previous_occurrence[i.first];
            }
            else if (n - color_to_previous_occurrence[i.first] > second_longest_gap) {
                second_longest_gap = n - color_to_previous_occurrence[i.first];
            }
            ll current_res = max((longest_gap/2), second_longest_gap);
            res = min(res, current_res);
        }

        cout << res << endl;
    }
}