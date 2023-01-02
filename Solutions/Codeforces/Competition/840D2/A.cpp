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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int ones = 0, zeros = 0;
        for (auto i : a) {
            for (int j = 0; j < 10; ++j) {
                if (i & (1 << j)) {
                    ones |= (1 << j);
                }
                else {
                    zeros |= (1 << j);
                }
            }
        }

        int lowest = 1023;
        cout << ones - (lowest ^ zeros) << endl;

        
    }
}