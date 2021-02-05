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
        ll n, b;
        cin >> n >> b;
        vector<ll> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        if (n == 1) {
            cout << -1 << endl;
        }
        else {
            for (int i = 1; i < n; ++i) {
                if (h[i] > h[i-1]) {
                    int j = i-1;
                    while (h[j] < h[j+1]) {
                        int k = j;
                        while (k >= 0 && h[k] < h[k+1]) {
                            ++h[k];
                            --b;
                            if (b <= 0) {
                                cout << k+1 << endl;
                                goto done;
                            }
                            --k;
                        }
                    }
                }
            }
            done: if (b > 0) {
                cout << -1 << endl;
            }
        }
    }
}