//Competition #:
//Problem #:
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
        ll n, x;
        cin >> n >> x;

        unordered_set<ll> res;

        if (n == 1) {
            cout << x << endl;
            continue;
        }

        ll tot = 0;
        for (ll i = 0; i + 1 < n; ++i) {
            tot ^= i;
            res.insert(i);
        }

        ll last = tot ^ x;
        if (res.find(last) == res.end() && last <= 500000) {
            res.insert(last);
        }
        else {
            for (auto i = res.begin(); i != res.end(); ++i) {
                if (*i != last) {
                    ll temp = *i + (1ll << 18);
                    res.erase(i);
                    res.insert(temp);
                    break;
                }
            }
            if (last > 500000) {
                res.insert(last - (1ll << 18));
            }
            else {
                res.insert(last + (1ll << 18));
            }
        }

        for (auto i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
}