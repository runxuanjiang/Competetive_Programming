#include <bits/stdc++.h>

using namespace std;

long long MOD = 1000000007;
struct Node{
    vector<int> children;
    long long count = -1;
};

void populate(vector<Node> &tree, unordered_map<int, vector<int>> &hash, unordered_set<int> &visited, int node) {
    if (visited.find(node) != visited.end()) return;

    for (auto i : hash[node]) {
        if (visited.find(i) == visited.end()) {
            tree[node].children.push_back(i);
        }
    }
    visited.insert(node);
    for (auto i : tree[node].children) {
        populate(tree, hash, visited, i);
    }
}

long long count(vector<Node> &tree, priority_queue<long long> &pqe, int node) {
    if (tree[node].count != -1) return tree[node].count;
    if (tree[node].children.empty()) {
        tree[node].count = 1;
    }
    else {
        long long cnt = 0;
        for (auto i : tree[node].children) {
            long long add = count(tree, pqe, i);
            pqe.push(add * ((long long) tree.size() - add));
            cnt += add;
        }
        tree[node].count = cnt + 1;
    }
    return tree[node].count;
}

int main() {
    int t;
    cin >> t;
    for (int x = 0; x < t; ++x) {
        int n;
        cin >> n;
        vector<Node> tree(n);
        unordered_map<int, vector<int> > hash;
        unordered_set<int> visited;
        for (int i = 0; i < n-1; ++i) {
            int e1, e2;
            cin >> e1 >> e2;
            hash[e1-1].push_back(e2-1);
            hash[e2-1].push_back(e1-1);
        }
        populate(tree, hash, visited, 0);
        int f;
        cin >> f;
        priority_queue<long long> pqf;
        for (int i = 0; i < f; ++i) {
            long long add;
            cin >> add;
            pqf.push(add);
        }
        priority_queue<long long> pqe;
        count(tree, pqe, 0);

        long long ans = 0;
        while(!pqe.empty()) {
            if (!pqf.empty()) {
                long long multiplier = 1;
                while (pqf.size() > pqe.size()) {
                    multiplier = (multiplier * pqf.top()) % MOD;
                    pqf.pop();
                }
                multiplier = (multiplier * pqf.top()) % MOD;
                pqf.pop();
                ans += (((pqe.top() % MOD) * (multiplier % MOD)) % MOD);
            }
            else {
                ans += (pqe.top() % MOD);
            }
            pqe.pop();
            ans = ans % MOD;
        }
        cout << ans << endl;
    }
}