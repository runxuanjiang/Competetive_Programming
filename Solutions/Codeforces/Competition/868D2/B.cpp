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
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }


        unordered_map<ll, unordered_set<ll>> diff;

        bool swapped = false;
        bool good = true;

        for (int i = 0; i < n; ++i) {
            ll want = i+1;

            ll other = 0;
            if (want + k <= n) {
                other = want + k;
            }
            if (want - k >= 1) {
                other = want - k;
            }

            if (a[i] != want && a[i] != other) {
                if (swapped) {
                    good = false;
                    break;
                }
                else {
                    swapped = true;
                    for (auto &j : a) {
                        if (j == want) {
                            j = a[i];
                        }
                    }
                }
            }

            for (auto i : a) {
                cout << i << " ";
            }
            cout << endl;


        }

        if (good) {
            if (swapped) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        else {
            cout << -1 << endl;
        }
    }
}