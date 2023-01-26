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
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<ll> c(m);
        for (int i = 0; i < m; ++i) {
            cin >> c[i];
        }

        sort(c.begin(), c.end());

        unordered_map<ll, ll> dishes;
        for (auto i : a) {
            if (dishes.find(i) == dishes.end()) {
                dishes[i] = 0;
            }
            dishes[i]++;
        }

        set<pair<ll, ll>> people;
        for (auto i : dishes) {
            people.insert({i.second, i.first});
        }

        ll res = 0;
        for (ll i = m-1; i >= 0; --i) {
            if (people.empty()) {
                break;
            }
            ll ppl = (--people.end())->first;
            ll dish = (--people.end())->second;
            people.erase((--people.end()));
            if (ppl > c[i]) {
                res += c[i];
                people.insert({ppl - c[i], dish});
            }
            else {
                res += ppl;
            }
        }
        cout << res << endl;
    }
}