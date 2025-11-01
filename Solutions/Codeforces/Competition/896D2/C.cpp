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

        if (m == 1) {
            cout << 0 << endl;
            for (int i = 0; i < n; ++i) {
                cout << 0 << endl;
            }
        }
        else {
            ll res = min(n+1, m);

            cout << res << endl;

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (i+1 < m) {
                        cout << (i+j)%m << " ";
                    }
                    else {
                        cout << j << " ";
                    }
                    
                }
                cout << endl;
            }
        }









    }
}