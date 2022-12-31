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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        multiset<ll> ms;
        for (auto i : a) {
            ms.insert(i);
        }

        for (auto j : b) {
            ms.erase(ms.begin());
            ms.insert(j);
        }

        ll res = 0;
        for (auto i : ms) {
            res += i;
        }

        cout << res << endl;


    }
}