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
        ll a, b;
        cin >> a >> b;
        ll diff = abs(a - b);
        ll res = (diff % 10) ? 1 : 0;
        res += diff/10;
        cout << res << endl;
    }
}