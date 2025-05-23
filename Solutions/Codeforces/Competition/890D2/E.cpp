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

ll recurse1(ll i, ll parent, const vector<vector<ll>> &g, vector<ll> &subgraph_size) {
    ll res = 1;
    for (auto child : g[i]) {
        if (child != parent) {
            res += recurse1(child, i, g, subgraph_size);
        }
    }

    subgraph_size[i] = res;
    return res;
}

ll recurse(ll i, ll parent, const vector<vector<ll>> &g, const vector<ll> &subgraph_size) {
    ll res = 0;
    bitset<5001> knapsack;
    knapsack[0] = 1;
    for (auto child : g[i]) {
        if (child != parent) {
            res += recurse(child, i, g, subgraph_size);
            knapsack |= (knapsack << subgraph_size[child]);
        }
    }

    ll current_node_res = 0;
    for (int j = 0; j < subgraph_size[i]; ++j) {
        if (knapsack[j]) {
            ll side1 = j;
            ll side2 = subgraph_size[i] - 1 - j;
            current_node_res = max(current_node_res, side1*side2);
        }

    }

    // cerr << "answer for node " << i << " is " << current_node_res + res << endl;
    return res + current_node_res;
}

int main() {
    fast;
    ll n;
    cin >> n;

    vector<vector<ll>> g(n);
    for (int i = 1; i < n; ++i) {
        ll j;
        cin >> j;
        --j;
        g[i].push_back(j);
        g[j].push_back(i);
    }

    vector<ll> subgraph_size(n, 0);
    recurse1(0, -1, g, subgraph_size);

    // for (int i = 0; i < n; ++i) {
    //     cerr << "subgraph_size[" << i << "] = " << subgraph_size[i] << endl;
    // }

    cout << recurse(0, -1, g, subgraph_size) << endl;
}