//Competition #: round 266 Div 2 (466A)
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
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    if (b >= a*m) {
        cout << n * a << endl;
    }
    else {
        ll res = 0;
        res += (n / m) * b;
        res += min((n%m)*a, b);
        cout << res << endl;
    }
}