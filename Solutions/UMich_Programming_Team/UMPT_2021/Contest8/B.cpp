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
    int n;
    cin >> n;
    vector<ll> a(2*n);

    for (int i = 0 ; i < 2*n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) {
        sum1 += a[i];
    }
    for (int i = n; i < 2*n; ++i) {
        sum2 += a[i];
    }

    if (sum1 == sum2) {
        cout << -1;
        return 0;
    }

    for (auto i : a) {
        cout << i << " ";
    }
}