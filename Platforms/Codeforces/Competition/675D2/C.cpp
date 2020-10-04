//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ll pwr(ll p) {
    ll base = 10;
    ll result = 1;
    while (p > 0) {
        if (p & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        p >>=1;
    }
    return result;
}

int main() {
    fast;
    string input;
    cin >> input;
    ll res = 0;
    vector<ll> left(input.length(), 0);
    vector<ll> right(input.length(), 0);
    ll leftstart = 1;
    ll rightstart = 1;
    for (int i = 1; i < input.length(); ++i) {
        left[i] = (leftstart * pwr(input.length() - 1 - i)) % MOD ;
        right[input.length() - 1 - i] = rightstart;

        leftstart = (leftstart + i+1) % MOD;
        rightstart = (rightstart + (i+1) * pwr(i)) % MOD;
    }

    for (int i = 0; i < input.length(); ++i) {
        ll digit = (ll) (input[i] - '0');
        // cout << digit << " " << left[i] << " " << right[i] << endl;
        res += (digit * ((left[i] + right[i]) % MOD)) % MOD;
        res %= MOD;

    }

    cout << res % MOD;
}