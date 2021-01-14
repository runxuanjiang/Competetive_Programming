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
    int n, m;
    cin >> n >> m;

    DisjointSet ds(n);

    for (int i = 0; i < m; ++i) {
        int size;
        cin >> size;
        vector<int> nodes(size);
        for (int j = 0; j < size; ++j) {
            cin >> nodes[j];
            nodes[j] -=1;
        }

        for (int j = 0; j+1 < nodes.size(); ++j) {
            int a = ds.find(nodes[j]);
            int b = ds.find(nodes[j+1]);
            ds.unite(a, b);
        }
    }

    vector<int> counts(n, 0);
    for (int i = 0; i < n; ++i) {
        int a = ds.find(i);
        counts[a]++;
    }

    for (int i = 0; i < n; ++i) {
        int a = ds.find(i);
        cout << counts[a] << " ";
    }

}