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
        pair<ll, ll> acoords, bcoords, ccoords;
        cin >> acoords.first;
        cin >> acoords.second;
        cin >> bcoords.first;
        cin >> bcoords.second;
        cin >> ccoords.first;
        cin >> ccoords.second;

        ll res = 0;
        if (!((bcoords.first > acoords.first) ^ (ccoords.first > acoords.first))) {
            res += min(abs(bcoords.first - acoords.first), abs(ccoords.first - acoords.first));
        }

        if (!((bcoords.second > acoords.second) ^ (ccoords.second > acoords.second))) {
            res += min(abs(bcoords.second - acoords.second), abs(ccoords.second - acoords.second));
        }

        cout << res+1 << endl;





    }
}