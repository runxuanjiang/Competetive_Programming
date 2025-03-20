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

        if (n < 3) {
            for (int i = 1; i <= n; ++i) {
                cout << i << " ";
            }
            cout << endl;
        }
        else {
            ll x = 4;
            for (int i = 0; i < n; ++i) {
                if (i == 0) {
                    cout << 2 << " ";
                }
                else if (i+1 == n) {
                    cout << 3 << " ";
                }
                else if (i == n/2) {
                    cout << 1 << " ";
                }
                else {
                    cout << x << " ";
                    ++x;
                }
            }
            cout << endl;
        }
    }
}