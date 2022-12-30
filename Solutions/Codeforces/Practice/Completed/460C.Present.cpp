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

bool check(ll mid, ll m, ll w, const vector<ll> &a) {
    ll curr = 0;
    vector<ll> offset(a.size(), 0);
    for (int i = 0; i < a.size(); ++i) {
        curr += offset[i];
        if (a[i] + curr < mid) {
            ll diff = mid - (curr + a[i]);
            if (i + w < a.size()) {
                offset[i+w] -= diff;
            }
            curr += diff;
            m -= diff;
            if (m < 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    fast;
    ll n, m, w;
    cin >> n >> m >> w;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll res = 0;

    ll l = 0, r = 1000000000 + m;
    while (l <= r) {
        ll mid = l + (r-l)/2;
        if (check(mid, m, w, a)) {
            res = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << res << endl;



    
}