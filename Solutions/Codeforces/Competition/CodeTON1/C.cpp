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
        bool one = false;
        bool zero = false;
        bool two = false;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 1) {
                one = true;
            }
            if (a[i] == 0) {
                zero = true;
            }
            if (a[i] == 2) {
                two = true;
            }
        }

        if (one) {
            sort(a.begin(), a.end());
            bool good = true;
            for (int i = 1; i < a.size(); ++i) {
                if (a[i] == a[i-1] + 1) {
                    good = false;
                    break;
                }
            }

            if (good)  {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }

        }
        else {
            cout << "YES" << endl;
        }
        


    }
}