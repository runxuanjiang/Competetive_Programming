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
    tests {
        ll n;
        cin >> n;
        vector<ll> c(n);
        for (ll& x : c) cin >> x;
        ll k;
        cin >> k;


        vector<ll> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&c](ll &l, ll &r) {
            if (c[l] == c[r]) {
                return l > r;
            }
            return c[l] < c[r];
        });

        vector<ll> res(n, 0);
        ll idx = indices.front();
        res[idx] = k/c[idx];
        ll cost = res[idx] * c[idx];

        for (auto i : indices) {
            if (i <= idx) {
                continue;
            }

            ll extra_price=c[i]-c[idx];
            ll rem = k-cost;
            ll num_switch = min(rem / extra_price, res[idx]);

            res[i] = num_switch;
            res[idx] -= num_switch;

            idx = i;
            cost += num_switch * extra_price;
        }

        vector<ll> res2(n, 0);
        ll tot = 0;
        for (int i = n-1; i >= 0; --i) {
            tot += res[i];
            res2[i] = tot;
        }

        for (auto i : res2) {
            cout << i << " ";
        }
        cout << endl;









    }
}