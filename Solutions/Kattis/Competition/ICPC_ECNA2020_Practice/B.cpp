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
ld p, a, b, c, d;

ld price(ld k) {
    return p * (sin(a*k + b) + cos(c*k + d) + 2);
}

int main() {
    fast;

    int n;
    cin >> p >> a >> b >> c >> d;
    cin >> n;

    ld res = 0;
    ld high = price((ld) 1);
    for (ld i = 2; i <= n; ++i) {
        ld pr = price(i);
        res = max(res, high-pr);
        high = max(high, pr);
    }

    cout.precision(15);
    cout << res << '\n';


}