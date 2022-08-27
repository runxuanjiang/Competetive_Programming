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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int idx = 0;
    int res = 0;
    for (int i = 0; i < a.size(); ++i) {
        while (idx < b.size() && b[idx] < a[i]-1) {
            ++idx;
        }

        if (idx < b.size() && abs(a[i] - b[idx]) <= 1) {
            ++res;
            ++idx;

        }
    }

    cout << res << endl;


}