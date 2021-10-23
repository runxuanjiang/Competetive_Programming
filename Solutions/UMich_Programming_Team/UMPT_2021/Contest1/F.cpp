//Competition #:
//Problem #: F
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int n;

bool checkr(int m, const vector<ll> &b, const vector<ll> &rem) {
    for (int i = 0; m+i < n; ++i) {
        if (b[m+i] < rem[i]) {
            return false;
        }
    }
    return true;
}

bool checkl(int m, const vector<ll> &b, const vector<ll> &rem) {
    for (int i = m; i >= 0; --i) {
        if (b[i] > rem[n - (m-i) - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    fast;
    tests {
        cin >> n;
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        sort(b.begin(), b.end());

        vector<ll> rem;
        int bidx = 0;
        for (int i = 1; i <= 2*n; ++i) {
            if (i == b[bidx]) {
                ++bidx;
            }
            else {
                rem.push_back(i);
            }
        }

        int ridx = n, lidx = -1;

        int l = 0, r = n-1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (checkr(m, b, rem)) {
                ridx = m;
                r = m-1;
            }
            else {
                l = m+1;
            }
        }

        l = 0;
        r = n-1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (checkl(m, b, rem)) {
                lidx = m;
                l = m+1;
            }
            else {
                r = m-1;
            }
        }

        int res = max(0, lidx - ridx + 2);
        cout << res << endl;
    }
}