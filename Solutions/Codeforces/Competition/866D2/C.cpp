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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        unordered_set<ll> seen;
        for (auto i : a) {
            seen.insert(i);
        }

        ll mex = 0;

        for (int i = 0; i <= n; ++i) {
            if (seen.find(i) == seen.end()) {
                mex = i;
                break;
            }
        }

        ++mex;

        ll lo = n+1, hi = -1;
        for (ll i = 0; i < n; ++i) {
            if (a[i] == mex) {
                lo = min(lo, i);
                hi = max(hi, i);
            }
        }


        if (hi >= 0) {
            for (int i = lo; i <= hi; ++i) {
                a[i] = mex-1;
            }

            seen = unordered_set<ll>();
            for (auto i : a) {
                seen.insert(i);
            }

            ll newmex = 0;
            for (int i = 0; i <= n; ++i) {
                if (seen.find(i) == seen.end()) {
                    newmex = i;
                    break;
                }
            }

            if (newmex == mex) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else {
            ll good = false;
            seen = unordered_set<ll>();
            for (auto i : a) {
                if (i > mex) {
                    good = true;
                }

                if (seen.find(i) != seen.end()) {
                    good = true;
                }

                seen.insert(i);
            }

            cout << (good ? "YES" : "NO") << endl;
        }
    }
}