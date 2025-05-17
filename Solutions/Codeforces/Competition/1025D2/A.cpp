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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }


        bool good = true;
        bool has_lose = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                has_lose = true;

                if (i-1 >= 0 && a[i-1] == 0) {
                    good = false;
                    break;
                }
                if (i+1 < n && a[i+1] == 0) {
                    good = false;
                    break;
                }
            }
        }

        if (!has_lose) {
            good = false;
        }

        cout << (good ? "NO" : "YES") << '\n';
    }
}