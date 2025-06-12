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

        if (s.size() == 2) {
            if (s == "((" || s == "))") {
                cout << "YES" << endl;
                cout << "()()" << endl;
            }
            else if (s == ")(") {
                cout << "YES" << endl;
                cout << "(())" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else {

            cout << "YES" << endl;

            bool is_alternating = true;
            if (s[0] == s[1]) {
                is_alternating = false;
            }
            for (int i = 0; i < s.size(); ++i) {
                if (i % 2 == 0 && s[i] != s[0]) {
                    is_alternating = false;
                }
                if (i % 2 == 1 && s[i] != s[1]) {
                    is_alternating = false;
                }
            }

            if (is_alternating) {
                for (int i = 0; i < s.size(); ++i) {
                    cout << '(';
                }
                for (int i = 0; i < s.size(); ++i) {
                    cout << ')';
                }
            }
            else {
                for (int i = 0; i < s.size(); ++i) {
                    cout << "()";
                }
            }
            cout << endl;
        }
    }
}