#include "UnionFind.h"
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
}