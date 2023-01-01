//Competition #: Educational Round 94
//Problem #: E
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll recurse(ll start, ll end, ll offset, const vector<ll> &a) {
    ll minH = a[start];
    for (int i = start; i <= end; ++i) {
        minH = min(minH, a[i]);
    }
    ll res = minH - offset;
    for (int i = start; i <= end; ++i) {
        if (a[i] > minH) {
            ll newstart = i;
            while (i + 1 <= end && a[i+1] > minH) {
                ++i;
            }

            res += recurse(newstart, i, minH, a);
        }
    }
    res = min(res, end-start + 1);
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<ll> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    ll res = recurse(0, n-1, 0, v);

    cout << res << endl;


}