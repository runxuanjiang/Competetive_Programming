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


int main() {
    fast;
    tests {
        // cerr << "tests remaining: " << testCount << endl;
        ll l, r;
        cin >> l >> r;

        ll res = 0;
        ll ub2 = r/2;
        if (ub2 >= l) {
            res += (ub2-l+1);
        }

        ll lb = 1, ub = 1;
        while (lb < l) {
            ll proj = (l % lb == 0) ? l/lb : (l/lb) + 1;
            ll nproj = proj+1;
            ll lub = r/nproj;
            if (lub >= lb) {
                res += (min(lub, ub) - lb + 1);
            }

            // cerr << "(lb, ub, proj, nproj, res): " << lb << " " << ub << " " << proj << " " << nproj << " " << res << endl;

            lb = ub+1;
            if (lb < l) {
                ll cproj = (l % lb == 0) ? l/lb : (l/lb) + 1;
                ll cnproj = cproj - 1;
                ub = (l % cnproj == 0) ? (l/cnproj)-1 : l/cnproj;
            }
        }

        cout << res << endl;
    }
}