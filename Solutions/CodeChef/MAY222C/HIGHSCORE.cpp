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
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int res = a;
        res = max(res, b);
        res = max(res, c);
        res = max(res, d);
        cout<< res << endl;
    }
}