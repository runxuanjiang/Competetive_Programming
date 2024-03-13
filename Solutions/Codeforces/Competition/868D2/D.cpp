//Competition #:
//Problem #: D
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

        vector<ll> x(k), c(k);
        for (int i = 0; i < k; ++i) {
            cin >> x[i];
        }

        for (int i = 0; i < k; ++i) {
            cin >> c[i];
        }


        string res;
        bool good = true;
        ll filler = 0;

        for (int i = 0; i < k; ++i) {
            char curr = 'd' + i;
            if (i == 0) {
                if (c[i] > x[i]) {
                    good = false;
                    break;
                }
                else {
                    ll rem = c[i] - 3;
                    for (int j = 0; j < x[i] - rem; ++j) {
                        res.push_back('a' + (filler % 3));
                        ++filler;
                    }
                    for (int j = 0; j < rem; ++j) {
                        res.push_back(curr);
                    }
                }
            }
            else {
                if (x[i] - x[i-1] < c[i] - c[i-1]) {
                    good = false;
                    break;
                }
                else {
                    ll rem = c[i] - c[i-1];
                    ll tot = x[i] - x[i-1];
                    for (int j = 0; j < tot - rem; ++j) {
                        res.push_back('a' + (filler % 3));
                        ++filler;
                    }
                    for (int j = 0; j < rem; ++j) {
                        res.push_back(curr);
                    }
                }
            }
        }

        if (!good) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            cout << res << endl;
        }




    }
}