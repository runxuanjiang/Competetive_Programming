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
        vector<ll> a(n), b(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }


        sort(b.begin(), b.end(), greater<ll>());
        sort(a.begin(), a.end(), greater<ll>());

        ll idx = 0;
        ll res = 1;


        for (int i = 0; i < b.size(); ++i) {
            while (idx < n && a[idx] > b[i]) {
                ++idx;
            }

            res = (res * (idx - i)) % MOD;
        }
        cout << res << endl;

    }
}