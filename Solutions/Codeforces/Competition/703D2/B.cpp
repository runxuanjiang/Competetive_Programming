//Competition #:
//Problem #: B
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
        int n;
        cin >> n;

        vector<ll> x(n);
        vector<ll> y(n);

        for (int i = 0; i < n; ++i) {
            cin >> x[i];
            cin >> y[i];
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        ll res = (n % 2 == 0) ? (x[(n+1)/2] - x[(n-1)/2] + 1) : (1);
        res *= ((n%2 == 0) ? (y[(n+1)/2] - y[(n-1)/2] + 1) : (1));

        cout << res << '\n';
    }
}