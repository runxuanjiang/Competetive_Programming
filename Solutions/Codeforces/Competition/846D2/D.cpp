//Competition #:
//Problem #: D
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
        ll cnt;
        cin >> cnt;

        if (!cnt) {
            cout << "! 0" << endl;
            continue;
        }
        else if (cnt == 1) {
            cout << "- 1" << endl;
            cin >> cnt;
            cout << "! " << (1ll << cnt) << endl;
        }
        else {
            ll res = 1;
            ll ones = cnt;
            cout << "- 1" << endl;
            cin >> cnt;
            while (ones > 1) {
                ll extra = cnt - ones + 1;
                cout << "- " << (1ll << extra) << endl;
                res += (1ll << extra);
                cin >> cnt;
                --ones;
            }

            cout << "! " << (1ll << cnt) + res - 1 << endl;


        }
    }
}