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
        ll n;
        cin >> n;
        vector<pair<ll, ll>> outer_bound(n), inner_bound(n);
        for (int i = 0; i < n; ++i) {
            cin >> outer_bound[i].first >> outer_bound[i].second;
            cin >> inner_bound[i].first >> inner_bound[i].second;
        }

        vector<pair<ll, ll>> dists;
        for (int i = 0; i < n; ++i) {
            dists.push_back({outer_bound[i].first, inner_bound[i].second});
        }
        sort(dists.begin(), dists.end());

        // print out dists
        // cout << "Distances:" << endl;
        // for (auto& [first, second] : dists) {
        //     cout << first << " " << second << endl;
        // }

        map<ll, ll> max_dist;
        max_dist[0] = 0;
        ll start = 0, end = 0;


        for (int i = 0; i < n; ++i) {

            start = dists[i].first;
            end = dists[i].second;
            while (i+1 < n && dists[i+1].first <= end) {
                ++i;
                end = max(end, dists[i].second);
            }

            max_dist[start] = end;
        }

        // print out max dists
        // cout << "Max Distances:" << endl;
        // for (auto& [key, value] : max_dist) {
        //     cout << key << " " << value << endl;
        // }

        ll q;
        cin >> q;

        for (int i = 0; i < q; ++i) {
            ll x;
            cin >> x;

            auto iter = max_dist.upper_bound(x);
            --iter;
            cout << max(x, iter->second) << " ";

        }

        cout << endl;

    }
}