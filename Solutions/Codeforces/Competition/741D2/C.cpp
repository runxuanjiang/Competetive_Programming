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
        ll n;
        cin >> n;
        string s;
        cin >> s;

        bool done = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                if (i < n/2) {
                    cout << i+1 << " " << n << " " << i+2 << " " << n << endl;
                }
                else {
                    cout << 1 << " " << i+1 << " " << 1 << " " << i << endl;
                }
                done = true;
                break;
            }
        }

        if (!done) {
            cout << 1 << " " << n-1 << " " << 2 << " " << n << endl;
        }
    }
}