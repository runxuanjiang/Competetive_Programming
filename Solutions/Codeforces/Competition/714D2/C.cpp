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
    vector<ll> digits(10, 0);
    digits[0] = 1;
    ll sol[200020];
    for (int i = 1; i <= 200020; ++i) {
            int nines = digits[9];
            for (int j = 9; j >= 0; --j) {
                digits[j] = digits[j-1];
            }
            digits[0] = nines;
            digits[1] = (digits[1] + nines) % MOD;

            ll res = 0;

            for (auto j : digits) {
                res = (res + j ) % MOD;
            }
            sol[i-1] = res;
    }
    tests {
        string n;
        ll m;
        cin >> n;
        cin >> m;
        vector<ll> digits(10, 0);
        for (auto i : n) {
            digits[i - '0']++;
        }
        ll res = 0;
        for (int i = 0; i < 10; ++i) {
            res = (res + sol[i + m-1] * digits[i]) % MOD;
        }
        cout << res << endl;


    }

}