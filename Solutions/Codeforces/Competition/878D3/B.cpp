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
        ll n, k;
        cin >> n >> k;

        ll maxDesserts = (2ll << min(k-1, 32ll));
        cerr << "maxdesserts: " << maxDesserts << endl;
        cout << min(maxDesserts, n+1) << endl;
    }
}