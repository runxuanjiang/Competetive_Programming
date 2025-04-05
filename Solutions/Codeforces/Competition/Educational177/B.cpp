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
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll sum = 0;
        for (const auto i : a) {
            sum += i;
        }

        ll res = 0;
        for (int i = n-1; i >= 0; --i) {
            x -= a[i];
            ll full_lengths = 0;
            if (x > 0) {
                full_lengths = (x % sum == 0) ? x/sum : 1 + x/sum;
            }
            // cerr << "a[i] and full lengths: " << a[i] << " " << full_lengths << endl;
            if (full_lengths + 1 <= k) {
                res += (k - full_lengths);
            }
        }
        cout << res << endl;
    }

}