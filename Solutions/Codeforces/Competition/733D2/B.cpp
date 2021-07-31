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
        int h, w;
        cin >> h >> w;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (i == 0 || i == h-1) {
                    if (j % 2 == 0) {
                    cout << 1;
                    }
                    else {
                        cout << 0;
                    }
                }
                else if (i % 2 == 0 && i != h-2 && (j == 0 || j == w-1)) {
                    cout << 1;
                }
                else {
                    cout << 0;
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}