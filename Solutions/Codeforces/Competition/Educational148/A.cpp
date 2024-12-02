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

        char last = s[0];
        bool good = false;

        for (int i = 0; i*2 + 1 < s.size(); ++i) {
            if (s[i] != last) {
                good = true;
                break;
            }
        }

        cout << (good ? "YES" : "NO") << endl;
    }
}