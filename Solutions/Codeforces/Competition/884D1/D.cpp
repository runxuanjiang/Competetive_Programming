//Competition #:
//Problem #: D
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

        for (int i = 1; i <= n+1; ++i) {
            if (n % i != 0) {
                for (int j = 0; j < n; ++j) {
                    int offset = j%i;
                    cout << (char) ('a' + offset);
                }
                cout << endl;

                break;
            }
        }
    }
}