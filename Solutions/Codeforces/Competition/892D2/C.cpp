//Competition #:
//Problem #: C
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

        ll res = 0;

        for (int i = 0; i <= n; ++i) {
            vector<ll> products;
            for (int j = 1; j <= i; ++j) {
                products.push_back(j*j);
            }
            ll curr = n;
            for (int j = i+1; j <= n; ++j) {
                products.push_back(j*curr);
                --curr;
            }

            sort(products.begin(), products.end());
            ll curres = 0;
            for (int j = 0; j+1 < products.size(); ++j) {
                curres += products[j];
            }

            res = max(res, curres);
        }

        cout << res << endl;
    }
}