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

ll traverse(int node, const vector<vector<int>> &graph, const vector<ll> &gold, vector<bool> seen) {
    seen[node] = true;
    ll res = gold[node];
    ll lowerRes = 0;
    for (auto child : graph[node]) {
        if (!seen[child]) {
            lowerRes = max(lowerRes, traverse(child, graph, gold, seen));
        }

    }
    return res + lowerRes;
}

int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";
        int n;
        cin >> n;
        vector<ll> gold(n);
        for (int i = 0; i < n; ++i) {
            cin >> gold[i];
        }
        vector<vector<int>> graph(n);
        for (int i = 0; i+1 < n; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }


        int res = 0;
        if (graph[0].size() <= 1) {
            vector<bool> seen(n, false);
            res = traverse(0, graph, gold, seen);
        }
        else {
            vector<ll> tempres;
            for (auto child : graph[0]) {
                vector<bool> seen(n, false);
                seen[0] = true;
                tempres.push_back(traverse(child, graph, gold, seen));
            }

            sort(tempres.begin(), tempres.end());
            res = gold[0] + tempres.back() + tempres[tempres.size() - 2];
        }

        cout << res << endl;
    }
}