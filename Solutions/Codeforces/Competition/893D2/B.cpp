//Competition #:
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
    tests {
        ll n, m, d;
        cin >> n >> m >> d;

        vector<ll> s(m);
        for (ll i = 0; i < m; ++i) {
            cin >> s[i];
            --s[i];
        }

        ll cookies = 1;
        ll prev = 0;
        for (auto i : s) {
            if (i == 0) {
                continue;
            }
            ++cookies;
            ll dist = i - prev - 1;
            cookies += (dist/d);
            prev = i;
        }
        cookies += (n-1-prev)/d;

        ll max_saved = 0;
        vector<ll> res;

        for (int i = 0; i < m; ++i) {
            ll before, after;
            if (i == 0) {
                if (s[i] == 0) {
                    res.push_back(i);
                    continue;
                }
                before = 1 + (s[i] - 1)/d + (s[i+1] - s[i] - 1)/d;
                after = (s[i+1] - 1)/d;


            }
            else if (i == m-1) {
                before = 1 + (s[i] - s[i-1] - 1) / d + (n - 1 - s[i]) / d;
                after = (n - 1 - s[i-1]) / d;
            }
            else {
                before = before = 1 + (s[i] - s[i-1] - 1) / d + (s[i+1] - s[i] - 1)/d;
                after = (s[i+1] - s[i-1] - 1) / d;
            }

            // cerr << "i: " << i << " before: " << before << " after: " << after << endl;


            ll diff = before-after;
            if (diff > max_saved) {
                max_saved = diff;
                res = {i};
            }
            else if (diff == max_saved) {
                res.push_back(i);
            }

        }

        cout << cookies - max_saved << " " << res.size() << endl;





    }
}