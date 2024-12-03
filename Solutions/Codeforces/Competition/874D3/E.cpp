//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

bool isLoop(ll node, ll parent, const vector<unordered_set<ll>> &g, vector<bool> &seen) {
    seen[node] = true;
    bool good = false;
    for (auto child : g[node]) {
        if (child != parent) {
            if (seen[child]) {
                return true;
            }
            if (isLoop(child, node, g, seen)) {
                good = true;
            }
        }
    }

    return good;
}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<unordered_set<ll>> g(n);
        for (int i = 0; i < n; ++i) {
            ll l = i;
            ll r = a[i]-1;

            g[l].insert(r);
            g[r].insert(l);
        }


        ll loop = 0, line = 0;
        vector<bool> seen(n, false);
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) {
                if (isLoop(i, -1, g, seen)) {
                    ++loop;
                }
                else {
                    ++line;
                }
            }
        }

        cout << loop + min(line, 1ll) << " " << loop + line << endl;


    }
}