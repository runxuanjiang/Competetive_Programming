//Competition #:
//Problem #: C
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
        ll n, m;
        cin >> n >> m;
        if (n == 1) {
            cout << "YES" << endl;
        }
        else if (m >= n) {
            cout << "NO" << endl;
        }
        else {
            bool good = true;
            for (int i = 2; i*i <= n; ++i) {
                if (n % i == 0 && i <= m) {
                    good = false;
                    break;
                }
            }

            if (good) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }

    }
}