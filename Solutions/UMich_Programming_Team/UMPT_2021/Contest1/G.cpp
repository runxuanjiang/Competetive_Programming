//Competition #:
//Problem #: G
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (a.front() == 1) {
            cout << n+1 << " ";
            for (int i = 1; i <= n; ++i) {
                cout << i << " ";
            }
            cout << endl;
        }

        else if (a.back() == 0) {
            for (int i = 1; i <= n+1; ++i) {
                cout << i << " ";
            }
            cout << endl;
        }

        else {
            for (int i = 0; i < n-1; ++i) {
                if (!a[i] && a[i+1]) {
                    for (int j = 0; j <= i; ++j) {
                        cout << j+1 << " ";
                    }
                    cout << n+1 << " ";
                    for (int j = i+1; j < n; ++j) {
                        cout << j+1 << " ";
                    }
                    cout << endl;
                    break;
                }
            }
        }
    }
}