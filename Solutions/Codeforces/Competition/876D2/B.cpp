//Competition #:
//Problem #: B
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

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cin >> b[i];
        }


        unordered_map<ll, vector<ll>> m;
        for (int i = 0; i < n; ++i) {
            m[a[i]].push_back(b[i]);
        }

        ll res = 0;
        for (auto &e : m) {
            sort(e.second.begin(), e.second.end(), greater<ll>());
            for (int i = 0; i < e.second.size() && i < e.first; ++i) {
                res += e.second[i];
            }
        }


        cout << res << endl;
    }
}