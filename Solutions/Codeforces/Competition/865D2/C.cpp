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
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        if (n % 2) {
            cout << "YES" << endl;
        }
        else {
            for (int i = 1; i + 1 < n; ++i) {
                if (a[i] >= a[i-1]) {
                    ll diff = a[i] - a[i-1];
                    a[i] -= diff;
                    a[i+1] -= diff;
                }
                else {
                    if (i % 2) {
                        ll diff = a[i-1] - a[i];
                        a[i] += diff;
                        a[i+1] += diff;
                    }
                }
            }

            if (a[n-1] < a[n-2]) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
            }
        }



        
    }
}