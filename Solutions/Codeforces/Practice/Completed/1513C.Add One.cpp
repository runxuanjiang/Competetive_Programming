//Competition #:
//Problem #:
//Accepted: YES

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
    vector<ll> dp(200020);
    for (int i = 0; i < 200020; ++i) {
        if (i < 9) dp[i] = 2;
        else if (i == 9) dp[i] = 3;
        else {
            dp[i] = (dp[i-9] + dp[i-10]) % MOD;
        }
    }
    tests {
        string n;
        cin >> n;
        ll m;
        cin >> m;


        ll res = 0;
        for (auto i : n) {
            res = (res + ((i - '0' + m < 10 ) ? 1 : (dp[m - (10 - (i - '0'))]))) % MOD;
        }
        cout << res << endl;
    }
}