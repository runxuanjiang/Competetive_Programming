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

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> count(2*n+1, 0);

        ll mres = 0;
        count[0] = 1;
        int curr = 0;
        for (auto i : a) {
            curr ^= i;

            for (int j = 0; j * j <= 2 * n; ++j) {
                if ((curr ^ (j * j)) <= 2*n) {
                    mres += count[curr ^ (j * j)];
                }
            }
            ++count[curr];
        }

        cout <<  n * (n+1) / 2 - mres << endl;


    }
}