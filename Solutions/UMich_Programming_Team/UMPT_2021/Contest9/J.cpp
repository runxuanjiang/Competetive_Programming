//Competition #:
//Problem #: I
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ll calc(int i, ll mult, const vector<ll> &a, vector<ll> &dp) {
    cout << i << " " << mult << " " << endl;
    int l = 1, r = a.size() - i - 1;
    int res = 0;
    while (l <= r) {
        int m = l + (r-l)/2;
        if ((i + m-1 == i || (a[i + m]*mult + dp[i + m]) < (a[i + m-1]*mult + dp[i+m-1])) && (i + m+1 == a.size() || (a[i + m]*mult + dp[i + m]) < (a[i + m+1]*mult + dp[i+m+1]))) {
            res = a[i+m]*mult + dp[i+m];
            break;
        }
        else if ((i + m-1 == i || (a[i + m]*mult + dp[i + m]) < (a[i + m-1]*mult + dp[i+m-1]))) {
            l = m+1;
        }
        else {
            r = m-1;
        }
    }
    return res;
}

int main() {
    fast;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<ll> dp(n, 0);
    for (int i = n-2; i >= 0; --i) {
        dp[i] = calc(i, b[i], a, dp);
    }
    for (auto i : dp) {
        cout << i << " ";
    }
    cout << endl;
    cout << dp[0] << endl;

}