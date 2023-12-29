//Competition #:
//Problem #: A
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

        vector<ll> a(n, 1);

        bool good = false;

        for (int i = 0; i < n; ++i) {
            a[i] = -1;
            ll curr = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i+1; j < n; ++j) {
                    if (a[i] * a[j] == 1) {
                        ++curr;
                    }
                }
            }

            if (curr == k) {
                cout << "YES" << endl;
                good = true;
                for (auto i : a) {
                    cout << i << " ";
                }
                cout << endl;
                break;
            }
        }

        if (!good) {
            cout << "NO" << endl;
        }
    }
}