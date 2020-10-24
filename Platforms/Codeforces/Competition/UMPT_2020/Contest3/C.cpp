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

void recurse(int node, vector<unordered_set<int>> &edges, unordered_set<int> &seen, bool &valid) {
    if (edges[node].size() != 2) valid = false;

    for (auto n : edges[node]) {
        if (seen.find(n) == seen.end()) {
            seen.insert(n);
            recurse(n, edges, seen, valid);
        }
    }
}

int main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> edges(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a -=1; b-=1;

        edges[a].insert(b);
        edges[b].insert(a);
    }

    int res = 0;
    unordered_set<int> seen;
    for (int i = 0; i < n; ++i) {
        if (seen.find(i) == seen.end()) {
            bool valid = true;
            seen.insert(i);
            recurse(i, edges, seen, valid);
            if (valid) ++res;
        }
    }
    cout << res;
}