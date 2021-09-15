//Competition #:
//Problem #:
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
        int n, a, b;
        string s;
        cin >> n >> a >> b;
        cin >> s;

        ll res = 0;
        for (auto i : s) {
            if (i == '0') {
                res += a;
            }
            else {
                res += b;
            }
        }
        cout << res << endl;
    }
}