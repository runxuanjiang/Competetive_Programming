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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 0; i < k; ++i) {
        if (a[i] > 0) {
            ++res;
        }
    }

    for (int i = k; i < n; ++i) {
        if (a[i] > 0 && a[i] == a[k-1]) {
            ++res;
        }
    }
    cout << res << endl;
}