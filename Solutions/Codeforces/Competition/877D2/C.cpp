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

        for (int i = 0; i*2+1 < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cout << (i*2+1)*m + j << " ";
            }
            cout << endl;
        }
        for (int i = 0; i*2 < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cout << i*2*m + j << " ";
            }
            cout << endl;
        }

        cout << endl;


    }
}