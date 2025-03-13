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
        ll x, k, n;
        cin >> n >> k >> x;

        if (x != 1) {
            cout << "YES" << endl;
            cout << n << endl;
            for (int i = 0; i < n; ++i) {
                cout << 1 << " ";
            }
            cout << endl;
        }
        else {
            if (k == 1) {
                cout << "NO" << endl;
            }
            else if (k == 2) {
                if (n % 2 == 0) {
                    cout << "YES" << endl;
                    cout << (n/2) << endl;
                    for (int i = 1; i*2 <= n; ++i) {
                        cout << 2 << " ";
                    }
                    cout << endl;
                }
                else {
                    cout << "NO" << endl;
                }  
            }
            else {
                cout << "YES" << endl;
                if (n % 2 == 0) {
                    cout << (n/2) << endl;
                    for (int i = 1; i*2 <= n; ++i) {
                        cout << 2 << " ";
                    }
                    cout << endl;
                }
                else {
                    cout << 1 + ((n-3)/2) << endl;
                    cout << 3 << " ";
                    n -= 3;
                    for (int i = 1; i*2 <= n; ++i) {
                        cout << 2 << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
}