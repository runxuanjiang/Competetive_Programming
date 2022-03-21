#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while (testCount--)

int main() {
    fast;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    stack<pair<ll, ll>> stk;
    ll res = 0;
    vector<ll> left(n), right(n);

    for (ll i = 0; i < n; ++i) {
        while (!stk.empty() && a[i] < stk.top().first) {
            pair<ll, ll> p = stk.top();
            stk.pop();
            right[p.second] = i;
        }
        stk.push({a[i], i});
    }
    while (!stk.empty()) {
        pair<ll, ll> p = stk.top();
        stk.pop();
        right[p.second] = n;
    }

    stk = stack<pair<ll, ll>>();
    for (ll i = n-1; i >= 0; --i) {
        while (!stk.empty() && a[i] < stk.top().first) {
            pair<ll, ll> p = stk.top();
            stk.pop();
            left[p.second] = i+2;
        }
        stk.push({a[i], i});
    }
    while (!stk.empty()) {
        pair<ll, ll> p = stk.top();
        stk.pop();
        left[p.second] = 1;
    }
    pair<ll, ll> best;
    for (ll i = 0; i < n; ++i) {
        if ((right[i] - left[i] + 1) * a[i] > res || (right[i] - left[i] + 1) * a[i] == res && left[i] < best.first) {
            res = (right[i] - left[i] + 1) * a[i];
            best = {left[i], right[i]};
        }
    }
    // for (auto i : left) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (auto i : right) {
    //     cout << i << " ";
        
    // }
    // cout << endl;
    if (!res) {
        cout << "1 1 0" << endl;
        return 0;
    }
    cout << best.first << " " << best.second << " " << res << endl;
}