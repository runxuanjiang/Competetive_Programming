//Competition #:
//Problem #: C
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

        vector<bool> seen(n+1, false);

        vector<ll> res;
        for (int i = 1; i <= n; ++i) {
            if (!seen[i]) {
                seen[i] = true;

                res.push_back(i);
                ll j = i;
                while (j*2 <= n) {
                    j *= 2;
                    seen[j] = true;
                    res.push_back(j);
                }
            }
        }

        for (auto i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
}