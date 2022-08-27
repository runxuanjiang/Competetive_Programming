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

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll res = 0;

        unordered_map<ll, ll> last;

        for (ll i = 0; i < n; ++i) {
            if (last.find(a[i]) == last.end()) {
                last[a[i]] = 0;
            }
            ll l = max(last[a[i]], i - a[i] + 1);
            ll r = min(i, n-a[i]);
            res += max(r-l+1, 0ll);
            last[a[i]] = i + 1;
        }

        cout << res << endl;



    }
}