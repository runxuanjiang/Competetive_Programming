//Competition #:
//Problem #: C
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
 
#define tests int testCount; cin >> testCount; while(testCount--)

ll calcNumVacations(const ll consecutiveDays, const ll k) {
    if (consecutiveDays < k) {
        return 0;
    }


    ll possibleKTrips = consecutiveDays - k + 1;
    return possibleKTrips * (possibleKTrips + 1) / 2;
}

int main() {
    fast;
    tests {
        ll n, k, q;
        cin >> n >> k >> q;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll consecutiveDays = 0;
        ll res = 0;
        for (auto i : a) {
            if (i <= q) {
                ++consecutiveDays;
            }
            else {
                res += calcNumVacations(consecutiveDays, k);
                consecutiveDays = 0;
            }
        }

        res += calcNumVacations(consecutiveDays, k);
        cout << res << endl;


    }
}