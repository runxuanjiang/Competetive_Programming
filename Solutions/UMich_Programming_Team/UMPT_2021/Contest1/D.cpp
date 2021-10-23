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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int res = 1;
    for (int i = 0; i < k; ++i) {
        res = a[i];
    }

    if (a[k] == res) {
        cout << -1 << endl;
    }
    else {
        cout << res << endl;
    }


}