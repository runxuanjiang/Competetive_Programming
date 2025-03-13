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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        ll res = 0;
        vector<ll> diffs;
        for (int i = 1; i < a.size(); ++i) {
            ll diff = abs(a[i] - a[i-1]);
            diffs.push_back(diff);
            res += diff;
        }

        sort(diffs.begin(), diffs.end(), greater<ll>());

        for (int i = 0; i+1 < k; ++i) {
            res -= diffs[i];
        }
        cout << res << endl;
    }
}