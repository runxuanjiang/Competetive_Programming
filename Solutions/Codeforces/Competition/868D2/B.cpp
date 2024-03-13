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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll swaps = 0;
        for (ll i = 1; i <= k; ++i) {
            for (int j = i-1; j < n; j += k) {
                if ((a[j] - i) % k) {
                    ++swaps;
                }
            }
        }

        if (swaps == 0) {
            cout << 0 << endl;
        }
        else if (swaps == 2) {
            cout << 1 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}