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
        ll c, m, x;
        cin >> c >> m >> x;

        x += abs(c-m);
        ll k = min(c, m);

        ll res = min(x, k);
        res += ((k - res) * 2) / 3;

        cout << res << endl;

    }
}