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
        ll x, y, n;
        cin >> x >> y >> n;

        vector<ll> a(n);
        ll diff = 1;
        a.back() = y;
        for (int i = n-2; i >= 0; --i) {
            a[i] = a[i+1] - diff;
            ++diff;
        }

        if (x <= a[0]) {
            a[0] = x;
            for (auto i : a) {
                cout << i << " ";
            }
            cout << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}