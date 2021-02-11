//Competition #:
//Problem #: C
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
    tests {
        ll n;
        cin >> n;
        vector<ll> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        ll res = 0;
        bool cont = false;
        for (int i = 1; i < n; ++i) {
            ll curr = abs(a[i] - b[i]) + 1;
            ll tempmax = curr + c[i];
            res = max(res, tempmax);

            while (i + 1 < n && a[i+1] != b[i+1]) {
                i = i+1;
                curr += min(a[i], b[i]) + (c[i-1] - max(a[i], b[i]) + 1);
                curr = max(curr, abs(a[i] - b[i]) + 1);
                tempmax = max(tempmax, curr + c[i]);
                res = max(res, tempmax);
            }
        }

        cout << res << endl;
    }
}