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

    int test = 0;
    tests {
        ++test;
        cout << "Case #" << test << ": ";

        ll n, k;


        ll tc, tw;
        cin >> tc >> tw;
        ll gc = 0;
        ll lc = 0;
        ll ec = 0;


        for (int i = 1; i < n; ++i) {
            ll c, w;
            cin >> c >> w;

            if (w < tw) {
                lc += c;
            }
            else if (w > tw) {
                gc += c;
            }
            else {
                ec += c;
            }
        }

        ll tot = tc + gc + lc + ec;

        pair<ll, ll> res = {tc, tot};

        for (int i = 1; i < k; ++i) {
            res.first = (res.first * max(tc + lc - i, 0ll)) % MOD;
            res.second = (res.second * (tot - i)) % MOD;
        }

        pair<ll, ll> res2 = {lc, tot};
        vector<pair<ll, ll>> 





    }
}