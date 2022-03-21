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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int idx = 0;
    int res = 0;
    unordered_set<ll> seen;
    for (int i = 0; i < n; ++i) {
        while (seen.find(a[idx]) != seen.end()) {
            ++idx;
        }

        if (a[idx] == b[i]) {
            ++idx;
        }
        else {
            ++res;
            seen.insert(b[i]);
        }
    }

    cout << res << endl;
}