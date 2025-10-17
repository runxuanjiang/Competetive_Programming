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

int main() {
    fast;
    tests {
        ll n, m, k;
        cin >> n >> m >> k;

        vector<ll> h(n);
        for (auto &i : h) cin >> i;

        vector<vector<ll>> g(n);
        vector<unordered_set<ll>> invg(n);
        vector<ll> change_index(n, k);
        vector<ll> time(n);
        vector<ll> starting_points;
        for (int i = 0; i < m; ++i) {
            ll a, b;
            cin >> a >> b;

            g[a-1].push_back(b-1);
            invg[b-1].insert(a-1);
        }

        vector<unordered_set<ll>> invg2(invg.begin(), invg.end());


        set<pair<ll, ll>> q;
        for (int i = 0; i < n; ++i) {
            if (invg[i].empty()) {
                q.insert({h[i], i});
                time[i] = h[i];
                change_index[i] = h[i] + 1;
                starting_points.push_back(h[i]);
            }
        }

        ll ctime = 0;
        while (!q.empty()) {
            auto curr = *(q.begin());
            q.erase(q.begin());

            ctime = curr.first;

            for (auto child : g[curr.second]) {
                invg[child].erase(curr.second);
                ll base = (ctime / k) * k;

                if (invg[child].empty()) {
                    
                    if (h[child] + base < ctime) {
                        q.insert({h[child] + base + k, child});
                        time[child]  = h[child] + base + k;
                    }
                    else {
                        q.insert({h[child] + base, child});
                        time[child] = h[child] + base;
                    }

                    for (auto parent : invg2[child]) {
                        if (time[parent] + k > time[child]) {
                            change_index[child] = min(change_index[child], change_index[parent]);
                        }

                    }


                }
            }
        }

        multimap<ll, ll> change_index_sorted;
        for (int i = 0; i < n; ++i) {
            change_index_sorted.insert({change_index[i], i});
        }

        sort(starting_points.begin(), starting_points.end());
        ll res = *max_element(time.begin(), time.end());
        ll max_end_time = *max_element(time.begin(), time.end());

        // for (int i = 0; i < n; ++i) {
        //     cerr << "time for " << i << " is " << time[i] << " change index " << change_index[i] << endl;
        // }
        // cerr << "res is " << res << endl;

        for (auto i : starting_points) {
            // cerr << "considering starting point " << i << endl;
            while (!change_index_sorted.empty() && change_index_sorted.begin()->first <= i) {
                max_end_time = max(max_end_time, time[change_index_sorted.begin()->second] + k);
                // cerr << "updating max end time to " << max_end_time << " from node " << change_index_sorted.begin()->second << endl;
                change_index_sorted.erase(change_index_sorted.begin());
            }

            res = min(res, max_end_time - i);
            // cerr << "res is " << res << endl;
        }

        cout << res << endl;

    }
}