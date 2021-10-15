//Competition #:
//Problem #:
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a + b + c <= d) {
            cout << 1 << endl;
        }
        else if (a + b <= d) {
            cout << 2 << endl;
        }
        else {
            cout << 3 << endl;
        }
    }
}