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

        if (k == 1) {
            cout << n / k << endl;
        }
        else {
            if (n % k <= 1) {
                cout << 1 + (n/k) << endl;
            }
            else {
                cout << 2 + (n/k) << endl;
            }

        }
    }
}