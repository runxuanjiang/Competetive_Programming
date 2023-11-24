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
        string s;
        cin >> s;

        ll res = -1;

        for (int i = 0; i < 26; ++i) {
            char keep = 'a' + i;

            ll longest = 0;
            ll currlen = 0;
            for (auto i : s) {
                if (i == keep) {
                    longest = max(longest, currlen);
                    currlen = 0;
                }
                else {
                    ++currlen;
                }
            }
            longest = max(longest, currlen);

            ll bits = 0;
            while (longest) {
                longest >>= 1;
                ++bits;
            }

            if (res == -1) {
                res = bits;
            }
            else {
                res = min(res, bits);
            }

        }

        cout << res << endl;


    }
}