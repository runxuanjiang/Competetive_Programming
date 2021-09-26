//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)
int testnum = 0;

int recurse(int node, const vector<vector<int>> &graph, const vector<int> &f, vector<bool> &seen, unordered_multiset<int> &prev, unordered_multiset<int> &next, unordered_set<int> &dupes) {
    seen[node] = true;

    int res = 0;
    for (auto child : graph[node]) {
        if (!seen[child]) {
            prev.insert(f[child]);
            next.erase(next.find(f[child]));
            if (next.find(f[child]) != next.end()) {
                dupes.insert(f[child]);
            }
            else {
                dupes.erase(f[child]);
            }
            if (dupes.empty()) {
                ++res;
                cout << node << " " << child << endl;
            }

            res += recurse(child, graph, f, seen, prev, next, dupes);

            next.insert(f[child]);
            prev.erase(prev.find(f[child]));
            if (prev.find(f[child]) != prev.end()) {
                dupes.insert(f[child]);
            }
            else {
                dupes.erase(f[child]);
            }
        }
    }

    return res;
}

int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";

        ll n;
        cin >> n;
        vector<vector<int>> graph(n);
        for (int i = 0; i < n-1; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        vector<int> f(n);
        unordered_multiset<int> prev, next;
        for (int i = 0; i < n; ++i) {
            cin >> f[i];
            next.insert(f[i]);
        }

        // find a leaf node
        int node;
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) {
                node = i;
                break;
            }
        }

        vector<bool> seen(n, false);
        unordered_set<int> dupes;
        prev.insert(f[node]);
        next.erase(next.find(f[node]));
        if (next.find(f[node]) != next.end()) {
            dupes.insert(f[node]);
        }

        int res = recurse(node, graph, f, seen, prev, next, dupes);
        cout << res << endl;
    }
}