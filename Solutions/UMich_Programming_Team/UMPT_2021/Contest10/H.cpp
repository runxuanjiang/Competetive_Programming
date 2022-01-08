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
    vector<ll> temp(heaps.begin(), heaps.end());
    for (int i = temp.size() - 1; i >= 2; --i) {
        if (temp[i] < m) {
            return false;
        }

        ll diff = min(temp[i] - m, heaps[i]);
        while (diff % 3 > 0) {
            --diff;
        }

        temp[i-1] += diff/3;
        temp[i-2] += (diff/3)*2;
    }

    if (temp[0] < m) {
        return false;
    }

    if (temp[1] < m) {
        return false;
    }

    return true;
}

int main() {
    fast;
    tests {
        int n;
        cin >> n;
        vector<ll> heaps(n);
        ll l = MOD, r = 0;
        for (int i = 0; i < n; ++i) {
            cin >> heaps[i];
            l = min(l, heaps[i]);
            r = max(r, heaps[i]);
        }

        ll res = 0;

        while (l <= r) {
            ll m = l + (r-l)/2;
            if (check(m, heaps)) {
                res = m;
                l = m+1;
            }
            else {
                r = m -1;
            }
        }
        cout << res << endl;


        
    }
}