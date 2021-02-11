//Competition #:
//Problem #: C
//Accepted: Yes

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

        ll inv = n-k;

        for (int i = 1; i < k - inv; ++i) {
            cout << i << " ";
        }
        for (int i = k - inv; i <= k; ++i) {
            cout << 2*k - i - inv << " ";
        }
        cout << '\n';


    }
}