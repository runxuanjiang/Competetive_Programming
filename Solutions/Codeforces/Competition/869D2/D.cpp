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

string validate(ll start, const vector<ll> &path, const vector<vector<ll>> &g) {
    stringstream ss;
    unordered_set<ll> c(g[start].begin(), g[start].end());
    ll first = -1, last = -1;
    for (auto i : path) {
        if (c.find(i) != c.end()) {
            c.erase(i);
            if (first == -1) {
                first = i;
            }
            else {
                last = i;
                break;
            }
        }
    }

    while (c.size() > 2) {
        c.erase(c.begin());
    }

    for (auto i : c) {
        ss << start+1 << " " << i+1 << endl;
    }

    ll prev = -1;
    for (auto i : path) {
        if (prev != -1) {
            ss << prev+1 << " " << i+1 << endl;
        }

        prev = i;
        if (i == last) {
            break;
        }
    }

    ss << prev+1 << " " << start+1 << endl;
    return ss.str();

}


void dfs(ll node, ll prev, ll start, vector<bool> &seen, vector<ll> &path, const vector<vector<ll>> &g, string &res) {
    path.push_back(node);
    seen[node] = true;

    for (ll child : g[node]) {
        if (child != prev) {
            if (child == start) {
                res = validate(start, path, g);
            }
            else if (!seen[child]) {
                dfs(child, node, start, seen, path, g, res);
            }
        }
        if (!res.empty()) {
            return;
        }
    }
    path.pop_back();
}

int main() {
    fast;
    tests {
        ll n, m;
        cin >> n >> m;

        vector<vector<ll>> g(n);
        for (int i = 0; i < m; ++i) {
            ll x, y;
            cin >> x >> y;
            g[x-1].push_back(y-1);
            g[y-1].push_back(x-1);
        }

        string res;

        for (int i = 0; i < n; ++i) {
            if (g[i].size() >= 4) {
                vector<bool> seen(n, 0);
                vector<ll> path;
                dfs(i, -1, i, seen, path, g, res);
            }
            if (!res.empty()) {
                break;
            }
        }

        if (res.empty()) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << count(res.begin(), res.end(), '\n') << endl;
            cout << res;
        }

    }
}