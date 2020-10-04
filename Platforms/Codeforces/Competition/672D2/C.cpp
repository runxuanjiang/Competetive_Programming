//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const ll MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    tests{
        ll n, x;
        cin >> n >> x;
        ll infected = 0;
        ll sum = 0;
        for (ll i = 0; i < n; ++i) {
            ll rating;
            cin >> rating;
            if (rating == x) ++infected;
            sum += rating;
        }

        if (infected == n) {
            cout << 0 << endl;
        }
        else if (sum == x*n || infected > 0) {
            cout << 1 << endl;
        }
        else {
            cout << 2 << endl;
        }
    }
}