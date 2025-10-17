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
        ll n;
        cin >> n;

        vector<ll> p(n);
        for (ll &i : p) cin >> i;

        vector<ll> num_to_index(n+1);

        for (int i = 0; i < n; ++i) {
            num_to_index[p[i]] = i;
        }

        ll res = 0;
        for (int i = 2; i <= n; ++i) {
            if (num_to_index[i] < num_to_index[i-1]) {
                ++res;
            }
        }

        cout << res << endl;





    }
}