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

ll power(ll base, ll p) {
    if (!p) return 1;
    if (p == 1) return base;

    ll tmp = power(base, p/2);
    if (p%2 == 0) return tmp*tmp;
    return base*tmp*tmp;
}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> count(7, 0), next(7, 0);
        for (int i = 0; i < n; ++i) {
            ll len = to_string(a[i]).size();
            for (int j = 0; j < 7; ++j) {
                ll index = (power(10ll, len) * j + a[i]) % 7;
                next[index] = (count[index] + count[j]) % MOD;
            }

            next[a[i] % 7]++;

            count = next;
        }

        cout << count[0] << endl;



    }
}