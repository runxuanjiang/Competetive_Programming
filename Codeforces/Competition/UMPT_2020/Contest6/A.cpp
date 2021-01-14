//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    ll n;
    cin >> n;

    cout << n << " ";
    while (n > 1) {
        for (int i = 2; i <= n; ++i) {
            if (n%i == 0) {
                n/=i;
                cout << n << " ";
                break;
            }
        }
    }
}