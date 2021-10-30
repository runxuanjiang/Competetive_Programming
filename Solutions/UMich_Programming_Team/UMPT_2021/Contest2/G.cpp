//Competition #:
//Problem #: G
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

void dfs(int node, const vector<unordered_set<int>> &graph, vector<bool> &seen, unordered_map<int, unordered_set<int>> &seene, ll &edges, ll &nodes) {
    ++nodes;
    seen[node] = true;
    for (auto edge : graph[node]) {
        if (seene[node].find(edge) == seene[node].end()) {
            ++edges;
            seene[node].insert(edge);
            seene[edge].insert(node);
        }
    }

    for (auto edge : graph[node]) {
        if (!seen[edge]) {
            dfs(edge, graph, seen, seene, edges, nodes);
        }
    }
}

int main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x-1].insert(y-1);
        graph[y-1].insert(x-1);
    }

    vector<bool> seen(n, 0);
    unordered_map<int, unordered_set<int>> seene;

    ll res = 0;

    for (int i = 0; i < n; ++i) {
        if (!seen[i]) {
            ll edges = 0, nodes = 0;
            dfs(i, graph, seen, seene, edges, nodes);
            if (nodes > edges) {
                ++res;
            }
        }
    }

    cout << res << endl;


}