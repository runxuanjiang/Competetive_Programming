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
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        unordered_map<ll, ll> ac, bc;
        
        ll count = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ++count;
            }
            else {
                if (a[i] == a[i-1]) {
                    ++count;
                }
                else {
                    count = 1;
                }

            }
            if (ac.find(a[i]) == ac.end()) {
                ac[a[i]] = 0;
            }
            ac[a[i]] = max(ac[a[i]], count);
        }

        count = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ++count;
            }
            else {
                if (b[i] == b[i-1]) {
                    ++count;
                }
                else {
                    count = 1;
                }

            }
            if (bc.find(b[i]) == bc.end()) {
                bc[b[i]] = 0;
            }
            bc[b[i]] = max(bc[b[i]], count);
        }

        ll res = 0;
        for (auto i : ac) {
            if (bc.find(i.first) != bc.end()) {
                res = max(res, i.second + bc[i.first]);
            }
            else {
                res = max(res, i.second);
            }
        }

        for (auto i : bc) {
            if (ac.find(i.first) != ac.end()) {
                res = max(res, i.second + ac[i.first]);
            }
            else {
                res = max(res, i.second);
            }
        }

        cout << res << endl;
    }
}