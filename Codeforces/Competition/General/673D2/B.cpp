//Competition #:
//Problem #:
//Accepted: 

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
const int MOD = 1000000007;

#define fast ios::sync_with_stdio(false); cin.tie(nullptr)
#define tests int testCount; cin >> testCount; while(testCount--)

int main() {
    fast;
    tests{
        ll n, t;
        cin >> n >> t;

        vector<ll> v(n);
        int r = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            if (t % 2 == 0 && t/2 == v[i]) ++r;
        }

        r/=2;

        for (auto i : v) {
            if (t%2 == 0 && i == t/2) {
                if (r > 0) {
                    cout << 0 << " ";
                    --r;
                }
                else cout << 1 << " ";
            }
            else {
                cout << (i <= t/2) << " ";
            }
        }
        cout << endl;

    }
}