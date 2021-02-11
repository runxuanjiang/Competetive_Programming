//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

struct comp{
    bool operator() (pair<ll, pair<ll, ll>> l, pair<ll, pair<ll, ll>> r) {
        return l.first < r.first;
    }
};

class DisjointSet{
    struct Node{
        size_t parent;
        int rank = 0;
    };

    std::vector<Node> nodes;

public:
    DisjointSet(size_t size) {
        std::vector<Node> tempNodes(size);
        for (int i = 0; i < size; ++i) {
            tempNodes[i].parent = i;
        }
        nodes = tempNodes;
    }

    size_t find(size_t node) {
        if (nodes[node].parent == node) return node;
        return nodes[node].parent = find(nodes[node].parent);
    }

    void unite(size_t node1, size_t node2) {
        size_t a = find(node1);
        size_t b = find(node2);

        if (a != b) {
            if (nodes[a].rank == nodes[b].rank) {
                nodes[a].parent = b;
                nodes[b].rank++;
            }
            else if (nodes[a].rank < nodes[b].rank) {
                nodes[a].parent = b;
            }
            else {
                nodes[b].parent = a;
            }
        }
    }
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<pair<ll, pair<ll, ll>>> edges;
    for (int i = 0; i < m; ++i) {
        ll a, b, cost;
        cin >> a >> b >> cost;
        --a; --b;
        edges.push_back({cost, {a, b}});
    }


    int minedge = min_element(v.begin(), v.end()) - v.begin();

    for (int i = 0; i < n; ++i) {
        if (i != minedge) {
            edges.push_back({v[i] + v[minedge], {i, minedge}});
        }
    }

    sort(edges.begin(), edges.end());

    DisjointSet ds(n);
    ll cost = 0;

    for (auto edge : edges) {
        int a = ds.find(edge.second.first);
        int b = ds.find(edge.second.second);

        if (a != b) {
            ds.unite(a, b);
            cost += edge.first;
        }

    }

    cout << cost;



}