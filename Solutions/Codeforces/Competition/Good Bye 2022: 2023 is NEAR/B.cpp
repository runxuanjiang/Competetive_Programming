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
        ll n, m;
        cin >> n >> m;
        ll l = 1, r = n;
        bool first = true;
        while (l <= r) {
            if (first) {
                cout << r << " ";
                --r;
            }
            else {
                cout << l << " ";
                ++l;
            }
            first = !first;
        }
        cout << endl;
    }
}