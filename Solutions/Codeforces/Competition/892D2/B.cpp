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
        vector<vector<ll>> arrays;
        for (int i = 0; i < n; ++i) {
            ll m;
            cin >> m;
            vector<ll> a(m);
            for (int j = 0; j < m; ++j) {
                cin >> a[j];
            }

            sort(a.begin(), a.end());
            arrays.push_back(move(a));
        }

        vector<ll> second_smallest;
        ll smallest = arrays[0][0];

        for (int i = 0; i < n; ++i) {
            second_smallest.push_back(arrays[i][1]);
            smallest = min(smallest, arrays[i][0]);
        }

        sort(second_smallest.begin(), second_smallest.end());

        ll res = smallest;
        for (int i = 1; i < n; ++i) {
            res += second_smallest[i];
        }

        cout << res << endl;








    }
}