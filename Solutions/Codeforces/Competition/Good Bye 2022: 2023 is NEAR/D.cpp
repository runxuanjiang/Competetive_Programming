//Competition #:
//Problem #: D
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 998244353;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        vector<bool> seen(n, 0);
        ll res = 1;
        
        vector<unordered_multiset<int>> graph(n);
        for (int i = 0; i < n; ++i) {
            graph[a[i] - 1].insert(b[i] - 1);
            graph[b[i] - 1].insert(a[i] - 1);
        }

        vector<int> curr, next;
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1 && *(graph[i].begin()) != i) {
                curr.push_back(i);
            }
        }


        while (!curr.empty()) {
            for (auto i : curr) {
                seen[i] = true;
                if (!graph[i].size()) {
                    res = 0;
                    next = {};
                    break;
                }
                int parent = *(graph[i].begin());

                graph[parent].erase(graph[parent].find(i));
                if (graph[parent].size() == 1 && *(graph[parent].begin()) != parent) {
                    next.push_back(parent);
                }
            }

            swap(next, curr);
            next = {};
        }

        for (int i = 0; i < n; ++i) {
            if (!seen[i] && !graph[i].size()) {
                res = 0;
            }
        }

        if (res) {
            for (int i = 0; i < n; ++i) {
                if (!seen[i]) {
                    int nodes = 1;
                    seen[i] = true;
                    int j = i;
                    while (*(graph[j].begin()) != i) {
                        int pnode = j;
                        ++nodes;
                        j = *(graph[j].begin());
                        seen[j] = true;
                        graph[j].erase(graph[j].find(pnode));
                    }

                    if (nodes == 1) {
                        res = (res * n) % MOD;
                    }
                    else {
                        res = (res * 2) % MOD;
                    }
                    
                }
            }
        }

        cout << res << endl;
    }

    
}