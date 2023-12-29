//Competition #:
//Problem #: C
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

        ll res = n * 4;
        ll loop = n*(n+1)/2 - n;
        res += loop;
        loop -= (n-1);
        res += loop;
        ++res;
        cout << res << endl;
    }
}