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
        ll n;
        cin >> n;
        string s, t;
        cin >> s >> t;



        ll mismatches = 0;
        ll reverseMismatches = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                ++mismatches;
            }
            if (s[i] != t[n - i - 1]) {
                ++reverseMismatches;
            }
        }

        if (mismatches == 0) {
            cout << 0 << endl;
            continue;
        }
        if (reverseMismatches == 0) {
            cout << 2 << endl;
            continue;
        }


        ll res1;
        if (mismatches % 2 == 0) {
            res1 = mismatches*2;
        }
        else {
            res1 = mismatches*2 - 1;
        }

        ll res2;
        if (reverseMismatches % 2 == 0) {
            res2 = reverseMismatches*2 - 1;
        }
        else {
            res2 = reverseMismatches*2;
        }
        cout << min(res1, res2) << endl;
    }
}