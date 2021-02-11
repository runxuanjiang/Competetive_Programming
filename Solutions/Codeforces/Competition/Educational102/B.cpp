//Competition #:
//Problem #: B
//Accepted: Yes

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
        string s, t;
        cin >> s >> t;

        ll length = lcm(s.length(), t.length());

        string slong = "", tlong = "";

        for (int i = 0; i < length/s.length(); ++i) {
            slong += s;
        }
        for (int i = 0; i < length/t.length(); ++i) {
            tlong += t;
        }

        if (slong == tlong) {
            cout << slong << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}