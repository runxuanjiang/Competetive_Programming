//Competition #:
//Problem #: H
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
    ll n;
    cin >> n;

    set<ll> res;
    res.insert(1);

    for (int i = 1; i*i <= n; ++i) {
        if (n%i==0) {
            res.insert((i-1) * n / 2 + i);
            res.insert((n /i - 1)*n / 2 + n/i);
        }
    }
    for (auto i : res) {
        cout << i << " ";
    }
}