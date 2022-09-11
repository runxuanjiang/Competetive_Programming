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

    int test = 0;
    tests {
        ++test;
        cout << "Case #" << test << ": ";

        ll n;
        cin >> n;
        vector<ll> nx(n);
        vector<ll> ny(n);
        for (int i = 0; i < n; ++i) {
            cin >> nx[i];
            cin >> ny[i];
        }

        ll q;
        cin >> q;
        vector<ll> qx(q);
        vector<ll> qy(q);
        for (int i = 0; i < q; ++i) {
            cin >> qx[i];
            cin >> qy[i];
        }

        unordered_map<ll, ll> nxcount, nycount, qxcount, qycount;

        for (auto i : nx) {
            if (nxcount.find(i) == nxcount.end()) {
                nxcount[i] = 0;
            }
            ++nxcount[i];
        }
        for (auto i : ny) {
            if (nycount.find(i) == nycount.end()) {
                nycount[i] = 0;
            }
            ++nycount[i];
        }
        for (auto i : qx) {
            if (qxcount.find(i) == qxcount.end()) {
                qxcount[i] = 0;
            }
            ++qxcount[i];
        }
        for (auto i : qy) {
            if (qycount.find(i) == qycount.end()) {
                qycount[i] = 0;
            }
            ++qycount[i];
        }

        ll res = 0;
        for (auto i : nxcount) {
            for (auto j : qxcount) {
                res = (res + (i.second * j.second * (i.first - j.first) * (i.first - j.first)) ) % MOD;
            }
        }

        for (auto i : nycount) {
            for (auto j : qycount) {
                res = (res + (i.second * j.second * (i.first - j.first) * (i.first - j.first)) ) % MOD;
            }
        }

        cout << res << endl;

    }
}