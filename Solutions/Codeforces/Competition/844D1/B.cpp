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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        ll res = 1;
        ll coming = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] <= coming) {
                ++coming;
            }
            else {
                if (a[i] <= i) {
                    ++res;
                    coming = i+1;
                }
            }
        }

        cout << res << endl;
    }
}