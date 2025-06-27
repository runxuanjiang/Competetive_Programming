//Competition #:
//Problem #: C
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
        ll x;
        cin >> x;

        vector<ll> res = {x};
        ll sub = 1;
        while (sub < x) {
            if (x & sub) {
                x -= sub;
                res.push_back(x);
            }
            sub *= 2;
        }

        while (x > 1) {
            x /= 2;
            res.push_back(x);
        }


        cout << res.size() << endl;
        for (ll val : res) {
            cout << val << " ";
        }
        cout << endl;


    }
}