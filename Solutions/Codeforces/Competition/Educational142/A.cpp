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
        ll n;
        cin >> n;
        vector<ll> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        ll ones = 0;
        for (auto i : h) {
            if (i == 1) {
                ++ones;
            }
        }

        if (ones % 2) {
            --ones;
        }

        cout << (n - ones/2) << endl;
    }
}