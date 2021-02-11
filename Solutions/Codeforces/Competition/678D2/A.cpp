//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    tests{
        ll n, m;
        cin >> n >> m;

        ll tot = 0;
        for (int i = 0; i < n; ++i) {
            ll in;
            cin >> in;
            tot += in;
        }

        if (tot == m) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}