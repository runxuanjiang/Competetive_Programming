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

        vector<ll> triple1 = {n, n+1, 2*n+1};
        for (auto &i : triple1) {
            if (i % 2 == 0) {
                i /= 2;
                break;
            }
        }
        for (auto &i : triple1) {
            if (i % 3 == 0) {
                i /= 3;
                break;
            }
        }

        vector<ll> triple2 = {n-1, n, 2*n-1};
        for (auto &i : triple2) {
            if (i % 2 == 0) {
                i /= 2;
                break;
            }
        }
        for (auto &i : triple2) {
            if (i % 3 == 0) {
                i /= 3;
                break;
            }
        }

        ll res1 = 1;
        ll res2 = 1;
        for (auto i : triple1) {
            res1 = (res1 * i) % MOD;
        }
        for (auto i : triple2) {
            res2 = (res2 * i) % MOD;
        }
        ll nm = (((n-1) * n)/2) % MOD;
        cout << ((res1 + res2 + nm)*2022) % MOD << endl;
    }
}