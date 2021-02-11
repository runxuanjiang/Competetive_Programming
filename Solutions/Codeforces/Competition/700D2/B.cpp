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
        ll A, B, n;
        cin >> A >> B >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        ll totb = 0;

        for (int i = 0; i < n; ++i) {
            ll attacks = ceil((ld) b[i] / (ld) A);
            totb += attacks * a[i];
        }

        bool works = false;
        for (int i = 0; i < n; ++i) {
            if (totb - a[i] < B) {
                works = true;
                break;
            }
        }

        if (works) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }




    }
}