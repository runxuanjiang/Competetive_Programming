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
        string s, t;
        cin >> s >> t;
        ll length = lcm((int) s.size(), (int) t.size());
        string res1, res2;
        while (res1.size() < length) {
            res1 += s;
        }
        while (res2.size() < length) {
            res2 += t;
        }

        if (res1 == res2) {
            cout << res2 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}