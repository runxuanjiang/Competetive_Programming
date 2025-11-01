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
        vector<ll> a(n);
        for (ll &i : a) cin >> i;

        vector<ll> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&a](ll x, ll y) {
            return a[x] > a[y];
        });

        vector<ll> res(n);
        for (int i = 0; i < n; ++i) {
            res[indices[i]] = i+1;
        }

        for (auto i : res) {
            cout << i << " ";
        }
        cout << endl;






    }
}