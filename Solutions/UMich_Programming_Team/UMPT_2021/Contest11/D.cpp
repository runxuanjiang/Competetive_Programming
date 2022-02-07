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

bool check(ll m, const vector<ll> &a, ll k) {

    ll tot = 0;
    for (int i = 0; i < a.size(); ++i) {
        ++tot;
        ll curr = a[i];
        if (a[i] > m) {
            return false;
        }

        while (i + 1 < a.size() && curr + a[i+1] <= m) {
            ++i;
            curr += a[i];
        }
    }

    return tot <= k;
}

int main() {
    fast;
    int n;
    cin >> n;
    ll k;
    cin >> k;

    ll l = 0, r = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        r += a[i];
    }

    ll res = r;

    while (l <= r) {
        ll m = l + (r-l)/2;
        if (check(m, a, k)) {
            res = m;
            r = m-1;
        }
        else {
            l = m+1;
        }

    }
    cout << res << endl;
}