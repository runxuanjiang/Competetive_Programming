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


// This will be a sweep line with dp

struct Event {
    ll time;
    ll idx;
    bool isEnd;

    bool operator<(const Event &rhs) const {
        if (time != rhs.time) {
            return time < rhs.time;
        }
        else if (isEnd != rhs.isEnd) {
            return !isEnd;
        }
        return idx < rhs.idx;
    }
};

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            cin >> a[i].second;
        }

        sort(a.begin(), a.end());

        vector<Event> events;
        events.reserve(2*n);

        for (int i = 0; i < n; ++i) {
            events.push_back(Event({a[i].first, i, false}));
            events.push_back(Event({a[i].second, i, true}));
        }

        sort(events.begin(), events.end());
        vector<ll> dp(n+1, 0);

        for (int i = events.size()-1; i >= 0; --i) {
            if (!events[i].isEnd) {
                ll res = dp[events[i].idx + 1];

                for (int j = i+1; j < events.size(); ++j) {

                    if (!events[j].isEnd) {
                        ll endOfPair = max(a[events[i].idx].second, a[events[j].idx].second);
                        auto nextRangeIter = upper_bound(a.begin(), a.end(), make_pair(endOfPair, LLONG_MAX));
                        if (nextRangeIter != a.end()) {
                            res = max(res, 1 + dp[nextRangeIter - a.begin()]);
                        }
                        else {
                            res = max(res, 1ll);
                        }
                    }

                    if (events[j].idx == events[i].idx && events[j].isEnd) {
                        break;
                    }
                }

                dp[events[i].idx] = res;

            }
        }

        // for (auto event : events) {
        //     cerr << event.time << " " << event.idx << " " << event.isEnd << endl;
        // }

        // for (auto range : a) {
        //     cerr << "(" << range.first << "," << range.second << ")" << " ";
        // }
        // cerr << endl;

        // for (auto i : dp) {
        //     cerr << i << " ";
        // }
        // cerr << endl;

        cout << n - dp[0]*2 << endl;




    }
}