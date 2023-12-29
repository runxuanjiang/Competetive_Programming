//Competition #:
//Problem #: D
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

        if (n % 2) {
            if (n == 1) {
                cout << 1 << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
        else {
            ll c = n;
            cout << n << " ";
            --c;
            while (c > 1) {
                cout << c << " ";
                cout << n+1-c << " ";
                c -= 2;
            }
            cout << 1 << endl;
        }


    }
}