#include <vector>
#include <iostream>

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

#include <cassert>

using namespace std;

bool graphContainsCycle(vector<pair<int, int>> &edges, int nodes) {
    DisjointSet ds(nodes);

    for (auto edge : edges) {
        int a = ds.find(edge.first);
        int b = ds.find(edge.second);

        if (a == b) return true;
        ds.unite(a, b);
    }

    return false;
}

int main() {
    vector<pair<int, int>> test1 = {{0, 2}, {2, 4}, {0, 3}, {4, 8}, {3, 7}, {7, 0}};
    vector<pair<int, int>> test2 = {{1, 3}, {0, 2}, {0, 1}};
    vector<pair<int, int>> test3 = {{1, 4}, {0, 4}, {1, 2}, {2, 3}, {3, 4}};

    assert(graphContainsCycle(test1, 9));
    assert(!graphContainsCycle(test2, 4));
    assert(graphContainsCycle(test3, 5));
    cout << "Tests Passed" << endl;
}