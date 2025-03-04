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
        vector<ll> count(101, 0);
        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            count[x]++;
        }

        bool good = true;
        for (int i = 1; i < 101; ++i) {
            if (count[i] > count[i-1]) {
                good = false;
                break;
            }
        }

        cout << (good ? "YES" : "NO") << endl;


    }
}