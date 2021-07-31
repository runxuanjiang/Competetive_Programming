//Competition #:
//Problem #: D
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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<unordered_set<int>> graph(n+1);
        for (int i = 1; i <= n; ++i) {
            graph[a[i-1]].insert(i);
        }


        queue<int> empties;
        int ful = 0;
        for (int i = 1; i <= n; ++i) {
            if (graph[i].empty()) {
                empties.push(i);
            }
            else {
                ++ful;
            }
        }

        queue<int> bfs;
        for (int i = 1; i <= n; ++i) {
            if (!graph[i].empty() && graph[a[i-1]].size() > 1) {
                bfs.push(i);
            }
        }

        while (!bfs.empty()) {
            if (graph[a[bfs.front() - 1]].size() == 1) {
                bfs.pop();
                continue;
            }
            graph[empties.front()].insert(bfs.front());
            graph[a[bfs.front() - 1]].erase(bfs.front());
            if (graph[a[empties.front() - 1]].size() > 1) {
                bfs.push(empties.front());
            }
            empties.pop();
            bfs.pop();
        }


        // for (int i = 1; i <= n; ++i) {
        //     cout << i << ": ";
        //     for (auto j : graph[i]) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        cout << ful << endl;
        vector<int> res(n+1);
        for (int i = 1; i <= n; ++i) {
            res[ *(graph[i].begin()) ] = i;
        }
        for (int i = 1; i <= n; ++i) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}