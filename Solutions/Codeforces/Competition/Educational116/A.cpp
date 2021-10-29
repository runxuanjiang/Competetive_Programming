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

        int ab = 0, ba = 0;
        for (int i = 0; i < s.size()-1; ++i) {
            if (s[i] == 'a' && s[i+1] == 'b') {
                ++ab;
            }
            else if (s[i] == 'b' && s[i+1] == 'a') {
                ++ba;
            }
        }

        if (ab > ba) {
            s.back() = 'a';
        }
        else if (ba > ab) {
            s.front() = 'a';
        }

        cout << s << endl;
    }
}