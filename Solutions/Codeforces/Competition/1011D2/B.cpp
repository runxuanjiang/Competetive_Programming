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
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> zeropos;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                zeropos.push_back(i);
            }
        }

        if (zeropos.empty()) {
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
        }
        else {
            ll split = n/2;
            ll zeros = 0;
            for (int i = 0; i < split; ++i) {
                if (a[i] == 0) {
                    ++zeros;
                }
            }

            if (zeros == zeropos.size()) {
                cout << 2 << endl;
                cout << 1 << " " << split << endl;
                cout << 1 << " " << n-split+1 << endl;
            }
            else if (zeros == 0) {
                cout << 2 << endl;
                cout << split+1 << " " << n << endl;
                cout << 1 << " " << split+1 << endl;
            }
            else {
                cout << 3 << endl;
                cout << split+1 << " " << n << endl;
                cout << 1 << " " << split << endl;
                cout << 1 << " " << 2 << endl;
            }

        }
    }
}