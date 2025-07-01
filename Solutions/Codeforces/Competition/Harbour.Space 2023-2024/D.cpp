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

        vector<bool> flipped(n, false), prevflipped(n, false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                
                bool shouldflip = prevflipped[j] ^ (matrix[i][j] == '1');
                bool shouldpropagate = prevflipped[j] ^ shouldflip;

                if (shouldflip) {
                    ++res;
                    cerr << "prevflipped[j] is " << prevflipped[j] << ", matrix[i][j] is " << matrix[i][j] << endl;
                    cerr << "Flipping at (" << i << ", " << j << ")" << endl;
                }

                if (shouldpropagate) {
                    if (j-1 >= 0) {
                        flipped[j-1] = !flipped[j-1];
                    }
                    flipped[j] = !flipped[j];
                    if (j+1 < n) {
                        flipped[j+1] = !flipped[j+1];
                    }
                }
                
            }
            swap(prevflipped, flipped);
            flipped.assign(n, false);
        }

        cout << res << endl;
    }
}