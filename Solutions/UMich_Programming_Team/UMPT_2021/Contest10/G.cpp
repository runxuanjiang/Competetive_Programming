//Competition #:
//Problem #: G
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
    vector<pair<ll, ll>> b;
    for (int i = 0; i < n; ++i) {
        ll f1, f2;
        cin >> f1 >> f2;
        b.push_back({f1, f2});
    }

    sort(b.begin(), b.end());
 
    ll res = 1;
 
    vector<ll> dp(n, 1);
    map<ll, ll> beacons;
    beacons.insert({b[0].first, 0});
    for (int i = 1; i < n; ++i) {
        auto iter = beacons.lower_bound(b[i].first - b[i].second);
        if (iter == beacons.begin()) {
            dp[i] = 1;
        }
        else {
            dp[i] = 1 + dp[(--iter)->second];
        }
        res = max(res, dp[i]);
        beacons.insert({b[i].first, i});
    }

 
    cout << n - res << endl;
}