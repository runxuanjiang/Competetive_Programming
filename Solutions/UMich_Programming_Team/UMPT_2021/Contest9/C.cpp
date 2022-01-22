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
        int n;
        cin >> n;
        ll l, r;
        cin >> l >> r;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll res = 0;
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); ++i) {
            ll tl = l - a[i], tr = r - a[i];
            auto liter = lower_bound(a.begin() + i + 1, a.end(), tl);
            auto riter = upper_bound(a.begin() + i + 1, a.end(), tr);
            res += (riter - liter);
        }

        cout << res << endl;
    }
}