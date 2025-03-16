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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bitset<256> before, after;

        int res = 0;
        for (auto i : a) {
            res = max(i, res);
            after[i] = true;

            for (int j = 0; j < 256; ++j) {
                if (before[j]) {
                    res = max(i ^ j, res);
                    after[i^j] = true;
                }
            }

            swap(before, after);
            after.reset();
        }

        cout << res << endl;

        
    }
}