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
        int n;
        cin >> n;
        string s;
        cin >> s;

        ll res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res += (ll) (s[i] - '0');

            if (s[i] != '0' && i < s.size() - 1) {
                ++res;
            }
        }
        cout << res << endl;
    }
}