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
        ll n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        int res;
        vector<int> amin = {a[0]};
        for (int i = 0; i < a.size(); ++i) {
            if (i > 0) {
                amin.push_back(min(a[i], amin.back()));
            }
            if (a[i] < b[0]) {
                res = i;
                break;
            }
        }

        int idx = (int) amin.size() - 1;
        int bmax = b[0];
        for (int i = 0; i < amin.size(); ++i) {
            bmax = max(bmax, b[i]);
            while (idx-1 >= 0 && amin[idx-1] < bmax) {
                --idx;
            }
            res = min(res, idx + i);
        }

        cout << res << endl;
    }
}