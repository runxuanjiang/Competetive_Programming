//Competition #:
//Problem #: D
//Accepted: 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

typedef
tree<
  ll,
  null_type,
  less<ll>,
  rb_tree_tag,
  tree_order_statistics_node_update>
set_t;

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

        ll res = 0;
        for (ll i = 1; i+1 <= n; ++i) {
            res += i * (n-i);
        }

        ll sub = 0;

        for (int i = 0; i < n; ++i) {
            int l = 1, r = 0;

            ll j = i;
            while (j+1 < n) {
                if (a[j+1] < a[i]) {
                    if (r) {
                        break;
                    }
                    else {
                        ++j;
                    }
                }
                else {
                    ++r;
                    ++j;
                }
            }

            j = i;
            while (j-1 >= 0 && a[j-1] < a[i]) {
                ++l;
                --j;
            }

            sub += l*r;
        }


        cout << res-sub << endl;
    }
}