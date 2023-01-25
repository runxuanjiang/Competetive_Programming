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

bool isPerfectSquare(ll n) {
    ll l = 0, r = 2'000'000'000;
    while (l <= r) {
        ll m = l + (r-l)/2;
        if (m*m == n) {
            return true;
        }
        else if (m*m < n) {
            l = m+1;
        }
        else {
            r = m-1;
        }

    }

    return false;
}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll res = 1;
        sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                ll diff = a[j] - a[i];
                for (ll k = 1; k*k <= diff; ++k) {
                    if (diff % k == 0) {
                        ll div1 = k;
                        ll div2 = diff / k;
                        if ((div2 - div1) % 2 == 0) {
                            ll y = (div2 - div1) / 2;
                            ll x = div1 + y;

                            ll plus = y*y - a[i];

                            if (plus >= 0) {
                                ll tempres = 0;
                                for (auto num : a) {
                                    tempres += isPerfectSquare(plus + num);
                                }

                                res = max(res, tempres);
                            }

                        }
                    }
                }

                

            }
        }

        cout << res << endl;


    }
}