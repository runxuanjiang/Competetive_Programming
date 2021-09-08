//Competition #: 1151
//Problem #: C
//Accepted: Yes

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

ull arithmeticSum(ull lo, ull hi) {
    ull mid = lo + (hi - lo) / 2;
    ull count = 1 + (hi - lo) / 2;
    mid = (mid % MOD);
    count = (count % MOD);
    return ((mid * count) % MOD);
}

int main() {
    fast;
    ull max = 4000000000000000000ULL;

    vector<ull> ids;
    vector<pair<ull, ull>> vals;

    ull i = 1, oddcurr = 1, evencurr = 2;
    ull tot = 1;
    bool odd = true;
    while (tot <= max) {
        ids.push_back(tot);
        if (odd) {
            vals.push_back({oddcurr, oddcurr - 2 + 2*i});
            oddcurr += 2*i;
        }
        else {
            vals.push_back({evencurr, evencurr - 2 + 2*i});
            evencurr += 2*i;
        }
        i *= 2;
        tot += i;
        odd = !odd;
    }

    ull l, r;
    cin >> l >> r;

    ull start = lower_bound(ids.begin(), ids.end(), l) - ids.begin();
    ull end = lower_bound(ids.begin(), ids.end(), r) - ids.begin();
    
    ull res = 0;
    if (start == end) {
        ull low = vals[start].second - 2*(ids[start] - l);
        ull high = vals[start].second - 2*(ids[start] - r);
        res = (res + arithmeticSum(low, high)) % MOD;
    }
    else {
        for (ull i = start; i <= end; ++i) {
            if (i == start) {
                ull low = vals[i].second - 2 * (ids[i] - l);
                ull high = vals[i].second;
                res = (res + arithmeticSum(low, high)) % MOD;
            }
            else if (i == end) {
                ull low = vals[i].first;
                ull high = vals[i].second - 2*(ids[i] - r);
                res = (res + arithmeticSum(low, high)) % MOD;
            }
            else {
                ull low = vals[i].first;
                ull high = vals[i].second;
                res = (res + arithmeticSum(low, high)) % MOD;
            }
        }
    }


    cout << res << endl;

}