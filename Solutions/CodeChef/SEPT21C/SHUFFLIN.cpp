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
        vector<ll> a(n);
        ll odds = 0, evens = 0;
        for (int i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            if (a % 2 == 0) {
                ++evens;
            }
            else {
                ++odds;
            }
        }

        ll maxodd = n/2;
        ll maxeven = (n+1)/2;
        ll res = min(maxeven, evens) + min(maxodd, odds);
        cout << res << endl;



    }
}