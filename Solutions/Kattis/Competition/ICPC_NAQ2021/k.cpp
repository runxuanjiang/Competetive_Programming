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

bool bs(int iter, ll targ, vector<ll> &psum) {
    int l = 0, r = psum.size() - 1 - iter;
    while (l <= r) {
        int m = l + (r-l)/2;
        if (psum[m] == targ) {
            return true;
        }
        if (psum[m] > targ) {
            r = m-1;
        }
        else {
            l = m+1;
        }
    }
    return false;
}

int main() {
    fast;
    int m, n;
    cin >> m >> n;
    vector<ll> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        ll q;
        cin >> q;

        vector<ll> psum(m+1, 0);
        for (int i = 0; i < m; ++i) {
            psum[i+1] = psum[i] + a[i];
        }

        bool found = false;
        for (int j = 0; j <= m; ++j) {
            if (bs(j, q, psum)) {
                found = true;
                break;
            }
            q -= a[a.size() - 1 - j];
        }

        if (found) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }

    }
}