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

        if (n == 1) {
            cout << "NO" << endl;
            continue;
        }

        ll ones = 0;
        ll not_ones = 0;
        ll sum_not_ones = 0;

        for (auto i : a) {
            if (i == 1) {
                ones++;
            } else {
                not_ones++;
                sum_not_ones += i;
            }
        }

        if (sum_not_ones - not_ones >= ones) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }

    }
}