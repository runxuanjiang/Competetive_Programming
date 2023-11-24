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
    tests {
        ll n, k;
        cin >> n >> k;

        vector<pair<ll, ll>> segs(n);

        for (int i = 0; i < n; ++i) {
            cin >> segs[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> segs[i].second;
        }

        multiset<ll> csegs;
        ll tot = 0;
        ll res = -1;
        for (const auto &i : segs) {
            ll len = i.second - i.first + 1;
            tot += len;
            csegs.insert(len);
            if (tot >= k) {
                ll curres = 2 * csegs.size() + i.second - (tot - k);
                if (res == -1 || curres < res) {
                    res = curres;
                }
            }
            while (!csegs.empty() && tot - *csegs.begin() >= k) {
                tot -= *csegs.begin();
                csegs.erase(csegs.begin());

                ll curres = 2 * csegs.size() + i.second - (tot - k);
                if (res == -1 || curres < res) {
                    res = curres;
            }
            }

        }

        cout << res << endl;
    }
}