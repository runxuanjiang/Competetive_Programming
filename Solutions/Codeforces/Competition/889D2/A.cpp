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
        vector<ll> p(n);
        for (ll i = 0; i < n; i++) {
            cin >> p[i];
        }

        ll unhappy = 0;
        for (int i = 0; i < n; ++i) {
            if (i+1 == p[i]) {
                ++unhappy;
            }
        }

        cout << (unhappy+1)/2 << endl;
    }
}