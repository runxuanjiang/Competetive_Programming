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
    ll n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    unordered_set<ll> sep;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end()) {
            mp[a[i]] = 1;
        }
        else {
            ++mp[a[i]];
            if (a[i] != a[i-1]) {
                sep.insert(a[i]);
            }
        }
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    int id = n-2;
    while (id >= 0 && a[id] == a[id+1]) {
        --id;
    }

    ll res = 0;
    for (int i = 0; i < id; ++i) {
        if (a[i] == a.back()) ++res;
    }

    for (auto i : mp) {
        if (i.first != a.back() && sep.find(i.first) != sep.end()) {
            res += i.second;
        }
    }

    cout << res << endl;
}