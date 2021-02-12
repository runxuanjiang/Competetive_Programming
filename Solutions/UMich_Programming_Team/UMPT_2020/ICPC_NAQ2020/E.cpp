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

void dfs(vector<deque<pair<ll, ll>>> &graph, ll idx, ll prevnode) {
    sort(graph[idx].begin(), graph[idx].end());
}


void traverse(vector<deque<pair<ll, ll>>> &graph, ll idx) {
    sort(graph[idx].begin(), graph[idx].end());
    pair<ll, ll> &node1 = graph[idx][0];
    --node1.first;
    dfs(graph, node1.second, idx);

    if (graph[idx].size() > 1) {
        pair<ll, ll> &node2 = graph[idx][1];
        --node2.first;
        dfs(graph, node2.second, idx);
    }

    graph[idx].pop_front();
    if (!graph[idx].empty()) {
        graph[idx].pop_front();
    }

}

int main() {
    fast;
    ll n;
    cin >> n;
    vector<deque<pair<ll, ll>>> graph(n);
    for (int i = 0; i < n-1; ++i) {
        ll u, v, p;
        cin >> u >> v >> p;
        graph[u].push_back({p, v});
        graph[v].push_back({p, u});
    }

    int res = 0;

    for (int i = 0; i < n; ++i) {
        while (!graph[i].empty()) {
            ++res;
            traverse(graph, i);
        }
    }

    
}