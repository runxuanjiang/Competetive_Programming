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
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }


        sort(a.begin(), a.end());


        for (int i = 0; i < k; ++i) {
            sum -= a[n-i-1];
        }

        ll res = sum;


        ll l = 0, r = n-k;

        for (int i = 0; i < k; ++i) {
            sum += a[r];
            sum -= a[l];
            sum -= a[l+1];
            ++r;
            l += 2;

            res = max(sum, res);
        }


        cout << res << endl;
    }
}
