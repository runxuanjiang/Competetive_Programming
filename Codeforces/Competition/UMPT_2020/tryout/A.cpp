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
    ll k, d;
    cin >> k >> d;
    for (int i = 0; i < d; ++i) {
        ll in;
        cin >> in;
        if (in < k) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << "awesome" << endl;
}