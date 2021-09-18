//Competition #:
//Problem #: C
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

        vector<unordered_set<int>> parents(n);
        vector<unordered_set<int>> children(n);

        for (int i = 0; i < n; ++i) {
            ll edges;
            cin >> edges;
            for (int j = 0; j < edges; ++j) {
                ll parent;
                cin >> parent;
                parents[i].insert(parent-1);
                children[parent-1].insert(i);

            }
        }

        unordered_set<int> seen;
        queue<int> prev, next;
        for (int i = 0; i < parents.size(); ++i) {
            if (parents[i].empty()) {
                prev.push(i);
            }
        }

        int res = 0;

        while (!prev.empty()) {
            ++res;
            while (!prev.empty()) {
                int node = prev.front();
                prev.pop();

                seen.insert(node);

                for (auto child : children[node]) {
                    parents[child].erase(node);
                    if (parents[child].empty()) {
                        if (child > node) {
                            prev.push(child);
                        }
                        else {
                            next.push(child);
                        }
                    }

                }
            }

            swap(prev, next);
        }

        if (seen.size() == n) {
            cout << res << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}