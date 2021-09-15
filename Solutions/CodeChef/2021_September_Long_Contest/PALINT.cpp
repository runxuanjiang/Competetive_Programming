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

struct Comp{
    bool operator() (const pair<ll, ll> &l, const pair<ll, ll> &r) {
        if (l.first == r.first) {
            return l.second < r.second;
        }
        return l.first > r.first;
    }
};

int main() {
    fast;
    tests {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        unordered_map<ll, pair<ll, ll>> counts;
        for (auto i : a) {
            if (counts.find(i) == counts.end()) {
                counts[i] = {0, 0};
            }

            ++counts[i].first;
            ll other = i ^ x;
            if (other != i) {
                if (counts.find(other) == counts.end()) {
                    counts[other] = {0, 0};
                }
                ++counts[other].first;
                ++counts[other].second;
            }
        }

        ll res1 = 0, res2 = 0;
        vector<pair<ll, ll>> sorted;
        for (auto i : counts) {
            sorted.push_back({i.second.first, i.second.second});
        }

        sort(sorted.begin(), sorted.end(), Comp());

        cout << sorted[0].first << " " << sorted[0].second << endl;
    }
}