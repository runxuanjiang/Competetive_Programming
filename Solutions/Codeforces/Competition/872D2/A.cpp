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
        bool good = true;
        for (auto i : s) {
            if (i != s[0]) {
                good = false;
            }
        }

        cout << (good ? -1 : ((ll) s.size() - 1)) << endl;
    }
}