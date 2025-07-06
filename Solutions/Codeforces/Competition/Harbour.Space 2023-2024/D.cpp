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
    tests {
        ll n;
        cin >> n;

        vector<string> matrix(n);
        for (ll i = 0; i < n; ++i) {
            cin >> matrix[i];
        }

        ll res = 0;


        vector<bitset<3>> current(n, 0), next(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                bool flipped = current[j][0] ^ current[j][1] ^ current[j][2];
                bool propagate = false;
                if (flipped ^ (matrix[i][j] == '1')) {
                    ++res;
                    propagate = true;
                    // cerr << "Flipping at (" << i << ", " << j << ")" << endl;
                }


                if (j > 0 && (current[j][0] ^ propagate)) {
                    next[j-1][0] = true;
                }
                if (flipped ^ propagate) {
                    next[j][1] = true;
                }
                if (j+1 < n && (current[j][2] ^ propagate)) {
                    next[j+1][2] = true;
                }
            }

            swap(current, next);
            next.assign(n, 0);
        }

        cout << res << endl;
    }
}