//Competition #: 260 D1 (455A)
//Problem #: A
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
    ll n;
    cin >> n;

    map<ll, ll> mp;

    for (int i = 0; i < n; ++i) {
        ll in;
        cin >> in;
        if (mp.find(in) != mp.end()) {
            mp[in]++;
        }
        else {
            mp[in] = 1;
        }
    }

    ll res = 0;

    for (auto i = mp.begin(); i != mp.end(); ++i) {
        vector<ll> dp(3, 0);
        dp[2] = i->first * i->second;

        while(next(i) != mp.end() && next(i)->first == i->first + 1) {
            ++i;
            dp[0] = dp[1];
            dp[1] = dp[2];

            dp[2] = max(dp[0] + i->first * i->second, dp[1]);
        }

        res += dp[2];
    }

    cout << res << endl;
}