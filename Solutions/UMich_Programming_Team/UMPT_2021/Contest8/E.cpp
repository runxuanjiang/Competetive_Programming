//Competition #:
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

bool check(int m, const vector<ll> &a, int k) {
    for (int i = a.size() / 2; i < a.size(); ++i) {
        if (a[i] < m) {
            k -= (m - a[i]);
        }
        if (k < 0) {
            return false;
        }
    }
    return true;

}

int main() {
    fast;
    int n;
    cin >> n;
    ll k;
    cin >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll l = a[n/2], r = a.back() + k;
    ll res = l;
    while (l <=r ) {
        ll m = l + (r-l)/2;
        if (check(m, a, k)) {
            res = m;
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    cout << res << endl;
}