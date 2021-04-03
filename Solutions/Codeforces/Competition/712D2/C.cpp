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
        string s;
        cin >> s;

        int zero = 0;
        for (auto i : s) {
            if (i == '0') ++ zero;
        }
        int one = n - zero;

        if (zero % 2 == 0 && s.front() == '1' && s.back() == '1') {
            cout << "YES\n";
            int tempOne = 1;
            int tempZero = 1;
            string out = "";
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') {
                    if (tempZero % 2 == 1) {
                        out.push_back('(');
                    }
                    else {
                        out.push_back(')');
                    }
                    ++tempZero;
                }
                else {
                    if (tempOne <= one/2) {
                        out.push_back('(');
                    }
                    else {
                        out.push_back(')');
                    }
                    ++tempOne;
                }
            }
            cout << out << endl;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '0') {
                    out[i] = (out[i] == ')') ? '(' : ')';
                }
            }
            cout << out << endl;

        }
        else {
            cout << "NO\n";
        }
    }
}