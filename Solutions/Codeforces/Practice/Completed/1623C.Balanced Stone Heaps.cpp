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

bool check(ll m, const vector<ll> &heaps) {
    vector<ll> d(heaps.begin(), heaps.end());
    for (int i = heaps.size() - 1; i >= 2; --i) {
        if (d[i] < m) {
            return false;
        }
        ll diff = min(heaps[i], d[i] - m);
        ll div = diff / 3;
        d[i-1] += div;
        d[i-2] += (div * 2);
    }

    return (d[0] >= m && d[1] >= m);
}

int main() {
    fast;
    tests {
        int n;
        cin >> n;
        ll l = 0, r = 0;
        vector<ll> heaps(n);
        for (int i = 0; i < n; ++i) {
            cin >> heaps[i];
            r = max(r, heaps[i]);
        }

        ll res = 0;

        while (l <= r) {
            ll mid = l + (r-l)/2;
            if (check(mid, heaps)) {
                res = mid;
                l = mid + 1;
            }
            else {
                r = mid-1;
            }
        }
        cout << res << endl;


    }
}