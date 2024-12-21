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
        ll x, k;
        cin >> x >> k;

        if (x % k == 0) {
            cout << 2 << endl;
            cout << x-1 << " " << 1 << endl;
        }
        else {
            cout << 1 << endl;
            cout << x << endl;
        }
    }
}