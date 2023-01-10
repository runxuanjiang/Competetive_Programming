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

        if (s[0] == 'b') {
            cout << s[0] << " ";
            cout << s[1] << " ";
            for (int i = 2; i < s.size(); ++i) {
                cout << s[i];
            }
            cout << endl;
        }
        else {
            if (s[1] == 'a') {
                cout << s[0] << " ";
                cout << s[1] << " ";
                for (int i = 2; i < s.size(); ++i) {
                    cout << s[i];
                }
                cout << endl;
            }
            else {
                cout << s[0] << " ";
                int idx = 1;
                while (idx + 1 < s.size() && s[idx] == 'b') {
                    cout << 'b';
                    ++idx;
                }
                cout << " ";
                while (idx < s.size()) {
                    cout << s[idx];
                    ++idx;
                }
                cout << endl;
            }
        }
    }
    
}