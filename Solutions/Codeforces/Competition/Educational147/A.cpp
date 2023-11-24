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
        string s;
        cin >> s;

        ll res = 0;
        if (s[0] == '0') {
            cout << res << endl;
        }
        else {
            res = 1;
            if (s[0] == '?') {
                res = 9;
            }
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] == '?') {
                    res *= 10;
                }
            }

            cout << res << endl;
        }
    }
}