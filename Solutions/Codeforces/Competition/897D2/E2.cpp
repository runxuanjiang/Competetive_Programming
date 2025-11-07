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
        ll n, k;
        cin >> n >> k;

        ll res = 0;
        ll curr = 0;

        ll rem = n-curr;
        while (rem >= k) {
            cout << "? " << curr+1 << endl;
            ll response;
            cin >> response;

            if (response == -1) {
                return 0;
            }

            res ^= response;
            curr += k;
            rem = n-curr;
        }

        if (rem > 0) {
            curr -= k;
            cout << "? " << curr + 1 + rem/2 << endl;
            ll response;
            cin >> response;
            if (response == -1) {
                return 0;
            }
            res ^= response;

            cout << "? " << curr + 1 + rem << endl;
            cin >> response;
            if (response == -1) {
                return 0;
            }
            res ^= response;
        }

        cout << "! " << res << endl;


        


    }
}