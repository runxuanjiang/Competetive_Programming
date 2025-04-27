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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        if (a[0] != 1) {
            cout << 1 << endl;
        }
        else {
            ll res = k;
            for (int i = 1; i < n; ++i) {
                if (res+1 < a[i]) {
                    break;
                }

                ll prev_occurrences = 0;
                ll occurrences = ((res - a[i]) / (i+1)) + 1;
                while (occurrences - prev_occurrences > 0) {
                    res += (occurrences - prev_occurrences);
                    prev_occurrences = occurrences;
                    occurrences = ((res - a[i]) / (i+1)) + 1;
                }

                if ((res+1 - a[i]) % (i+1) == 0) {
                    ++res;
                }
                // cerr << "res after processing element " << a[i] << " is " << res << endl;
            }
            cout << res+1 << endl;

        }




    }
}