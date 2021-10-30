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

int main() {
    fast;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> powers;
    ll i = 1;
    while (i < 100000000000) {
        i *= 2;
        powers.push_back(i);
    }
    // for (auto i : powers) {
    //     cout << i << endl;
    // }

    unordered_map<ll, int> mp;
    for (auto i : a) {
        if (mp.find(i) == mp.end()) {
            mp[i] = 0;
        }

        ++mp[i];
    }

    ll res = 0;
    for (auto i : a) {
        for (auto p : powers) {
            ll diff = p - i;
            if (diff == i) {
                if (mp.find(diff) != mp.end()) {
                    res += mp[diff] - 1;
                }
            }
            else {
                if (mp.find(diff) != mp.end()) {
                    res += mp[diff];
                }
            }
        }
    }

    cout << res/2 << endl;

    // int res = 0;
    // unordered_map<ll, ll> count;
    // for (auto i : a) {
    //     if (count.find(i) != count.end()) {
    //         res += count[i];
    //     }

    //     for (auto p : powers) {
    //         if (count.find(p - i) == count.end()) {
    //             count[p-i] = 0;
    //         }
    //         count[p-i]++;
    //     }
    // }


}