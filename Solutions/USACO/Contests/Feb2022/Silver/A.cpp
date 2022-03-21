//Competition #:
//Problem #: A
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
        long long rank = 0;
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
    int n;
    cin >> n;
    vector<unordered_map<int, int>> pref(n);
    for (int i = 0; i < n; ++i) {
        bool done = false;
        for (int j = 0; j < n; ++j) {
            int in;
            cin >> in;
            if (done || in == i+1) {
                done = true;
            }
            else {
                pref[i][in-1] = j;
            }
        }
    }

    DisjointSet ds(n);


    for (int i = 0; i < n; ++i) {
        for (auto cow : pref[i]) {
            if (pref[cow.first].find(i) != pref[cow.first].end()) {
                int x = ds.find(i);
                int y = ds.find(cow.first);
                ds.unite(x, y);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        int bestval = i;
        int best = pref[i].size();
        for (int j = 0; j < n; ++j) {
            if (pref[i].find(j) != pref[i].end() && pref[i][j] < best && ds.find(j) == ds.find(i)) {
                bestval = j;
                best = pref[i][j];
            }
        }

        cout << bestval+1 << endl;
    }
}