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

        vector<ll> p(n);
        for (ll i = 0; i < n; ++i) {
            cin >> p[i];
        }


        ll lowest = p[0];
        set<ll> wins;

        for (int i = 1; i < n; ++i) {
            if (p[i] < lowest) {
                lowest = p[i];
            }
            else {
                if (wins.empty() || wins.lower_bound(p[i]) == wins.begin()) {
                    wins.insert(p[i]);
                }
            }
        }

        cout << wins.size() << endl;







    }
}