//Competition #: Educational Codeforces Round 96 (1430B)
//Problem #: B
//Accepted: Yes 

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
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) {
            cin >>  v[i];
        }

        sort(v.begin(), v.end(), greater<ll>());
        if (k == 0) {
            cout << v.back() - v.front() << endl;
        }
        else {
            ll res = 0;

            for (int i = 0; i < k+1; ++i) {
                res += v[i];
            }

            cout << res << endl;
        }

    }
}