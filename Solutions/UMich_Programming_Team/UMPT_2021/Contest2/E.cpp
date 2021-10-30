//Competition #:
//Problem #: E
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
    int n, q;
    cin >> n >> q;
    deque<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<ll, ll>> prev;
    ll m = *max_element(a.begin(), a.end());

    while (a[0] != m) {
        prev.push_back({a[0], a[1]});
        if (a[0] > a[1]) {
            swap(a[0], a[1]);
        }
        a.push_back(a[0]);
        a.pop_front();
    }

    while (q--) {
        ll m;
        cin >> m;

        if (m <= prev.size()) {
            cout << prev[m-1].first << " " << prev[m-1].second << endl;
        }
        else {
            m -= (prev.size());
            m -= 1;
            m %= (n-1);
            cout << a[0] << " " << a[m+1] << endl;
        }

    }
}