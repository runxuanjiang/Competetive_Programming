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


ll bfs(ll node, ll parent, ll index, const vector<vector<pair<ll, ll>>> &g) {
    ll res = 0;
    for (auto child : g[node]) {
        if (child.first != parent) {
            ll cost = bfs(child.first, node, child.second, g);
            if (child.second < index) {
                ++cost;
            }
            res = max(res, cost);
        }
    }
    return res;
}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;

        vector<vector<pair<ll, ll>>> g(n);
        for (int i = 1; i < n; ++i) {
            ll a, b;
            cin >> a >> b;
            g[a-1].push_back({b-1, i});
            g[b-1].push_back({a-1, i});
        }

        ll res = bfs(0, -1, 0, g);
        cout << res+1 << endl;
    }
}