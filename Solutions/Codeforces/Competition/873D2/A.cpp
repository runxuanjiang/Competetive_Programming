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
        ll n;
        cin >> n;

        if (n % 2 == 0) {
            for (int i = 1; i <= n; ++i) {
                if (i*2 == n) {
                    cout << i*2 << " ";
                }
                else {
                    cout << i << " ";
                }
            }
        }
        else {
            for (int i = 1; i <= n; ++i) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
}