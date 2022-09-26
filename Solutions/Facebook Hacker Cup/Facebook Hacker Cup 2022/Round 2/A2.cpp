//Competition #:
//Problem #:
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
    int test = 0;
    tests {
        ++test;
        cout << "Case #" << test << ": ";

        ll res = 0;

        ll n;
        cin >> n;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll q;
        cin >> q;

        for (int i = 0; i < q; ++i) {
            ll c;
            cin >> c;
            if (c == 1) {
                ll x, y;
                cin >> x >> y;
            }
            else {
                ll a, b;
                cin >> a >> b;
            }
        }

        cout << res << endl;

    }
}