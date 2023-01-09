//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

bool comp(const pair<ll, ll> &l, const pair<ll, ll> &r) {
    if (l.first == r.first) {
        return (l.second < r.second);
    }
    return (l.first < r.first);
}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        ll ub = 0, lb = n+1;

        vector<pair<ll, ll>> sl;

        for (int i = 0; i < n; ++i) {
            if (b[i] < a[i]) {
                sl.push_back({b[i], 0});
                sl.push_back({a[i]-1, 1});
            }
        }

        sort(sl.begin(), sl.end(), comp);

        vector<ll> bad;
        int idx = 0;
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            while (idx < sl.size() && sl[idx].first == i && !sl[idx].second) {
                ++idx;
                ++count;
            }
            if (count) {
                bad.push_back(i);
            }
            while (idx < sl.size() && sl[idx].first == i) {
                --count;
                ++idx;
            }
        }

        unordered_set<int> erase;
        for (auto i : bad) {
            for (int j = 1; j*j <= i; ++j) {
                if (i % j == 0) {
                    erase.insert(j);
                    erase.insert(i / j);
                }
            }
        }

        cout << n - erase.size() << endl;
        for (int i = 1; i <= n; ++i) {
            if (erase.find(i) == erase.end()) {
                cout << i << " ";
            }
        }
        cout << endl;


    }
}