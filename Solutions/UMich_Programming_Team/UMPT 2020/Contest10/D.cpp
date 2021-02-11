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

ll compare(string a, string b) {
    if (a.length() != b.length()) return -1;
    for (int i = 0; i < a.length(); ++i) {
        bool found = true;
        for (int j = 0; j < a.length(); ++j) {
            if (a[j] != b[(i + j) % a.length()]) {
                found = false;
                break;
            }
        }
        if (found) return i;
    }

    return -1;
}

int main() {
    fast;
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll res = INT_MAX;
    for (int i = 0; i < n; ++i) {
        ll ans = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                ll diff = compare(a[i], a[j]);
                if (diff == -1) {
                    cout << -1;
                    return 0;
                }
                else {
                    ans += diff;
                }
            }
        }
        res = min(res, ans);
    }
    

    cout << res;


}