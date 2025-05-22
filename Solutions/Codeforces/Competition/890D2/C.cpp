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

bool possible(ll target, ll moves, const vector<ll> &a) {
    for (int i = 0; i < a.size(); ++i) {
        ll used = 0;
        ll height = target;
        bool good = true;
        for (int j = i; j < a.size(); ++j) {
            if (a[j] >= height) {
                break;
            }
            else {
                if (j+1 == a.size()) {
                    good = false;
                    break;
                }
                else {
                    used += (height - a[j]);
                    --height;
                }
            }
        }

        if (good && used <= moves) {
            return true;
        }
    }
    return false;

    // for (ll i = 0; i < a.size(); ++i) {
    //     ll used = 0;
    //     ll height = a[i];
    //     ll current_target = target- i;

    //     if (a[i] < current_target) {
    //         if (i + 1 < a.size() && a[i+1] + 1 >= current_target && current_target - a[i] <= moves) {
    //             used = current_target - a[i];
    //             height = current_target;
    //         }
    //         else {
    //             continue;
    //         }
    //     }

    //     ll j = i;
    //     while (j-1 >= 0 && (a[j-1] >= height+1 || height + 1 - a[j-1]  + used <= moves)) {
    //         if (height+1 > a[j-1]) {
    //             used += (height+1 - a[j-1]);
    //             ++height;
    //         }
    //         else {
    //             height = a[j-1];
    //         }
    //         --j;
    //     }

    //     if (height >= target) {
    //         return true;
    //     }
    // }
    // return false;
}

int main() {
    fast;
    tests {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }


        ll l = 0, r = 200000001;
        ll res = 0;
        while (l <= r) {
            ll m = (l + r) / 2;
            if (possible(m, k, a)) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        cout << res << endl;
    }
}