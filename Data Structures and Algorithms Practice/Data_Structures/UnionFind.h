#include <vector>
#include <iostream>

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