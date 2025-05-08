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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<ll> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(),
            indices.end(),
            [&](const ll &i, const ll &j) {
                ll left = (a[i] % k == 0) ? k : a[i] % k;
                ll right = (a[j] % k == 0) ? k : a[j] % k;
                if (left == right) {
                    return i < j;
                }
                return left > right;
            }
        );

        for (auto i : indices) {
            cout << i+1 << " ";
        }
        cout << endl;

    }
}