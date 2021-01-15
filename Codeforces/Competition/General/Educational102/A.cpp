//Competition #:
//Problem #: A
//Accepted: Yes

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
        ll n, d;
        cin >> n >> d;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool sat = true;
        int s1=101, s2=101;

        for (auto i : a) {
            if (i > d) {
                sat = false;
            }
            if (i < s2) {
                s2 = i;
                if (s2 < s1) {
                    swap(s2, s1);
                }
            }
        }

        if (sat || s1 + s2 <= d) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }


    }
}