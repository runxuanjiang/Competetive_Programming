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
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool found = false;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '8') {
                if (s.length() - i >= 11) {
                    cout << "YES\n";
                    found = true;
                }
                break;
            }
        }

        if (!found) {
            cout << "NO\n";
        }
    }
}