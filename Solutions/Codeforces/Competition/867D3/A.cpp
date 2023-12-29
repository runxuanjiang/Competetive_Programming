//Competition #:
//Problem #: A
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
        ll n, t;
        cin >> n >> t;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        ll best = -1;
        ll bestidx = -1;

        for (int i = 0; i < n; ++i) {
            if (i + a[i] <= t) {
                if (b[i] > best) {
                    best = b[i];
                    bestidx = i+1;
                }
            }
        }

        cout << bestidx << endl;
    }
}