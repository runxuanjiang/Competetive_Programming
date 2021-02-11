//Competition #: UM training 2020 Contest 9
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

    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            res.insert((1 + (n+1-i)) * (n/i) /2);
            res.insert((1 + n+1 - (n/i)) * (i) / 2);
        }
    }

    for (auto i : res) {
        cout << i << " ";
    }
}