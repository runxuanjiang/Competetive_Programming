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
        string s;
        cin >> s;
        bool ones = false;
        bool no = false;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == '1' && s[i-1] == '1') {
                ones = true;
            }
            if (s[i] == '0' && s[i-1] == '0' && ones) {
                no = true;
                break;
            }
        }

        cout << (no ? "NO\n" : "YES\n");

    }
}