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
        vector<ll> h(n), p(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        multiset<pair<ll, ll>> h2p, p2h;
        for (int i = 0; i < n; ++i) {
            h2p.insert({h[i], p[i]});
            p2h.insert({p[i], h[i]});
        }

        bool good = true;
        ll attack = 0;
        while (!h2p.empty()) {
            attack += k;
            ll health = h2p.begin()->first;
            while (!h2p.empty() && h2p.begin()->first <= attack) {
                p2h.erase(p2h.find({h2p.begin()->second, h2p.begin()->first}));
                h2p.erase(h2p.begin());
            }

            if (!p2h.empty()) {
                ll power = p2h.begin()->first;
                k -= power;
                if (k <= 0) {
                    good = false;
                    break;
                }
            }
        }

        if (good) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}