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
        ll n;
        cin >> n;
        string s;
        cin >> s;
        int l = 0, r = n-1;
        int res = 0;
        while (l < r) {
            if (s[l] != s[r]) {
                ++res;
            }
            ++l;
            --r;
        }

        cout << (res + 1)/2 << endl;
    }
}