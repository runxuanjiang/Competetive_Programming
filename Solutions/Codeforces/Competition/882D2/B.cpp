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

        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll res = 0;
        ll curr = -1;
        for (int i = 0; i < n; ++i) {
            if (curr == -1) {
                curr = a[i];
            }
            else {
                curr &= a[i];
            }

            if (curr == 0) {
                curr = -1;
                ++res;
            }
        }

        cout << max(res, 1ll) << endl;


    }
}