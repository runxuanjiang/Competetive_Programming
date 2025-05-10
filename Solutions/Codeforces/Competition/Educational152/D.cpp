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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll leading_zero = 0;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            ++leading_zero;
        }
        else {
            ++res;
            int j = i;
            ll max_num = a[i];
            while (j+1 < n && a[j+1] > 0) {
                ++j;
                max_num = max(max_num, a[j]);
            }

            if (leading_zero > 0) {
                res += leading_zero - 1;
            }
            if (max_num == 2 || leading_zero == 0) {
                leading_zero = -1;
            }
            else {
                leading_zero = 0;
            }
            i = j;
        }
    }

    if (leading_zero > 0) {
        res += leading_zero;
    }
    cout << res << endl;

}