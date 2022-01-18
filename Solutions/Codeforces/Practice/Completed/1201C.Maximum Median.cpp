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

int main() {
    fast;
    int n;
    cin >> n;
    ll k;
    cin >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll cnt = 0;
    ll res = a[(int) a.size() / 2];
    for (int i = (a.size() / 2); i < a.size(); ++i) {
        ++cnt;
        while (i+1 < a.size() && a[i+1] == a[i]) {
            ++i;
            ++cnt;
        }

        if (i+1 < a.size()) {
            ll diff = (a[i+1] - a[i]) * cnt;
            if (k > diff) {
                res = a[i+1];
                k -= diff;
            }
            else {
                res += (k/cnt);
                break;
            }
        }
        else {
            res += (k/cnt);
            break;
        }
    }

    cout << res << endl;
}