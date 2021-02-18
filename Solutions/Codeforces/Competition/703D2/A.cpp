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
        int n;
        cin >> n;
        ll tot = 0;
        ll m = 0;
        bool good = true;
        for (int i = 0; i < n; ++i) {
            ll in;
            cin >> in;
            tot += in;

            m += i;

            if (tot < m) {
                good = false;
            }
        }

        if (good) {
            cout << "YES\n";
        }
        else cout << "NO\n";


    }
}