//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k, garbage;
        cin >> n >> k;
        vector<ll> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        for (int i = 0; i < n; ++i) cin >> garbage;

        if (n == 1) {
            cout << 1 << endl;
        }
        else {
            sort(x.begin(), x.end());
            ll res1 = 0, res2 = 0, res3 = 0;
            vector<ll>::iterator pos1, pos2;
            

            for (auto i = x.begin(); i != x.end(); ++i) {
                auto ub = upper_bound(x.begin(), x.end(), *i + k);
                ll max = (ub == x.end()) ? x.size() - (i - x.begin()) : ub - i;
                if (max > res1) {
                    res1 = max;
                    pos1 = i;
                    pos2 = ub;
                }
            }

            vector<ll> y(x.begin(), x.end());
            x.erase(pos1, pos2);

            for (auto i = x.begin(); i != x.end(); ++i) {
                auto ub = upper_bound(x.begin(), x.end(), *i + k);
                ll max = (ub == x.end()) ? x.size() - (i - x.begin()) : ub - i;
                if (max > res2) {
                    res2 = max;
                }
            }

            for (auto i = y.begin(); i != y.end(); ++i) {
                auto ub = upper_bound(y.begin(), y.end(), *i + k);
                ll max = (ub == y.end()) ? y.size() - (i - y.begin()) : ub - i;
                if (max > res3) {
                    res3 = max;
                }
            }

            cout << max(res1+res2, res3) << endl;
        }

    }
}