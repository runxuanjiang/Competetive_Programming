//Competition #:
//Problem #: C
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
    tests {
        int n;
        cin >> n;
        vector<ll> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        vector<ll> cost1 = {c[0] * n};
        ll curr = c[0] * n;
        ll mincost = c[0];
        ll cnt = 1;
        for (int i = 2; i < c.size(); i+= 2) {
            curr -= mincost * (n - cnt);
            ++cnt;
            curr += c[i];
            mincost = min(mincost, c[i]);
            curr += mincost * (n - cnt);
            cost1.push_back(curr);
        }

        vector<ll> cost2 = {c[1] * n};
        curr = c[1] * n;
        mincost = c[1];
        cnt = 1;
        for (int i = 3; i < c.size(); i+= 2) {
            curr -= mincost * (n - cnt);
            ++cnt;
            curr += c[i];
            mincost = min(mincost, c[i]);
            curr += mincost * (n - cnt);
            cost2.push_back(curr);
        }

        ll cost = cost1[0] + cost2[0];
        for (int i = 0; i < cost2.size(); ++i) {
            cost = min(cost, cost1[i] + cost2[i]);
            if (i+1 < cost1.size()) {
                cost = min(cost, cost1[i+1] + cost2[i]);
            }
        }
        cout << cost << endl;
    }
}