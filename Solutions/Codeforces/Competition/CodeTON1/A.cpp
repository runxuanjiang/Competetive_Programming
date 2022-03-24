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
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int mi = a[0], ma = a[0];
        int miidx = 0, maidx = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > ma) {
                ma = a[i];
                maidx = i;
            }
            if (a[i] < mi) {
                mi = a[i];
                miidx = i;
            }
        }

        cout << miidx + 1 << " " << maidx + 1 << endl;
    }
}