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

bool checkbit(int bit, ll num) {
    return (num & (1LL << bit)) != 0;
}

int main() {
    fast;
    tests {
        ll x, y;
        cin >> x >> y;

        if (x == y) {
            cout << -1 << endl;
            continue;
        }

        ll res = 0;
        ll uneven_bit = 0;
        for (int i = 0; i < 40; ++i) {
            if (checkbit(i, x) && checkbit(i, y)) {
                ll add = (1ll << i);
                res += add;
                x += add;
                y += add;
            }
            else if (checkbit(i, x) ^ checkbit(i, y)) {
                uneven_bit = i;
            }
        }
    

        if (checkbit(40, x) && checkbit(40, y)) {
            // cerr << "uneven_bit: " << uneven_bit << endl;
            for (int i = uneven_bit; i < 40; ++i) {
                res += (1ll << i);
            }
        }
        cout << res << endl;


    }
}