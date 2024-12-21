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
        ll n;
        cin >> n;
        string s;
        cin >> s;


        ll res = 2;
        ll curr = 2;


        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1]) {
                ++curr;
                res = max(res, curr);
            }
            else {
                curr = 2;
            }
        }
        cout << res << endl;


    }
}