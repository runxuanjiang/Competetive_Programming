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

int testnum = 0;

int main() {
    fast;
    tests {
        ++testnum;
        cout << "Case #" << testnum << ": ";
        int n;
        cin >> n;
        set<int> bins;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                bins.insert(i);
            }
        }

        ll res = 0;

        for (int i = 0; i < n; ++i) {
            ll tempres = INT_MAX;
            auto j = bins.lower_bound(i);
            if (j != bins.end()) {
                tempres = min(tempres, abs((ll) *j - i));
            }
            if (j != bins.begin()) {
                --j;
                tempres = min(tempres, abs((ll) *j - i));
            }
            res += tempres;
        }
        cout << res << endl;
    }
}