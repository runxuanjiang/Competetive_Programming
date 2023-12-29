//Competition #:
//Problem #: F
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)
ll n, k, c;

ll recurse(ll node, ll parent, const vector<unordered_set<ll>> &g, ll &res, ll cost) {
    ll l1 = 0, l2 = 0;
    for (ll child : g[node]) {
        if (child != parent) {

            ll childmax = recurse(child, node, g, res, cost + c);
            if (childmax > l1) { 
                l2 = l1;
                l1 = childmax;
            } 
            else if (childmax > l2) {
                l2 = childmax;
            }
        }
    }

    res = max(res, (l1 + l2)*k - (cost + l2*c));

    if (node == 0) {
        res = max(res, l1*k);
    }
    return l1+1;
}

int main() {
    fast;
    tests {
        cin >> n >> k >> c;
        vector<unordered_set<ll>> g(n);
        for (int i = 1; i < n; ++i) {
            ll x, y;
            cin >> x >> y;
            g[x-1].insert(y-1);
            g[y-1].insert(x-1);
        }

        ll res = 0;
        ll cost = 0;
        recurse(0, -1, g, res, cost);

        cout << res << endl;



    }
}