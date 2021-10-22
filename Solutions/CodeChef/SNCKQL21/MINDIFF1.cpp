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

int main() {
    fast;
    tests {
        int n, m;
        cin >> n >> m;
        vector<unordered_set<int>> graph(n);
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a-1].insert(b-1);
            graph[b-1].insert(a-1);
        }

        set<pair<int, int>> pq; //{size, node id}
        for (int i = 0; i < graph.size(); ++i) {
            pq.insert({graph[i].size(), i});
        }

        int curr = graph.size();
        int resnum = 0;
        vector<int> res(n);
        vector<bool> seen(n, false);
        while (!pq.empty()) {
            resnum = max(resnum, pq.begin()->first);
            int i = pq.begin()->second;
            pq.erase(pq.begin());
            seen[i] = true;
            res[i] = curr;
            --curr;

            for (auto child : graph[i]) {
                if (!seen[child]) {
                    pq.erase(pq.find({graph[child].size(), child}));
                    graph[child].erase(i);
                    pq.insert({graph[child].size(), child});
                }
            }
        }

        cout << resnum << endl;
        for (auto i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
}