//Competition #:
//Problem #: E
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

        ll plus = 0, minus = 0;
        ll res = 0;
        for (auto i : a) {
            if (i > 0) {
                plus += i;
                ll free = min(minus, i);
                i -= free;
                minus -= free;
                res += i;
            }
            else {
                i = -i;
                minus += i;
                ll free = min(plus, i);
                i -= free;
                plus -= free;
                res += i;
            }
        }

        cout << res << endl;


    }
}