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

void pf(ll num, unordered_map<ll, ll> &counts) {
    for (ll i = 2; i*i <= num; ++i) {
        if (num % i == 0) {
            if (counts.find(i) == counts.end()) {
                counts[i] = 0;
            }
            ++counts[i];
            return pf(num/i, counts);
        }
    }

    if (counts.find(num) == counts.end()) {
        counts[num] = 0;
    }
    ++counts[num];
}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        unordered_map<ll, ll> counts;
        for (auto i : a) {
            pf(i, counts);
        }

        ll res = 0;
        for (auto &i : counts) {
            res += (i.second / 2);
            i.second = (i.second % 2);
        }

        res += accumulate(begin(counts), end(counts), 0, 
            [](const ll prev, const pair<ll, ll> &p) { return prev + p.second;}) 
            / 3;

        cout << res << endl;


    }
}