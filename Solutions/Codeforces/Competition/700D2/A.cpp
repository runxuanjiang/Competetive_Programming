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
        for (int i = 0; i < s.length(); ++i) {
            if (i % 2 == 0) {
                s[i] = (s[i] == 'a') ? 'b' : 'a';
            }
            else {
                s[i] = (s[i] == 'z') ? 'y' : 'z';
            }
        }
        cout << s << endl;
    }
}