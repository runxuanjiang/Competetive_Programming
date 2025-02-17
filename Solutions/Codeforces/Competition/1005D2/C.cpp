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
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }


        vector<ll> prefixSumPositive(n+1, 0);
        vector<ll> suffixSumNegative(n+1, 0);
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) {
                prefixSumPositive[i+1] = prefixSumPositive[i] + a[i];
            } else {
                prefixSumPositive[i+1] = prefixSumPositive[i];
            }
        }
        for (int i = n-1; i >= 0; --i) {
            if (a[i] < 0) {
                suffixSumNegative[i] = suffixSumNegative[i+1] + a[i];
            } else {
                suffixSumNegative[i] = suffixSumNegative[i+1];
            }
        }

        ll res = 0;
        for (int i = 0; i <= n; ++i) {
            res = max(res, prefixSumPositive[i] - suffixSumNegative[i]);
        }
        cout << res << endl;
    }
}