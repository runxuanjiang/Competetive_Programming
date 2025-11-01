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
        ll n, k, a, b;
        cin >> n >> k >> a >> b;
        --a;
        --b;

        vector<pair<ll, ll>> coords(n);
        for (auto &coord : coords) {
            cin >> coord.first >> coord.second;
        }

        ll res = abs(coords[a].first - coords[b].first) + abs(coords[a].second - coords[b].second);

        ll min_major_dist_a = 1e10;
        ll min_major_dist_b = 1e10;
        for (int i = 0; i < k; ++i) {
            min_major_dist_a = min(min_major_dist_a, abs(coords[a].first - coords[i].first) + abs(coords[a].second - coords[i].second));
            min_major_dist_b = min(min_major_dist_b, abs(coords[b].first - coords[i].first) + abs(coords[b].second - coords[i].second));
        }

        cout << min(res, min_major_dist_a + min_major_dist_b) << endl;
    }
}