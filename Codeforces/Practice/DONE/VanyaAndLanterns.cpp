//Competition #: Round 280 D2 (492B)
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
    ll n, l;
    cin >> n >> l;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ld res = 0;
    for (int i = 1; i < a.size(); ++i) {
        res = max(res, ((ld) a[i] - (ld) a[i-1]) / 2);
    }
    
    res = max(res, (ld) a.front() - 0);
    res = max(res, (ld) l - (ld) a.back());

    cout <<fixed << res << '\n';
}