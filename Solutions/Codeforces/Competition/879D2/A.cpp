//Competition #:
//Problem #: A
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

        ll positives = 0, negatives = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) {
                ++positives;
            } else {
                ++negatives;
            }
        }

        ll res = 0;
        if (negatives > positives) {
            res = (negatives - positives + 1) / 2;
            negatives -= res;
            positives += res;
        }

        if (negatives % 2 == 1) {
            ++res;
        }

        cout << res << endl;


    }
}