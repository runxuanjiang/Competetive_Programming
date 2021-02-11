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
    ll n, x, y;
    cin >> n >> x >> y;


    ll white = min(x-1, y-1) + abs(x-y);
    ll black = min(n-x, n-y) + abs(x-y);

    if (black < white) {
        cout << "Black";
    }
    else {
        cout << "White";
    }
}