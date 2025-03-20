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
        vector<ll> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        ll res = c[0];
        for (auto i : c) {
            res = max(res, i);
        }

        ll emax = -1, omax = -1;
        for (int i = 0; i < n; i += 2) {
            if (c[i] >= 0) {
                if (emax == -1) {
                    emax = c[i];
                }
                else {
                    emax += c[i];
                }
            }
        }

        for (int i = 1; i < n; i += 2) {
            if (c[i] >= 0) {
                if (omax == -1) {
                    omax = c[i];
                }
                else {
                    omax += c[i];
                }
            }
        }

        if (emax > 0) {
            res = max(res, emax);
        }
        if (omax > 0) {
            res = max(res, omax);
        }

        cout << res << endl;


    }
}