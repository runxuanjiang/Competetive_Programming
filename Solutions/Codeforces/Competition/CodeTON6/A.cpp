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
        ll n, k, x;
        cin >> n >> k >> x;

        ll num_elements = 0;
        ll res = 0;

        if (k > n) {
            res = -1;
        }
        else {
            res = (k-1)*k/2;
            num_elements = k;
        }

        if (res != -1) {
            if (x < k-1) {
                res = -1;
            }
            else {
                res += (n-num_elements) * ((k == x) ? x-1 : x);
            }
        }

        cout << res << endl;
    }
}