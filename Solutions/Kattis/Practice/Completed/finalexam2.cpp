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
    vector<char> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> ans[i];
    }

    int res = 0;

    for (int i = 1; i < n; ++i) {
        if (ans[i] == ans[i-1]) ++res;
    }
    cout << res << endl;
}