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
        ll b, c, h;
        cin >> b >> c >> h;

        if (c+h+1 >= b) {
            cout << b + b - 1 << endl;
        }
        else {
            cout << c+h+c+h+1 << endl;
        }
    }
}