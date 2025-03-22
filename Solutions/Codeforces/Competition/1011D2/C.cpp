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
        ll x_first_bit = __builtin_ctzll(x);
        ll x_last_bit = 63 - __builtin_clzll(x);
        ll y_first_bit = __builtin_ctzll(y);
        ll y_last_bit = 63 - __builtin_clzll(y);

        cerr << x_first_bit << " " << x_last_bit << " " << y_first_bit << " " << y_last_bit << endl;

        ll all_bits_populated_between_first_and_last_bit = 0;
        for (int i = min(x_first_bit, y_first_bit); i <= max(x_last_bit, y_last_bit); ++i) {
            if (checkbit(i, y)) {
                all_bits_populated_between_first_and_last_bit += (1ll << i);
            }
        }

        // cerr << all_bits_populated_between_first_and_last_bit << endl;

        res += all_bits_populated_between_first_and_last_bit;
        res += all_bits_populated_between_first_and_last_bit;

        cout << res << endl;



    }
}