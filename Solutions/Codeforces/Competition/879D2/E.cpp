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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll &i : a) {
            cin >> i;
        }

        set<ll> lcms;

        set<ll> prevLcms;
        set<ll> nextLcms;
        for (auto i : a) {
            if (i <= n*n+1) {
                nextLcms.insert(i);
            }
            for (auto j : prevLcms) {
                if (lcm(i, j) <= n*n+1) {
                    nextLcms.insert(lcm(i, j));
                }
            }
            for (auto j : nextLcms) {
                // cerr << j << " ";
                lcms.insert(j);
            }
            // cerr << endl;
            prevLcms = nextLcms;
            nextLcms.clear();
        }


        ll prev = 0;
        ll res = 0;
        for (auto i : lcms) {
            if (i != prev+1) {
                res = prev+1;
                break;
            }
            prev = i;
        }
        if (!res) {
            res = prev+1;
        }
        cout << res << endl;



    }
}