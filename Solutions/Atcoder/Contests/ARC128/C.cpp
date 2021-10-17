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
    int n;
    cin >> n;
    ld m, s;
    cin >> m >> s;
    vector<ld> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    a = vector<ld>(a.rbegin(), a.rend());
    ld idx = -1;
    ld res = 0;


    while (s > 0) {
        ld maxavg = 0, maxidx = idx;
        ld sum = 0;
        for (int i = idx+1; i < a.size(); ++i) {
            sum += a[i];
            if (sum / (i - idx) >= maxavg) {
                maxavg = sum / (i - idx);
                maxidx = i;
            }
        }

        ld sub = min(s, m * (maxidx - idx));
        s -= sub;
        res += sub * maxavg;

        idx = maxidx;
    }

    cout << setprecision(20);
    cout << res << endl;

}