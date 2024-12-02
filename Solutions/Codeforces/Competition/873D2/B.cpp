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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll res = 0;

        for (int i = 0; i < n; ++i) {
            int idx = i+1;
            if (idx != a[i]) {
                if (!res) {
                    res = abs(idx - a[i]);
                }
                else {
                    res = gcd(res, abs(idx - a[i]));
                }
            }
        }

        cout << res << endl;
    }

}