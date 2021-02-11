//Competition #:
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
    tests {
        ll n, a, b;
        cin >> n >> a >> b;

        ll res = 0;
        res += min((n/2)*b, (n/2)*2*a);
        res += (n%2) * a;
        cout << res << endl;
    }
}