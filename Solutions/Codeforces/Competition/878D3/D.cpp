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


bool isPossible(ll time, const vector<ll> a) {
    ll start = a[0];
    ll resets = 1;
    for (auto i : a) {
        if ((i - start + 1)/2 > time) {
            start = i;
            ++resets;
        }
    }
    return resets <= 3;
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

        sort(a.begin(), a.end());

        ll l = 0, r = 1000000000;
        ll res;
        while (l <= r) {
            ll m = l + (r-l)/2;
            if (isPossible(m, a)) {
                res = m;
                r = m-1;
            }
            else {
                l = m+1;
            }
        
        }
        cout << res << endl;


    }
}