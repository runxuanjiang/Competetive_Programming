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
        vector<ll> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        vector<ll> positive_cost_right(n, 0);
        for (int i = n-2; i >= 0; --i) {
            if (a[i] >= a[i+1]) {
                positive_cost_right[i] = positive_cost_right[i+1] + 1;
            }
            else {
                positive_cost_right[i] = positive_cost_right[i+1];
            }
        }

        vector<ll> negative_cost_left(n, 1);
        for (int i = 1; i < n; ++i) {
            if (a[i] >= a[i-1]) {
                negative_cost_left[i] = negative_cost_left[i-1] + 1;
            }
            else {
                negative_cost_left[i] = negative_cost_left[i-1];
            }
        }

        // cerr << "positive_cost_right: ";
        // for (auto i : positive_cost_right) {
        //     cerr << i << " ";
        // }
        // cerr << endl;

        // cerr << "negative_cost_left: ";
        // for (auto i : negative_cost_left) {
        //     cerr << i << " ";
        // }
        // cerr << endl;

        ll res = min(positive_cost_right[0], negative_cost_left[n-1]);

        for (int i = 0; i+1 < n; ++i) {
            res = min(res, negative_cost_left[i] + positive_cost_right[i+1]);
        }

        cout << res << endl;







    }
}