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
        ll px, py;
        cin >> px >> py;
        string s;
        cin >> s;
        char xchar = (px >= 0) ? 'R' : 'L';
        char ychar = (py >= 0) ? 'U' : 'D';

        px = abs(px);
        py = abs(py);
        for (auto i : s) {
            if (i == xchar) {
                --px;
            }
            else if (i == ychar) {
                --py;
            }
        }

        if (px > 0 || py > 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}