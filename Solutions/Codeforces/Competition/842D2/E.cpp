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

ll modinverse(ll num, ll m) {
    ll m0 = m;
    ll y = 0, x = 1;
    while (num > 1) {
        ll q = num / m;
        ll t = m;

        m = num % m;
        num = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0) {
        x += m0;
    }

    return x;
}

int main() {
    fast;
    ll n, m;
    cin >> n >> m;

    vector<ll> factorial(3*n + 1);
    factorial[0] = 1;
    for (ll i = 1; i <= 3*n; ++i) {
        factorial[i] = (factorial[i-1] * i) % m;
    }

    ll zero = 1;
    ll one = (2 * (factorial[2*n] - 1) + m) % m;
    ll two = 0;
    for (ll i = 1; i <= n; ++i) {
        ll numerator = factorial[n];
        numerator = (numerator * factorial[n]) % m;
        numerator = (numerator * factorial[n]) % m;
        numerator = (numerator * factorial[n]) % m;
        numerator = (numerator * factorial[2*n-i]) % m;

        ll denominator = factorial[i];
        denominator = (denominator * factorial[n-i]) % m;
        denominator = (denominator * factorial[i]) % m;
        denominator = (denominator * factorial[n-i]) % m;
        denominator = (denominator * factorial[n-i]) % m;

        cout << denominator << " " << modinverse(denominator, m) << endl;

        ll add = (numerator * modinverse(denominator, m)) % m;
        two = (two + add) % m;
    }
    two = (two * 2) % m;

    ll three = (factorial[3*n] - zero - one - two) % m;
    while (three < 0) {
        three += m;
    }

    ll res = one;
    res = (res + 2 * two) % m;
    res = (res + 3 * three) % m;
    cout << zero << " " << one << " " << two << " " << three << endl;
    cout << res << endl;

}