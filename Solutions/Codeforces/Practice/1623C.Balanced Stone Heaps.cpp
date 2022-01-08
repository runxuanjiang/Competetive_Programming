//Competition #:
//Problem #:
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
        vector<ll> heaps(n);
        ll l = MOD, r = 0;
        for (int i = 0; i < n; ++i) {
            cin >> heaps[i];
            l = min(l, heaps[i]);
            r = max(r, heaps[i]);
        }

        ll res = 0;

        while (l <= r) {
            
        }


        
    }
}