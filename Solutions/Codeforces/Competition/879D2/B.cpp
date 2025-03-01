//Competition #:
//Problem #: B
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
        string L, R;
        cin >> L >> R;

        ll res = 0;

        if (L.size() < R.size()) {
            L = string(R.size() - L.size(), '0') + L;
        }

        for (int i = 0; i < L.size(); ++i) {
            if (L[i] != R[i]) {
                res = (R[i] - L[i]) + (9 * (R.size() - i - 1));
                break;
            }
        }

        cout << res << endl;


        
    }
}