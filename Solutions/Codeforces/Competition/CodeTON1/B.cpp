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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        unordered_set<ll> seen;
        bool done = false;
        for (auto i : a) {
            if (seen.find(i) != seen.end()) {
                done = true;
                break;
            }
            seen.insert(i - k);
            seen.insert(k + i);
        }

        if (done) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}