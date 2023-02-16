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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll res = 0;
        res += a;

        ll curr = a;

        if (curr) {
            ll two = min(b, c);
            res += 2*two;
            b-= two;
            c-= two;

            ll three = max(b, c);
            ll add = min(three, curr);
            res += add;
            curr -= add;
            three -= add;

            if (curr) {
                ll final = min(curr, d);
                res += final;
                curr -= final;
                d -= final;
            }

            if (three || d) {
                ++res;
            }
            cout << res << endl;
        }
        else {
            if (b || c || d) {
                cout << res+1 << endl;
            }
            else {
                cout << res << endl;
            }
        }

    }
}