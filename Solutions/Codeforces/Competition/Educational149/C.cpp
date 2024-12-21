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

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '?' && s[i-1] != '?') {
                s[i] = s[i-1];
            }
        }

        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] == '?' && s[i+1] != '?') {
                s[i] = s[i+1];
            }
        }

        if (s[0] == '?') {
            cout << string(s.size(), '0') << endl;
        }
        else {
            cout << s << endl;
        }
    }
}