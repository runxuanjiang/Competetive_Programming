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
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> count(m+1);
        vector<vector<ll>> div(n);
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); ++i) {
            for (ll j = 1; j*j <= a[i]; ++j) {

                if (a[i] % j == 0) {
                    ll div1 = j;
                    ll div2 = a[i] / j;
                    if (div1 <= m) {
                        count[div1]++;
                        div[i].push_back(div1);
                    }
                    if (div2 <= m && div2 != div1) {
                        count[div2]++;
                        div[i].push_back(div2);
                    }
                }
            }
        }

        bool done = false;
        for (int i = 1; i <= m; ++i) {
            if (!count[i]) {
                done = true;
            }
        }

        if (done) {
            cout << -1 << endl;
        }
        else {
            ll l = 0, r = n-1;
            bool good = true;
            while (good) {
                for (auto i : div[l]) {
                    if (count[i] == 1) {
                        good = false;
                    }
                }

                if (!good) {
                    break;
                }
                else {
                    for (auto i : div[l]) {
                        count[i]--;
                    }
                    ++l;
                }
            }


            good = true;
            while (good) {
                for (auto i : div[r]) {
                    if (count[i] == 1) {
                        good = false;
                    }
                }
                if (!good) {
                    break;
                }
                else {
                    for (auto i : div[r]) {
                        count[i]--;
                    }
                    --r;
                }
            }


            ll res = a[r] - a[l];
            while (l >= 1) {
                --l;
                for (auto i : div[l]) {
                    count[i]++;
                }
                good = true;
                while (good) {
                    for (auto i : div[r]) {
                        if (count[i] == 1) {
                            good = false;
                        }
                    }
                    if (!good) {
                        break;
                    }
                    else {
                        for (auto i : div[r]) {
                            count[i]--;
                        }
                        --r;
                    }
                }

                res = min(res, a[r] - a[l]);
            }

            cout << res << endl;
        }




    }
}