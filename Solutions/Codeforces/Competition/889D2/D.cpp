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
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> reward(n);
    reward[0] = a[0];
    for (int i = 1; i < n; ++i) {
        reward[i] = a[i] + reward[i-1] - 1;
    }

    bitset<200000> possible;
    possible[0] = 1;

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        possible |= (possible << a[i]);
        if (possible[0]) {
            res = max(res, reward[i]);
        }
        possible >>= 1;
    }
    for (int i = 0; i < n; ++i) {
        if (possible[i]) {
            res = max(res, reward.back() - i - 1);
        }
    }
    cout << res << endl;

}