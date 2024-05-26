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
        int n, m;
        cin >> n >> m;

        int left = 0, right = 0;
        unordered_set<int> locs;
        for (int i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            if (a == -1) {
                ++left;
            }
            else if (a == -2) {
                ++right;
            }
            else {
                locs.insert(a);
            }
        }

        int rem = m - locs.size();
        int res = locs.size() + min(rem, max(left, right));

        vector<int> l(locs.begin(), locs.end());
        sort(l.begin(), l.end());
        for (int i = 0; i < l.size(); ++i) {
            int cres = locs.size();
            cres += min(left, l[i] - 1 - i);
            cres += min(right, m - l[i] - ((int) l.size() - i - 1));
            res = max(res, cres);
        }
        cout << res << endl;




    }
}