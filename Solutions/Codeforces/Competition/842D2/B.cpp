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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll curr = 1;
        for (auto i : a) {
            if (i == curr) {
                ++curr;
            }
        }

        ll rem = n - (curr - 1);


        if (rem % k == 0) {
            cout << rem/k << endl;
        }
        else {
            cout << 1 + rem/k << endl;
        }




    }
}