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
        ll n, k;
        cin >> n >> k;
        ll mult = k / (n-1);
        ll rem = k % (n-1);
        if (rem == 0) {
            cout << n*mult - 1 << endl;
        }
        else {
            cout << n * mult + rem << endl;
        }


    }



}