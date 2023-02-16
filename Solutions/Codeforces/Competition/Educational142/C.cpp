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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<ll> locations(n);
        for (int i = 0; i < n; ++i) {
            locations[a[i] - 1] = i;
        }

        ll l = (n-1)/2, r = n/2;
        ll lbound = -1, rbound = -1;
        ll res = 0;
        ll done = false;

        while (l >= 0) {
            if (done) {
                ++res;
            }
            else {
                if (locations[l] > locations[r]) {
                    ++res;
                    done = true;
                }
                else {
                    if (lbound == -1 || (locations[l] < lbound && locations[r] > rbound)) {
                        lbound = locations[l];
                        rbound = locations[r];
                    }
                    else {
                        done = true;
                        ++res;
                    }
                }
            }

            --l;
            ++r;
        }

        cout << res << endl;


    }
}