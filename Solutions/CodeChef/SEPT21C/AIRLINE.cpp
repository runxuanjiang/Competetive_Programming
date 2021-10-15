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
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if (a + b <= d && c <= e) {
            cout << "YES" << endl;
        }
        else if (b + c <= d && a <= e) {
            cout << "YES" << endl;
        }
        else if (a + c <= d && b <= e) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}