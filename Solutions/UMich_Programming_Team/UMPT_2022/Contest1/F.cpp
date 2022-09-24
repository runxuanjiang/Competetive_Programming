//Competition #:
//Problem #: F
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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> ba(n);
    for (int i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        ba[i] = {b, a};
    }

    sort(ba.begin(), ba.end());

    ll bought = 0;
    ll r = n-1;
    ll res = 0;

    for (ll i = 0; i < n; ++i) {

        if (bought < ba[i].first) {
            while (r > i) {
                ll diff = ba[i].first - bought;
                if (diff <= ba[r].second) {
                    ba[r].second -= diff;
                    res += 2 * diff;
                    bought += diff;
                    break;
                }
                else {
                    res += 2 * ba[r].second;
                    bought += ba[r].second;
                    --r;
                }
            }
        }

        if (i == r) {
            ll diff = ba[i].first - bought;

            if (diff >= 0) {
                if (diff >= ba[i].second) {
                    res += 2 * ba[i].second;
                }
                else {
                    res += 2 * diff;
                    res += (ba[i].second - diff);
                }
            }
            else {
                res += ba[i].second;
            }


            break;
        }

        res += ba[i].second;
        bought += ba[i].second;


    }

    cout << res << endl;
}