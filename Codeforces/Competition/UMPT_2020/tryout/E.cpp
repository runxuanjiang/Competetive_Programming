//Competition #:
//Problem #: E
//Accepted: NO

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

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

int XC[] = {0, 1, 0, -1};
int YC[] = {1, 0, -1, 0};

unordered_map<pair<int, int>, unordered_set<int>, hash_pair> qs;

void dfs(vector<string> &grid, vector<vector<bool>> &vis, int x, int y, int edgecount, vector<pair<int, int>> &edges, unordered_map<pair<int, int>, bool, hash_pair> &hash) {
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + XC[i];
        int ny = y + YC[i];
        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
            if (grid[nx][ny] == '?' && hash.find({nx, ny}) == hash.end()) {
                qs[{x, y}].insert()
                hash[{nx, ny}] = true;
            }
            else {
                if (!vis[nx][ny]) {
                    dfs(grid, vis, nx, ny, edgecount, edges, hash);
                }
            }
        }
    }
}

int main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int nodes0 = 0, nodes1 = 0;
    vector<pair<int, int>> edges0;
    vector<pair<int, int>> edges1;

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int count = 1;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '?') {
                qs[{i, j}] = count;
                ++count;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j]) {
                if (grid[i][j]) {
                    ++nodes1;
                    unordered_map<pair<int, int>, bool, hash_pair> hash;
                    dfs(grid, vis, i, j, nodes1, edges1, hash);
                }
                else {
                    ++nodes0;
                    unordered_map<pair<int, int>, bool, hash_pair> hash;
                    dfs(grid, vis, i, j, nodes0, edges0, hash);
                }
            
            }
        }
    }

    DisjointSet zeros(nodes0);
    DisjointSet ones(nodes1);

    int res = nodes0 + nodes1;
    for (auto i : edges0) {
        int n1 = zeros.find()
    }
}