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

struct Event{
    ll index;
    bool isEnd;
    ll event_id;

};

bool compEvent(const Event &a, const Event &b) {
    if (a.index == b.index) {
        return a.isEnd < b.isEnd;
    }
    return a.index < b.index;
}

int main() {
    fast;
    ll n, m, q;
    cin >> n >> m >> q;

    string s;
    cin >> s;

    vector<pair<ll, ll>> a(m);
    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        a[i] = {x-1, y-1};
    }


    vector<Event> events;
    for (ll i = 0; i < m; ++i) {
        events.push_back({a[i].first, 0, i});
        events.push_back({a[i].second, 1, i});
    }

    sort(events.begin(), events.end(), compEvent);

    // for (const auto &e : events) {
    //     cerr << "(" << e.index << ", " << e.isEnd << ", " << e.event_id << ") ";
    // }
    // cerr << endl;

    vector<pair<ll, ll>> priorities;

    ll events_iter = 0;
    set<ll> active_intervals;
    for (ll i = 0; i < n; ++i) {
        while (events_iter < events.size() && events[events_iter].index == i && !events[events_iter].isEnd) {
            active_intervals.insert(events[events_iter].event_id);
            ++events_iter;
        }
        
        const auto minPriorityIter = active_intervals.begin();
        const ll priority = (minPriorityIter == active_intervals.end()) ? m : *minPriorityIter;
        priorities.push_back({priority, i});


        while (events_iter < events.size() && events[events_iter].index == i && events[events_iter].isEnd) {
            active_intervals.erase(events[events_iter].event_id);
            ++events_iter;
        }
    }

    sort(priorities.begin(), priorities.end());

    // for (const auto p : priorities) {
    //     cerr << "(" << p.first << ", " << p.second << ") ";
    // }
    // cerr << endl;

    vector<ll> id_map(n, 0);
    ll ones = 0;
    for (int i = 0; i < n; ++i) {
        id_map[priorities[i].second] = i;
        if (s[priorities[i].second] == '1') {
            ++ones;
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     cerr << id_map[i] << " ";
    // }
    // cerr << endl;

    ll first_extra = n;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (priorities[i].first == m && first_extra == n) {
            first_extra = i;
        }

        if (i < ones && i < first_extra && s[priorities[i].second] == '0') {
            ++res;
        }
    }

    // cerr << "res is originally: " << res << endl;

    for (int _ = 0; _ < q; ++_) {
        ll bit;
        cin >> bit;
        --bit;

        ll index = id_map[bit];
        if (s[bit] == '0') {
            s[bit] = '1';

            if (index < min(ones, first_extra)) {
                --res;
            }

            ++ones;

            if (ones <= first_extra) {
                ll s_index = priorities[ones-1].second;
                if (s[s_index] == '0') {
                    ++res;
                }
            }
        }
        else {
            s[bit] = '0';
            if (ones <= first_extra) {
                ll s_index = priorities[ones-1].second;
                if (s[s_index] == '0') {
                    --res;
                }
            }
            if (index < min(ones, first_extra)) {
                ++res;
            }
            --ones;


        }

        // cerr << "(s, ones, index): " << s << " " << ones << " " << index << endl;

        cout << res << endl;
        
    }

}