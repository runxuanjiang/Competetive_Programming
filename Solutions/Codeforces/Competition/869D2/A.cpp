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
        ll n, k;
        cin >> n >> k;
        vector<string> op(n);
        for (int i = 0; i < n; ++i) {
            cin >> op[i];
        }

        vector<bool> good(n, true);
        for (int i = 0; i < k; ++i) {
            for (int j = 1; j < n; ++j) {
                if (op[0][i] != op[j][i]) {
                    good[j] = false;
                }
            }
        }

        cout << count(good.begin(), good.end(), true) << endl;

    }
}