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
        int a, b;
        cin >> a >> b;

        if (a > 0 && b > 0) {
            cout << "Solution" << endl;
        }

        else if (b == 0) {
            cout << "Solid" << endl;
        }

        else if (a == 0) {
            cout << "Liquid" << endl;
        }
    }
}