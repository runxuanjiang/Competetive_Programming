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
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll positives = 0, negatives = 0;
        for (auto i : a) {
            if (i > 0) {
                positives++;
            } else if (i < 0) {
                negatives++;
            }
        }

        if (negatives == 0) {
            cout << n-1 << endl;
            for (int i = 2; i <= n; ++i) {
                cout << i << " " << i-1 << endl;
            }
        }
        else if (positives == 0) {
            cout << n-1 << endl;
            for (int i = n-1; i >= 1; --i) {
                cout << i << " " << i+1 << endl;
            }
        }
        else {

            cout << 5 + n + n - 1 << endl;
            ll j = 0;
            while (a[j] <= 0) {
                ++j;
            }

            for (int i = 0; i < 5; ++i) {
                cout << j+1 << " " << j+1 << endl;
            }

            for (int i = 1; i <= n; ++i) {
                cout << i << " " << j+1 << endl;
            }

            for (int i = 2; i <= n; ++i) {
                cout << i << " " << i-1 << endl;
            }
        }


    }
}