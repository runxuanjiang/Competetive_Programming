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

ll res(ll a, ll b) {
    ll res = 0;
    while (a > 1) {
        a = (a+1)/2;
        ++res;
    }
    while (b > 1) {
        b = (b+1)/2;
        ++res;
    }
    return res;
}

int main() {
    fast;
    tests {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;


        cout << min(res(min(a, n-a+1), m), res(n, min(b, m-b+1))) + 1 << endl;

    }
}