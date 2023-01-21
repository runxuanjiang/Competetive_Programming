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

    ll uptozero = 1;
    ll uptoone = (factorial[2*n] + factorial[2*n] - factorial[n]) % m;
    ll uptotwo = (factorial[2*n] * modinverse(factorial[n], m)) % m;
    uptotwo = (uptotwo * factorial[2*n]) % m;
    uptotwo = (uptotwo * 2) % m;
    ll intersection = 0;
    for (ll i = 0; i <= n; ++i) {
        ll num = factorial[n];
        num = (num * factorial[n]) % m;
        num = (num * factorial[2*n-i]) % m;
        num = (num * factorial[n]) % m;
        num = (num * factorial[n]) % m;

        ll denom = factorial[n - i];
        denom = (denom * factorial[i]) % m;
        denom = (denom * factorial[n-i]) % m;
        denom = (denom * factorial[i]) % m;
        denom = (denom * factorial[n-i]) % m;

        ll add = (modinverse(denom, m) * num) % m;
        intersection = (add + intersection) % m;
    }

    uptotwo = (uptotwo - intersection) % m;
    ll uptothree = factorial[3*n];

    ll res = 0;
    res = (res + uptoone - uptozero) % m;
    res = (res + 2 * (uptotwo - uptoone)) % m;
    res = (res + 3 * (uptothree - uptotwo)) % m;
    while (res < 0) {
        res += m;
    }
    cout << res << endl;

}