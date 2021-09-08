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
    int n, m;
    cin >> n >> m;

    int xl = 1, xr = n;
    while (xl < xr) {
        for (int i = 1; i <= m; ++i) {
            cout << xl << " " << i << '\n';
            cout << xr << " " << (m - i + 1) << '\n';
        }
        ++xl;
        --xr;
    }
    if (xl == xr) {
        int yl = 1, yr = m;
        while (yl < yr) {
            cout << xl << " " << yl << '\n';
            cout << xl << " " << yr << '\n';
            ++yl;
            --yr;
        }
        if (yl == yr) {
            cout << xl << " " << yr << '\n';
        }
    }
}