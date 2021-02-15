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
        int n;
        cin >> n;
        if (n == 2) {
            cout << 0;
        }
        else if (n%2 == 0) {
            for (int i = 0; i < n; ++i) {
                for (int j = i+1; j < n; ++j) {
                    if (i % 2 == 0 && j == i+1) {
                        cout << "0" << " ";
                    }
                    else {
                        if ((j - (i+1)) % 2 == 0) {
                            cout << 1 << " ";
                        }
                        else {
                            cout << -1 << " ";
                        }
                    }

                }
            }
        }
        else {
            for (int i = 0; i < n; ++i) {
                for (int j = i+1; j < n; ++j) {
                    if ((j -(i+1)) % 2 == 0) {
                        cout << 1 << " ";
                    }
                    else {
                        cout << -1 << " ";
                    }
                }
            }
        }
        cout << endl;

    }
}