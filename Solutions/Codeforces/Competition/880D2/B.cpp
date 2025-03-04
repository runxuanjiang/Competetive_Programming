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

int main() {
    fast;
    tests {
        ll n, k, g;
        cin >> n >> k >> g;

        ll total = k*g;
        ll maxLowball = (g-1)/2;
        if (maxLowball == 0) {
            cout << 0 << endl;
            continue;
        }
        ll lowBallCount = min(n-1, total / maxLowball);

        ll res = lowBallCount * maxLowball;
        total -= res;

        cerr << "res: " << res << endl;

        ll extra = total % g;
        if (extra >= (g+1)/2) {
            res -= (g - extra);
        }
        else {
            res += extra;
        }

        cout << res << endl;



    }

}