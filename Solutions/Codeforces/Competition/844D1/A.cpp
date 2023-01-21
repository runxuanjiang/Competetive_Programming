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
        ll w, d, h;
        cin >> w >> d >> h;
        ll a, b, f, g;
        cin >> a >> b >> f >> g;

        ll res = a + f + abs(g - b);
        res = min(res, b + abs(f - a) + g);
        res = min(res, (w - a) + (w-f) + abs(g-b));
        res = min(res, (d - b) + abs(f-a) + (d-g));

        cout << res + h << endl;
    }
}