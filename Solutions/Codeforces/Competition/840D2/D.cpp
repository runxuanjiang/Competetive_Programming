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

vector<vector<ll>> pascal(101, vector<ll>(101, 0));

ll choose(ll n, ll k) {
    if (k < 0 || k > n) {
        return 0;
    }

    return pascal[n][k];

}

int main() {
    fast;

    
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            }
            else {
                pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j]) % MOD;
            }
        }
    }
    tests {
        ll n;
        cin >> n;
        ll i, j;
        cin >> i >> j;
        ll x, y;
        cin >> x >> y;

        if (x > y) {
            swap(x, y);
            ll oi = i;
            i = n - j + 1;
            j = n - oi + 1;
        }

        if (y == n) {
            if (j == n) {
                cout << 0 << endl;
            }
            else {
                ll res = 1;
                res = (res*choose(y-x-1, j-i-1)) % MOD;
                res = (res*choose(x-1, i-1)) % MOD;
                cout << res << endl;
            }
        }
        else {
            ll res = 0;
            for (int k = i+1; k < n; ++k) {
                if (k > j) {
                    ll tempres = 1;
                    tempres = (tempres * choose(n-y-1, k-j-1)) % MOD;
                    tempres = (tempres * choose(y-x-1, j-i-1)) % MOD;
                    tempres = (tempres * choose(x-1, i-1)) % MOD;
                    res = (res + tempres) % MOD;
                }
                else if (k < j) {
                    ll tempres = 1;
                    tempres = (tempres * choose(n-y-1, j-k-1)) % MOD;
                    tempres = (tempres * choose(x-1, i-1)) % MOD;
                    tempres = (tempres * choose(y-x-1, n-j-x+i)) % MOD;
                    res = (res + tempres) % MOD;
                }
            }

            cout << res << endl;
        }
    }
}