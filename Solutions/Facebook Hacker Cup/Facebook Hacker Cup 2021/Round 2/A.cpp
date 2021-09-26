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

ll swaps(unordered_map<ll, pair<vector<int>, vector<int>>> &curr, vector<bool> &swapped, const vector<ll> &r) {

    ll res = 0;

    vector<ll> rem;
    unordered_map<ll, pair<vector<int>, vector<int>>> next;
    for (auto i : r) {
        if (curr.find(i) != curr.end()) {

            if (!curr[i].second.empty()) {
                next[i].second.push_back(curr[i].second.back());
                curr[i].second.pop_back();
            }
            else {
                next[i].first.push_back(curr[i].first.back());
                curr[i].first.pop_back();
            }
            if (curr[i].first.empty() && curr[i].second.empty()) {
                curr.erase(i);
            }
        }
        else {
            rem.push_back(i);
        }
    }

    vector<ll> ns, s;
    for (auto i : curr) {
        for (auto j : i.second.first) {
            ns.push_back(j);
        }
        for (auto j : i.second.second) {
            s.push_back(j);
        }
    }

    int otherRes = 0;

    for (auto i : rem) {
        if (!ns.empty()) {
            ++otherRes;
            swapped[ns.back()] = false;
            next[i].second.push_back(ns.back());
            ns.pop_back();
        }
        else {
            ++res;
            next[i].second.push_back(s.back());
            s.pop_back();
        }
    }

    curr = next;

    return res;
}

int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";

        ll n, m;
        cin >> n >> m;
        vector<ll> s(m);
        for (int i = 0; i < m; ++i) {
            cin >> s[i];
        }
        vector<vector<ll>> p(n, vector<ll>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> p[i][j];
            }
        }

        unordered_map<ll, pair<vector<int>, vector<int>>> curr;
        vector<bool> swapped(m, false);
        for (int i = 0; i < s.size(); ++i) {
            curr[s[i]].first.push_back(i);
        }

        ll res = 0;
        for (int i = 0; i < n; ++i) {
            res += swaps(curr, swapped, p[i]);
        }

        cout << res << endl;

    }
}