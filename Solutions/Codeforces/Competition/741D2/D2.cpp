//Competition #:
//Problem #: D
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
        ll n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> prefixEven(n+1, 0);
        vector<int> prefixOdd(n+1, 0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '+') {
                if (i % 2 == 0) {
                    prefixEven[i+1] = prefixEven[i] + 1;
                    prefixOdd[i+1] = prefixOdd[i] - 1;
                }
                else {
                    prefixEven[i+1] = prefixEven[i] -1;
                    prefixOdd[i+1] = prefixOdd[i] + 1;
                }
            }
            else {
                if (i % 2 == 0) {
                    prefixEven[i+1] = prefixEven[i] -1;
                    prefixOdd[i+1] = prefixOdd[i] + 1;
                }
                else {
                    prefixEven[i+1] = prefixEven[i] +1;
                    prefixOdd[i+1] = prefixOdd[i] - 1;
                }
            }
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            if (l % 2 == 1) {
                int rem =  abs(prefixEven[r] - prefixEven[l-1]);
                if (rem == 0) {
                    cout << 0 << endl;
                }
                else if (rem % 2 == 0) {
                    cout << 2 << endl;
                }
                else {
                    cout << 1 << endl;
                }
            }
            else {
                int rem =  abs(prefixOdd[r] - prefixOdd[l-1]);
                if (rem == 0) {
                    cout << 0 << endl;
                }
                else if (rem % 2 == 0) {
                    cout << 2 << endl;
                }
                else {
                    cout << 1 << endl;
                }
            }

        }
    }
}