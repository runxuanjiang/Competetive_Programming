//Competition #:
//Problem #: B
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
        int n, k;
        cin >> n >> k;
        vector<ll> p(n);
        vector<ll> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        s[0] = p[0];
        for (int i = 1; i < n; ++i) {
            s[i] = p[i] + s[i-1];
        }


        ll start = p[0];
        ll res = 0;
        for (int i = 1; i < n; ++i) {
            if ((ld) p[i] / ((ld) s[i-1] + (ld) res) > (ld) k / 100) {
                ld newN = (100 * (ld) p[i] / (ld) k);
                res += ceil(newN - (ld) s[i-1] - res);
            }
        }

        cout << res << endl;

    }
}