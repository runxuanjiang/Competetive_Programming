#include <bits/stdc++.h>

using namespace std;

struct Node{
    int parent;
    vector<int> children;
    bool covid;
};


void solve(vector<Node> &tree, int node, int &bmax, int &cmax, vector<pair<int, int>> &sol) {
    queue<int> bfs;
    if (tree[node].covid) {
        bfs.push(node);
        while (!bfs.empty()) {
            for (int child : tree[bfs.front()].children) {
                if (tree[child].covid) {
                    bfs.push(child);
                }
                else {
                    solve(tree, child, bmax, cmax, sol);
                }
            }
        }
    }
    else {
        int count = 1;
        vector<int> covids;
        bfs.push(node);
        while (!bfs.empty()) {
            for (int child : tree[bfs.front()].children) {
                if (!tree[child].covid) {
                    bfs.push(child);
                    ++count;
                }
                else {
                    covids.push_back(child);
                }
            }
        }
        if (bmax + count > cmax) {
            sol.clear();
            cmax = bmax + count;
            sol.push_back(make_pair(bmax, count));
        }
        bmax = max(bmax, count);
        for (int covidnode : covids) {
            solve(tree, covidnode, bmax, cmax, sol);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; ++x) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> E(k);
        for (int i = 0; i < k; ++i) {
            cin >> E[i];
        }
        int A, B, C;
        cin >> A >> B >> C;

        int curre = -1, prev1e = -1, prev2e = -1;

        vector<Node> tree(n);
        tree[0].covid = (s[0] == '#');
        for (int i = 0; i < n-1; ++i) {
            prev2e = prev1e;
            prev1e = curre;
            if (i < k) {
                curre = E[i];
            }
            else {
                curre = ((((A*prev2e + B*prev1e + C) % (i+1)) + (i+1)) % (i+1)) + 1;
            }
            tree[i+1].parent = curre;
            tree[curre - 1].children.push_back(i+1);
            tree[i+1].covid = (s[i+1] == '#');
        }
        vector<pair<int, int> > solution;
        int bmax = 0, cmax = 0;
        solve(tree, 0, bmax, cmax, solution);
        long long plans;
        for (pair<int, int> p : solution) {
            plans += (long long) p.first * (long long) p.second;
        }
        cout << "Case #" << x+1 << ": " << cmax << " " << plans << endl;

        
        
    }
}