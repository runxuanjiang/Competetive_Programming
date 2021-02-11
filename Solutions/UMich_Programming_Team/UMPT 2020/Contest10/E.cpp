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

class DisjointSet{
    struct Node{
        size_t parent;
        int rank = 0;
    };

    std::vector<Node> nodes;

public:
    DisjointSet(size_t size=0) {
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
    fast;
    int n, m;
    cin >> n >> m;

    unordered_map<int, DisjointSet> um;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        if (um.find(c) == um.end()) {
            DisjointSet ds(n);
            um.emplace(c, ds);
        }

        um[c].unite(a, b);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        int res = 0;
        for (auto i : um) {
            if (i.second.find(u) == i.second.find(v)) {
                ++res;
            }
        }
        cout << res << endl;
    }

}