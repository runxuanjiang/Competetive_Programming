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
        ll n, m;
        cin >> n >> m;
        vector<ll> t(n*m);
        for (auto &i : t) {
            cin >> i;
        }

        sort(t.begin(), t.end());

        ll max1 = t.back() - t.front();
        ll max2 = max(t[t.size() - 2] - t.front(), t.back() - t[1]);
        if (n > m) {
            swap(n, m);
        }

        cout << n * (m-1) * max1 + (n-1) * max2 << endl;
    }
}