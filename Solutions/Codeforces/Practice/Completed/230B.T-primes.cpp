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

bool isprime(ll n) {
    if (n < 2) {
        return false;
    }
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    fast;
    ll n;
    cin >> n;

    for (ll i = 0; i < n; ++i) {
        ll num;
        cin >> num;

        if (floor(sqrt((double) num)) * floor(sqrt((double) num)) == num && isprime(floor(sqrt((double) num)))) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }


    }
}