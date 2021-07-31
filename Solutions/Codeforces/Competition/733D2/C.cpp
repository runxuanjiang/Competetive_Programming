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

bool check(const vector<int> &a, const vector<int> &b, ll asum, ll bsum, int m) {
    ll asub = (int) a.size() + m;
    asub /= 4;
    ll bsub = max(0ll, asub - m);

    asum += (m * 100);
    if (asub > 0) {
        asum -= a[asub - 1];
    }
    if (bsub > 0) {
        bsum -= b[bsub - 1];
    }


    return (asum >= bsum);
}

int main() {
    fast;
    tests {
        ll n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll asum = a[0], bsum = b[0];


        for (int i = 1; i < n; ++i) {
            asum += a[i];
            bsum += b[i];
            a[i] += a[i-1];
            b[i] += b[i-1];
        }
        int res = 0;

        int l = 0, r = n+2;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (check(a, b, asum, bsum, m)) {
                res = m;
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        cout << res << endl;
    }
}