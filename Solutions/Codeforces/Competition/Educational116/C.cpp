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

ll intpow(ll exp) {
    ll base = 1;
    for (ll i = 0; i < exp; ++i) {
        base *= 10;
    }
    return base;
}

int main() {
    fast;
    tests {
        int n;
        cin >> n;
        ll k;
        cin >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> m;
        for (int i = 0; i < n; ++i) {
            m.push_back(intpow(a[i]));
        }

        sort(m.begin(), m.end());

        bool done = false;

        ll curr = 0;

        for (int i = 0; i < n-1; ++i) {
            if (m[i] * k + curr < m[i+1] - 1) {
                done = true;
                cout << m[i] * (k+1) + curr << endl;
                break;
            }
            else {
                curr = m[i+1] - 1;
                k -= (m[i+1] / m[i] - 1);
            }
        }

        if (!done) {
            cout << m.back() * (k+1) + curr << endl;
        }
    }
}