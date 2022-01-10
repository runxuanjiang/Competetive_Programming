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
        ll t1, t2, r1, r2;
        cin >> t1 >> t2 >> r1 >> r2;

        if ((t1*t1)*(r2*r2*r2) == (t2*t2)*(r1*r1*r1)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}