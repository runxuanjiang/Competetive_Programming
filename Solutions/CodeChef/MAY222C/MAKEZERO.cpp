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

        int tot = 0;
        for (auto i : a) {
            tot |= i;
        }

        int res = 0;
        for (int i = 0; i <= 30; ++i) {
            if ((1 << i) & tot) {
                ++res;
            }
        }
        cout << res << endl;

    }
}