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
        ll n, k;
        cin >> n >> k;
        if (n % 2 == 0) {
            cout << ((k-1) % n)+1 << endl;
        }
        else {
            ll m = (n-1)/2;
            ll steps = (k-1) % m;

            ll moves = (k-1) / m;

            ll res = moves*(m+1);
            res += steps;
            cout << res % n + 1 << endl;

        }
    }
}