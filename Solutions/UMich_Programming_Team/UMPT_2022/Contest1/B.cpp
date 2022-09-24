//Competition #:
//Problem #: B
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
    ll n, m;
    cin >> n >> m;
    vector<ll> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<ll> parent(n, -1);
    unordered_set<ll> ncc;

    for (int i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;

        parent[y-1] = x-1;
        ncc.insert(x-1);
    }

    ll res = 10000000000;


    for (int i = 0; i < n; ++i) {
        if (ncc.find(i) == ncc.end()) {
            unordered_set<ll> seen;
            int curr = i;
            ll cres = 0;
            while (parent[curr] != -1) {
                cres += p[curr];
                seen.insert(curr);
                curr = parent[curr];
            }
            cres += p[curr];
            seen.insert(curr);

            for (int j = 0; j < n; ++j) {
                if (ncc.find(j) == ncc.end() && j != i) {
                    int jcurr = j;
                    ll jcres = 0;
                    while (parent[jcurr] != -1 && seen.find(jcurr) == seen.end()) {
                        jcres += p[jcurr];
                        jcurr = parent[jcurr];
                    }

                    if (seen.find(jcurr) == seen.end()) {
                        jcres += p[jcurr];
                    }

                    res = min(res, cres + jcres);

                }
            }

        }
    }


    cout << res << endl;
}