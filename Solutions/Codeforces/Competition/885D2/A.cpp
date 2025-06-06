//Competition #:
//Problem #: A
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
        ll n, m, k;
        cin >> n >> m >> k;

        ll x, y;
        cin >> x >> y;

        vector<pair<ll, ll>> coords;
        for (int i = 0; i < k; ++i) {
            ll a, b;
            cin >> a >> b;
            coords.push_back({a, b});
        }

        bool can_escape = true;
        for (auto i : coords) {
            if ((x + y) % 2 == (i.first + i.second) % 2) {
                can_escape = false;
            }
        }

        cout << (can_escape ? "YES" : "NO") << '\n';
    }
}