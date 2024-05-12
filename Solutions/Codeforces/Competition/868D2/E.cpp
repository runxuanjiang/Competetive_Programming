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

ll dfs(ll node, ll parent, const vector<vector<ll>> &g, vector<bool> &seen) {
    seen[node] = true;
    for (auto child : g[node]) {
        if (child != parent && !seen[child]) {
            return 1 + dfs(child, node, g, seen);
        }
    }
    return 1;
}

int main() {
    fast;
    ll n, l, r;
    cin >> n >> l >> r;

    vector<vector<ll>> g(n);

    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    vector<ll> lengths;
    vector<bool> seen(n);

    for (int i = 0; i < n; ++i) {
        if (!seen[i] && !g[i].empty()) {
            lengths.push_back(dfs(i, g[i].front(), g, seen));
        }
    }

    ll tot = 0;
    for (auto i : lengths) {
        if (i < l+r) {
            tot ^= (i / l);
        }
    }

    if (tot == 0) {
        cout << "Bob" << endl;
    }
    else {
        cout << "Alice" << endl;
    }


}