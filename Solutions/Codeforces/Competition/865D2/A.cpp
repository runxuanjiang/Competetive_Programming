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
        ll a, b;
        cin >> a >> b;

        if (a == 1 || b == 1) {
            cout << 1 << endl;
            cout << a << " " << b << endl;
        }
        else {
            cout << 2 << endl;
            cout << 1 << " " << b-1 << endl;
            cout << a << " " << b << endl;
        }
    }
}