//Competition #: Codeforces Round 107 Div 2
//Problem #: D
//Accepted: YES

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    if (k == 1 || k > n) {
        ll res = 1;
        for (int i = 0; i < n; ++i) {
            res *= m;
            res %= MOD;
        }
        cout << res;
    }
    else if (k == n) {
        ll res = 1;
        for (int i = 0; i < (n+1)/2; ++i) {
            res *= m;
            res %= MOD;
        }
        cout << res;
    }
    else if (k % 2 == 0) {
        cout << m;
    }
    else if (k % 2 != 0) {
        cout << m *m;
    }
}