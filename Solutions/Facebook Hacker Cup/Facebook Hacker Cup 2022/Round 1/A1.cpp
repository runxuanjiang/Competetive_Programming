//Competition #:
//Problem #:
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

    int test = 0;
    tests {
        ++test;
        cout << "Case #" << test << ": ";

        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        vector<ll> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        ll rotations = -1;
        for (int i = 0; i < b.size(); ++i) {
            if (b[i] == a[0]) {
                rotations = i;
                break;
            }
        }

        bool good = true;

        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[(i + rotations) % a.size()]) {
                good = false;
            }
        }

        if (n == 2) {
            if (k % 2 == 0) {
                if (rotations == 1) {
                    good = false;
                }
            }
            else {
                if (rotations == 0) {
                    good = false;
                }
            }
        }
        else {
            if (k == 0) {
                if (rotations != 0) {
                    good = false;
                }
            }
            else if (k == 1) {
                if (rotations == 0) {
                    good = false;
                }
            }
        }

        if (!good) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }

    }
}