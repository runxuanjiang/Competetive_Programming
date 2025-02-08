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

        ll ub = a[0], lb = a[0];
        for (auto i : a) {
            ub = max(ub, i);
            lb = min(lb, i);
        }

        if (lb < 0) {
            cout << lb << endl;
        }
        else {
            cout << ub << endl;
        }
    }
}