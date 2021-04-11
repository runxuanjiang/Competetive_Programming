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
        ll n, p;
        cin >> n >> p;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<pair<ll, pair<int, int>>> edges;
        for (int i = 0; i < n; ++i) {
            ll m = a[i], cgcd = a[i];
            for (int j = i+1; j < n; ++j) {
                m = min(m, a[j]);
                cgcd = gcd(cgcd, a[j]);
                if (i+1 == j && (p < m || m != cgcd)) {
                    edges.push_back({p, {i, j}});
                }
                else if (m == cgcd) {
                    edges.push_back({m, {i, j}});
                }
            }
        }

        sort(edges.begin(), edges.end());

        DisjointSet ds(n);
        ll res = 0;
        int numEdges = 0;
        for (auto i : edges) {
            int a = ds.find(i.second.first);
            int b = ds.find(i.second.second);
            if (a != b) {
                ds.unite(a, b);
                ++numEdges;
                res += i.first;
            }
            if (numEdges == n-1) break;
        }
        cout << res << endl;
    }
}