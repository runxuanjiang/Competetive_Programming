//Competition #:
//Problem #: I
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
    int n;
    cin >> n;
    ++n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll res = 0;

    for (int i = n - 1; i >= 1; --i) {
        if (a[i] < b[i]) {
            ll diff = (b[i] - a[i] + 1)/2;
            a[i-1] -= diff;
            res += diff;
        }
    }

    if (a[0] >= b[0]) {
        cout << res << endl;
    }
    else {
        cout << -1 << endl;
    }

}