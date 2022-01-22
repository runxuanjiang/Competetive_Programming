//Competition #:
//Problem #: E
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
        ll n;
        cin >> n;
        bool turn = true;
        ll res = 0;
        while (n > 0) {
            if (n % 2) {
                if (turn) {
                    ++res;
                }
                --n;
            }
            else {
                if ((n/2) % 2 || (n/2) == 2) {
                    if (turn) {
                        res += (n/2);
                    }
                    n/=2;
                }
                else {
                    if (turn) {
                        ++res;
                    }
                    --n;
                }
            }
            turn = !turn;
        }

        cout << res << endl;
    }
}