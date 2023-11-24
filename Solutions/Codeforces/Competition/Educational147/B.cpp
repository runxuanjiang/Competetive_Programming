//Competition #:
//Problem #: B
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
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        ll diff = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                diff = i;
                break;
            }
        }

        if (diff == -1) {
            ll res = 0;
            ll start = 1;
            ll end = 1;
            ll curres = 1;
            ll currstart = 1;
            for (int i = 1; i < n; ++i) {
                if (b[i] < b[i-1]) {
                    if (curres > res) {
                        res = curres;
                        start = currstart;
                        end = i;
                        
                    }
                    curres = 1;
                    currstart = i+1;
                }
                else {
                    ++curres;
                }
            }

            if (curres > res) {
                res = curres;
                start = currstart;
                end = n;
            }

            cout << start << " " << end << endl;
        }
        else {
            ll lidx = diff;
            ll ridx = diff;
            while (lidx > 0 && b[lidx-1] <= b[lidx]) {
                --lidx;
            }
            while (ridx+1 < n && b[ridx+1] >= b[ridx]) {
                ++ridx;
            }
            cout << lidx+1 << " " << ridx+1 << endl;
        }


    }
}