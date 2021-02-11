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
    fast;
    int n;
    int count = 1;
    while (cin >> n) {
        if (n == 0) return 0;

        int e;
        cin >> e;
        vector<unordered_set<ll>> edges(n);
        DisjointSet ds(n);
        int resolution = 0;

        for (int i = 0; i < e; ++i) {
            int a, b;
            cin >> a >> b;
            a-=1; b-=1;
            edges[a].insert(b);
            edges[b].insert(a);

            int c = ds.find(a);
            int d = ds.find(b);
            if (c == d) resolution = -1;
            ds.unite(c, d);
        }
        int king = ds.find(0);
        vector<int> cnodes;

        if (resolution == -1) {
            goto resolve;
        }

        for (int i = 0; i < n; ++i) {
            if (ds.find(i) != king) {
                resolution = -1;
                goto resolve;
            }
            if (edges[i].size() > 1) {
                cnodes.push_back(i);
            }
        }

        for (auto node : cnodes) {
            int count = 0;
            for (auto othernode : cnodes) {
                if (edges[node].find(othernode) != edges[node].end()) {
                    ++count;
                }

                if (count > 2) {
                    resolution = -1;
                    goto resolve;
                }
            }
        }

        resolve: if (resolution == -1) {
            cout << "Graph " << count << " is not a caterpillar." << endl;
        }
        else {
            cout << "Graph " << count << " is a caterpillar." << endl;
        }

        ++count;


    }
}