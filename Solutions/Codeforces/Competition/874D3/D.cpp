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
        vector<ll> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        if (p[0] == n) {
            ll j = n-1;
            while (j >= 0) {
                --j;

                if (p[j+1] == n-1) {
                    break;
                } 
            }
            for (int i = j+1; i < n; ++i) {
                cout << p[i] << " ";
            }

            if (j >= 0 && j < n-2) {
                cout << p[j] << " ";
                --j;
            }
            for (int i = 0; i <= j; ++i) {
                cout << p[i] << " ";
            }
            cout << endl;
        }
        else {
            ll j = n-1;
            while (j >= 0) {
                --j;

                if (p[j+1] == n) {
                    break;
                } 
            }
            for (int i = j+1; i < n; ++i) {
                cout << p[i] << " ";
            }
            ll lo = p[0];

            if (j >= 0 && j < n-2) {
                cout << p[j] << " ";
                --j;
            }

            while (j >= 0 and p[j] >= lo) {
                cout << p[j] << " ";
                --j;

            }

            for (int i = 0; i <= j; ++i) {
                cout << p[i] << " ";
            }
            cout << endl;
        }


    




    }
}