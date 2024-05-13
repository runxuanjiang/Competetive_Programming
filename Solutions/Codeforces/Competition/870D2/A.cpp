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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        ll res = -1;
        if (a.back() == 0) {
            res = 0;
        }
        else if (a.front() == n) {
            res = -1;
        }
        else {
            for (int i = 1; i < n; ++i) {
                if (a[n-i] > i && a[n-i-1] <= i) {
                    res = i;
                    break;
                }
        }
        }


        cout << res << endl;


    }
}