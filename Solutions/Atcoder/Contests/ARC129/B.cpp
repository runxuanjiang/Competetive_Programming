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
    int n;
    cin >> n;
    multiset<ll> lefts, rights;
    for (int i = 0; i < n; ++i) {
        ll l, r;
        cin >> l >> r;
        lefts.insert(l);
        rights.insert(r);

        ll diff = max((*(--lefts.end()) - *(rights.begin()) + 1) / 2, 0ll);
        cout << diff << endl;
    }

    
}