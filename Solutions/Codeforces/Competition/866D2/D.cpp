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

bool check(multiset<pair<ll, ll>> w, multiset<pair<ll, ll>> h) {
    ll prev = -1;
    while (!w.empty()) {
        ll top = (--w.end())->first;
        ll curr = 0;
        while (!w.empty() && (--w.end())->first == top) {
            curr += (--w.end())->second;
            h.erase({(--w.end())->second, (--w.end())->first});
            w.erase(--w.end());
        }

        if (w.empty()) {
            return (prev == -1 || curr == prev);
        }

        if (prev != -1) {
            if (prev - curr != (--h.end())->first) {
                return false;
            }

        }

        prev = top;
        swap(w, h);
    }

    return false;
}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cin >> b[i];
        }

        if (n == 1) {
            cout << 1 << endl;
            cout << a[0] << " " << b[0] << endl;
            continue;
        }

        ll tot = 0;

        ll maxw = 0, maxh = 0;
        for (int i = 0; i < n; ++i) {
            maxw = max(maxw, a[i]);
            maxh = max(maxh, b[i]);
            tot += (a[i] * b[i]);
        }


        multiset<pair<ll, ll>> w, h;
        for (int i = 0; i < n; ++i) {
            w.insert({a[i], b[i]});
            h.insert({b[i], a[i]});
        }

        vector<pair<ll, ll>> res;


        if (check(w, h)) {
            res.push_back({maxw, tot/maxw});
        }

        if (check(h, w)) {
            res.push_back({tot/maxh, maxh});
        }

        cout << res.size() << endl;
        for (auto i : res) {
            cout << i.first << " " << i.second << endl;
        }


    }
}