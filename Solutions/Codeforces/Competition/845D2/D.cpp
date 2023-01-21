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

void dfs(int parent, int node, vector<unordered_set<ll>> &graph, vector<unordered_set<ll>> &children) {
    for (auto i : graph[node]) {
        if (i != parent) {
            children[node].insert(i);
            dfs(node, i, graph, children);
        }
    }
}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<unordered_set<ll>> graph(n);
        vector<unordered_set<ll>> children(n);
        for (int i = 0; i+1 < n; ++i) {
            ll u, v;
            cin >> u >> v;
            graph[u-1].insert(v-1);
            graph[v-1].insert(u-1);
        }

        dfs(-1, 0, graph, children);


        ll res = n;
        ll curr = n;


        vector<bool> seen(n, false);
        vector<ll> leaves;
        for (int i = 0; i < n; ++i) {
            if (children[i].empty()) {
                leaves.push_back(i);
                seen[i] = true;
            }
        }

        while (!leaves.empty()) {
            curr -= leaves.size();
            res += curr;
            vector<ll> next;
            for (auto i : leaves) {
                for (auto child : graph[i]) {
                    if (!seen[child]) {
                        graph[child].erase(i);

                        if (child == 0 && graph[child].empty()) {
                            next.push_back(0);
                            seen[0] = true;
                        }
                        if (child != 0 && graph[child].size() == 1) {
                            next.push_back(child);
                            seen[child] = true;
                        }
                    }
                }
            }

            leaves = next;

        }

        for (int i = 1; i+1 <= n; ++i) {
            res = (res * 2) % MOD;
        }
        cout << res << endl;



    }
}