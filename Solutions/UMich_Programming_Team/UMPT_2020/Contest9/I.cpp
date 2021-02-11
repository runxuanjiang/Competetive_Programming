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

int main() {
    fast;
    ll n;
    cin >> n;
    vector<ll> neg;
    vector<ll> pos;
    for (int i = 0; i < n; ++i) {
        ll in;
        cin >> in;
        if (in >= 0) {
            pos.push_back(in);
        }
        else neg.push_back(in);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<int>());

    if (!pos.empty() && !neg.empty()) {
        ll res = 0;
        for (auto i : pos) {
            res += i;
        }
        for (auto i : neg) {
            res -= i;
        }
        cout << res;
    }
    else if (!neg.empty()) {
        ll res = neg.front();
        for (int i = 1; i < neg.size(); ++i) {
            res -= neg[i];
        }
        cout << res;
    }
    else {
        if (pos.size() == 1) {
            cout << pos.front();
        }
        else {
            ll res = pos.front() * -1;
            for (int i = 1; i < pos.size(); ++i) {
                res += pos[i];
            }
            cout << res;
        }
    }


}