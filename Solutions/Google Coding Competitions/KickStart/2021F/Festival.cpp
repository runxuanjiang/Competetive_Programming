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

int testnum = 0;

struct Comp{
    bool operator() (const pair<ll, pair<ll, ll>> &l, const pair<ll, pair<ll, ll>> &r) {
        if (l.first == r.first) {
            return l.second.first < r.second.first;
        }
        return l.first < r.first;
    }
};

int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";
        ll d, n, k;
        cin >> d >> n >> k;

        vector<pair<ll, pair<ll, ll>>> events;
        vector<ll> a;

        for (int i = 0; i < n; ++i) {
            ll s, e, h;
            cin >> h >> s >> e;
            events.push_back({s, {1, a.size()}});
            events.push_back({e+1, {0, a.size()}});
            a.push_back(h);
        }

        sort(events.begin(), events.end(), Comp());
        set<pair<ll, ll>> l, r;
        ll tempres = 0;

        ll res = 0;
        for (auto e : events) {
            if (e.second.first) {
                if (l.size() == k) {
                    if (a[e.second.second] > (l.begin())->first) {
                        tempres -= l.begin()->first;
                        tempres += a[e.second.second];
                        r.insert(*(l.begin()));
                        l.erase(l.begin());
                        l.insert({a[e.second.second], e.second.second});
                    }
                    else {
                        r.insert({a[e.second.second], e.second.second});
                    }
                }
                else {
                    tempres += a[e.second.second];
                    l.insert({a[e.second.second], e.second.second});
                }
            }
            else {
                auto iter = l.find({a[e.second.second], e.second.second});
                if (iter != l.end()) {
                    tempres -= iter->first;
                    l.erase(iter);

                    if (!r.empty()) {
                        auto addIter = --r.end();
                        tempres += addIter->first;
                        l.insert(*addIter);
                        r.erase(addIter);
                    }
                }

                iter = r.find({a[e.second.second], e.second.second});
                if (iter != r.end()) {
                    r.erase(iter);
                }


            }

            res = max(res, tempres);
        }

        cout << res << endl;

    }
}