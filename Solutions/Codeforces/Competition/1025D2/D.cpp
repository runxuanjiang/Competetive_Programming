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
        ll n, m, l;
        cin >> n >> m >> l;

        vector<ll> a(l);
        for (ll i = 0; i < l; i++) {
            cin >> a[i];
        }

        vector<ll> earliest_reach_even(n, LONG_LONG_MAX);
        vector<ll> earliest_reach_odd(n, LONG_LONG_MAX);

        vector<vector<ll>> graph(n);

        for (int i = 0; i < m; ++i) {
            ll a, b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        vector<ll> curr, next;
        vector<bool> seen(n, false);
        seen[0]  = true;
        earliest_reach_even[0] = 0;
        curr.push_back(0);

        ll length = 0;
        while (!curr.empty())  {
            length += 2;
            for (auto i : curr) {
                for (auto child : graph[i]) {
                    for (auto grandchild : graph[child]) {
                        if (!seen[grandchild]) {
                            seen[grandchild] = true;
                            next.push_back(grandchild);
                            if (earliest_reach_even[grandchild] == LONG_LONG_MAX) {
                                earliest_reach_even[grandchild] = length;
                            }
                        }
                    }
                }
            }

            curr.clear();
            swap(curr, next);
        }

        curr.clear();
        next.clear();
        seen.assign(n, false);
        for (auto child : graph[0]) {
            seen[child] = true;
            curr.push_back(child);
            earliest_reach_odd[child] = 1;
        }
        length = 1;
        while (!curr.empty()) {
            length += 2;
            for (auto i : curr) {
                for (auto child : graph[i]) {
                    for (auto grandchild : graph[child]) {
                        if (!seen[grandchild]) {
                            seen[grandchild] = true;
                            next.push_back(grandchild);
                            if (earliest_reach_odd[grandchild] == LONG_LONG_MAX) {
                                earliest_reach_odd[grandchild] = length;
                            }
                        }
                    }
                }
            }

            curr.clear();
            swap(curr, next);
        }

        ll sum_a = 0;
        ll min_odd_element = LONG_LONG_MAX;
        for (auto i : a) {
            sum_a += i;
            if (i % 2 == 1) {
                min_odd_element = min(min_odd_element, i);
            }
        }

        ll highest_even = 0, highest_odd = -1;
        if (sum_a % 2 == 0) {
            highest_even = sum_a;
            if (min_odd_element != LONG_LONG_MAX) {
                highest_odd = sum_a - min_odd_element;
            }
        }
        else {
            highest_odd = sum_a;
            if (min_odd_element != LONG_LONG_MAX) {
                highest_even = sum_a - min_odd_element;
            }
        }


        // print out everything
        // cout << "highest_even: " << highest_even << endl;
        // cout << "highest_odd: " << highest_odd << endl;
        // cout << "earliest_reach_even: ";
        // for (int i = 0; i < n; ++i) {
        //     cout << earliest_reach_even[i] << " ";
        // }
        // cout << endl;
        // cout << "earliest_reach_odd: ";
        // for (int i = 0; i < n; ++i) {
        //     cout << earliest_reach_odd[i] << " ";
        // }
        // cout << endl;

        for (int i = 0; i < n; ++i) {
            if (highest_even >= earliest_reach_even[i] || highest_odd >= earliest_reach_odd[i]) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        cout << endl;
    }
}