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

        bool good = true;

        sort(a.begin(), a.end());

        if (a[0] <= 0) {
            good = false;
        }
        if (a[0] % 2 == 0) {
            for (auto i : a) {
                if (i % 2 == 1) {
                    good = false;
                }
            }
        }
        cout << (good ? "YES" : "NO") << endl;



    }
}