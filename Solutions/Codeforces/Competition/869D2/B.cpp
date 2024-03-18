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
        ll n;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
        }
        else if (n % 2) {
            cout << -1 << endl;
        }
        else {
            for (int i = 2; i <= n; i+=2) {
                cout << i << " " << i-1 << " ";
            }
            cout << endl;
        }
    }
}