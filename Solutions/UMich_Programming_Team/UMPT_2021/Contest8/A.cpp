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
        int b, p, f;
        cin >> b >> p >> f;
        int h, c;
        cin >> h >> c;

        int res = 0;
        if (h > c) {
            int maxh = min(b/2, p);
            res += h*maxh;
            b -= 2*maxh;

            int maxf = min(b/2, f);
            res += c * maxf;
        }
        else {
            int maxf = min(b/2, f);
            res += c * maxf;
            b -= 2*maxf;

            int maxh = min(b/2, p);
            res += h * maxh;
        }

        cout << res << endl;
    }
}