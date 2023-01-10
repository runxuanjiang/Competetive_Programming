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
        ll n, x;
        cin >> n >> x;

        if ((n & x) != x) {
            cout << -1 << endl;
        }
        else {
            bitset<64> nb(n);
            bitset<64> xb(x);

            int one = -2;
            int zero = -2;
            bool good = true;
            for (int i = 0; i < 63; ++i) {
                if (nb[i] && xb[i]) {
                    if (zero == i-1) {
                        good = false;
                        break;
                    }
                    if (one == -2) {
                        one = i;
                    }
                }
                else if (nb[i] && !xb[i]) {
                    if (one != -2) {
                        good = false;
                        break;
                    }
                    zero = i;
                }

                if (!nb[i] && xb[i]) {
                    good = false;
                    break;
                }
            }

            if (good) {

                if (zero == -2) {
                    cout << n << endl;
                }
                else {
                    for (int i = 0; i <= zero; ++i) {
                        if (n & (1ll << i)) {
                            n ^= (1ll << i);
                        }
                    }
                    n |= (1ll << (zero+1));
                    cout << n << endl;
                }

            }
            else {
                cout << -1 << endl;
            }
        }

    }
}