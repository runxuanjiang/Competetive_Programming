//Competition #:
//Problem #: I
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
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a-1].insert(b-1);
        graph[b-1].insert(a-1);
    }

    ll res = 0;

    for (int i = 0; i < n; ++i) {
        if (graph[i].size() >= 4) {
            ll h = ((ll) graph[i].size() - 1);
            ll htot = (h) * (h-1) * (h-2) / 6;
            for (auto child : graph[i]) {
                ll stot = (ll) graph[child].size() - 1;
                res += htot * stot;
            }

            for (auto c1 : graph[i]) {
                for (auto c2 : graph[i]) {
                    if (c1 != c2 && graph[c1].find(c2) != graph[c1].end()) {
                        res -=  ((h-1) * (h-2))/2;
                    }
                }
            }
        }

    }

    cout << res << endl;
}