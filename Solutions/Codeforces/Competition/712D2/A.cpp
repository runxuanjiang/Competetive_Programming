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
        bool found = false;
        int idx = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != 'a') {
                found = true;
                idx = i;
                break;
            }
        }

        if (!found) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            if (idx >= (s.length() / 2)) {
                if (s.length() % 2 == 0) {
                    s.insert(s.length() - idx - 1, "a");
                }
                else {
                    s.insert(s.length() - idx -1, "a");
                }
                
            }
            else {
                s.insert(s.length() - idx, "a");
            }

            cout << s << endl;
        }
    }
}